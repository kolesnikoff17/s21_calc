#include "parsing.h"

#include "../calc_c.h"

STACK_FUNC_INIT(char);

char* parsing(char* input, int* err) {
  int len = 1;
  char* res = calloc(len, sizeof(char));
  if (!res) exit(0);
  stack* head = init_char(' ');
  char long_op_spec = 0;
  int num_check = 0;
  int long_is_last = 0;
  for (; *input && !(*err);) {
    if (is_number(*input)) {
      input = number_handler_parse(input, &res, &len);
      num_check++;
      long_is_last = 0;
    } else if (*input == 'x' || *input == 'X') {
      input = x_handler_parse(input, &res, &len);
      num_check++;
      long_is_last = 0;
    } else if (is_short_operator(*input)) {
      input = short_operator_handler(input, &res, &len, err, &head);
      num_check = 0;
      long_is_last = 0;
    } else if ((long_op_spec = is_long_operator(input))) {
      input += long_operator_handler(long_op_spec, &res, &len, err, &head);
      num_check = 0;
      long_is_last = 1;
    } else if (*input == ' ') {
      ++input;
    } else {
      *err = 1;
    }
    if (num_check > 1) *err = 1;
  }
  if (long_is_last) *err = 1;
  while (!(*err) && head->value != ' ')
    from_stack_to_queue(&res, &len, &head, err);
  destroy_char(head);
  return res;
}

int is_short_operator(char a) {
  int res = 0;
  if (a == '(' || a == ')' || a == '+' || a == '-' || a == '/' || a == '*' ||
      a == '^')
    res = 1;
  return res;
}

char is_long_operator(char* a) {
  char res = 0;
  if (!strncmp(a, "sin", 3))
    res = 's';
  else if (!strncmp(a, "cos", 3))
    res = 'c';
  else if (!strncmp(a, "tan", 3))
    res = 't';
  else if (!strncmp(a, "atan", 4))
    res = 'a';
  else if (!strncmp(a, "acos", 4))
    res = 'o';
  else if (!strncmp(a, "asin", 4))
    res = 'i';
  else if (!strncmp(a, "sqrt", 4))
    res = 'k';
  else if (!strncmp(a, "ln", 2))
    res = 'l';
  else if (!strncmp(a, "log", 3))
    res = 'g';
  else if (!strncmp(a, "mod", 3))
    res = 'm';
  return res;
}

char* number_handler_parse(char* input, char** res, int* len) {
  char* end;
  strtod(input, &end);
  *len += end - input + 1;
  *res = realloc(*res, *len * sizeof(char));
  if (!(*res)) exit(0);
  char* curr = *res + *len - (end - input + 2);
  snprintf(curr, (int)(end - input + 2), "%.*s ", (int)(end - input), input);
  return end;
}

char* x_handler_parse(char* input, char** res, int* len) {
  *len += 2;
  *res = realloc(*res, *len * sizeof(char));
  if (!(*res)) exit(0);
  char* curr = *res + *len - 3;
  snprintf(curr, 3 * sizeof(char), "x ");
  return ++input;
}

char* short_operator_handler(char* input, char** res, int* len, int* err,
                             stack** head) {
  char in_stack = *input;
  if (in_stack == '+') in_stack = unary_handler_parse(input, *len) ? 'p' : '+';
  if (in_stack == '-') in_stack = unary_handler_parse(input, *len) ? 'u' : '-';
  // printf("%c\n", in_stack);
  if (in_stack == ')') {
    while ((*head)->value != '(' && (*head)->value != ' ') {
      // printf("%s %c\n", *res, (*head)->value);
      from_stack_to_queue(res, len, head, err);
    }
    if ((*head)->value == ' ')
      *err = 1;
    else
      pop_char(head);
  } else {
    while (precedence_check((*head)->value, in_stack)) {
      from_stack_to_queue(res, len, head, err);
    }
    *head = push_char(*head, in_stack);
  }
  return ++input;
}

int long_operator_handler(char op, char** res, int* len, int* err,
                          stack** head) {
  int op_len = 3;
  if (op == 'a' || op == 'o' || op == 'k' || op == 'i')
    op_len = 4;
  else if (op == 'l')
    op_len = 2;
  while (precedence_check((*head)->value, op)) {
    from_stack_to_queue(res, len, head, err);
  }
  *head = push_char(*head, op);
  return op_len;
}

void from_stack_to_queue(char** res, int* len, stack** head, int* err) {
  char out = 0;
  *len += 2;
  *res = realloc(*res, *len * sizeof(char));
  if (!(*res)) exit(0);
  // printf("%c\n", (*head)->value);
  if (!(*head) || (*head)->value == ' ' || (*head)->value == '(')
    *err = 1;
  else
    out = pop_char(head);
  char* curr = *res + *len - 3;
  snprintf(curr, 3 * sizeof(char), "%c ", out);
}

int unary_handler_parse(char* input, int len) {
  int res = 0;
  if (len == 1 || space_trim(--input) == '(') res = 1;
  return res;
}

int precedence_check(char a, char b) {
  int res = 0;
  if ((precedence_list(a) > precedence_list(b) && a != '(') ||
      (precedence_list(a) == precedence_list(b) && left_check(b)))
    res = 1;
  return res;
}

int precedence_list(char a) {
  int res = 0;
  switch (a) {
    case '(':
      res = 4;
      break;
    case 's':
    case 'c':
    case 't':
    case 'o':
    case 'i':
    case 'a':
    case 'l':
    case 'g':
    case 'k':
    case '^':
    case 'u':
    case 'p':
      res = 3;
      break;
    case '*':
    case '/':
    case 'm':
      res = 2;
      break;
    case '+':
    case '-':
      res = 1;
      break;
  }
  return res;
}

int left_check(char a) {
  int res = 0;
  if (a == '*' || a == '/' || a == 'm' || a == '+' || a == '-') res = 1;
  return res;
}

char space_trim(char* a) {
  while (*a == ' ') {
    --a;
  }
  return *a;
}
