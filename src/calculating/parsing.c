#include "parsing.h"

STACK_DECLARE(char)

int is_short_operator(char a);
char is_long_operator(char* a);
char* number_handler(char* input, char** res, int* len);
char* x_handler(char* input, char** res, int* len);
char* short_operator_handler(char* input, char** res, int* len, int* err,
                             stack** head);
int long_operator_handler(char op, char** res, int* len, int* err,
                          stack** head);
void from_stack_to_queue(char** res, int* len, stack** head);
int unary_handler(char* input, int len);
int precedence_check(char a, char b);
int precedence_list(char a);

char* parsing(char* input, int* err) {
  int len = 1;
  char* res = calloc(len, sizeof(char));
  if (!res) exit(0);
  stack* head = init(' ');
  for (; *input && !(*err);) {
    printf("%s\n", res);
    if (is_number(*input))
      input = number_handler(input, &res, &len);
    else if (*input == 'x' || *input == 'X')
      input = x_handler(input, &res, &len);
    else if (is_short_operator(*input))
      input = short_operator_handler(input, &res, &len, err, &head);
    else if (is_long_operator(input))
      // TODO fix this ugly part somehow
      input += long_operator_handler(is_long_operator(input), &res, &len, err,
                                     &head);
    else
      *err = 1;
  }
  while (!(*err) && head->value != ' ') from_stack_to_queue(&res, &len, &head);
  destroy(head);
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

char* number_handler(char* input, char** res, int* len) {
  char* end;
  strtod(input, &end);
  *len += end - input + 1;
  *res = realloc(*res, *len * sizeof(char));
  if (!(*res)) exit(0);
  char* curr = *res + *len - (end - input + 1);
  sprintf(curr, "%.*s ", end - input, input);
  return end;
}

char* x_handler(char* input, char** res, int* len) {
  *len += 2;
  *res = realloc(*res, *len * sizeof(char));
  if (!(*res)) exit(0);
  char* curr = *res + *len - 2;
  sprintf(curr, "x ");
  return ++input;
}

char* short_operator_handler(char* input, char** res, int* len, int* err,
                             stack** head) {
  char in_stack = *input;
  if (in_stack == '+') in_stack = unary_handler(input, *len) ? 'p' : '+';
  if (in_stack == '-') in_stack = unary_handler(input, *len) ? 'u' : '-';
  if (in_stack == ')') {
    while ((*head)->value != '(' && (*head)->value != ' ') {
      from_stack_to_queue(res, len, head);
    }
    if ((*head)->value == ' ')
      *err = 1;
    else
      pop(head);
  } else {
    while (precedence_check((*head)->value, in_stack)) {
      from_stack_to_queue(res, len, head);
    }
    *head = push(*head, in_stack);
  }
  return ++input;
}

int long_operator_handler(char op, char** res, int* len, int* err,
                          stack** head) {
  int op_len = 3;
  if (op == 'a' || op == 'o' || op == 'k' || op == 'i')
    op_len = 4;
  else if (op == 'l')
    op_len == 2;
  while (precedence_check((*head)->value, op)) {
    from_stack_to_queue(res, len, head);
  }
  *head = push(*head, op);
  return op_len;
}

void from_stack_to_queue(char** res, int* len, stack** head) {
  *len += 2;
  *res = realloc(*res, *len * sizeof(char));
  if (!(*res)) exit(0);
  char* curr = *res + *len - 2;
  sprintf(curr, "%c ", pop(head));
}

int unary_handler(char* input, int len) {
  int res = 0;
  // TODO space handlers case : (  -3)
  if (len == 1 || *(input - 1) == '(') res = 1;
  return res;
}

int precedence_check(char a, char b) {
  int res = 0;
  if (precedence_list(a) >= precedence_list(b)) res = 1;
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
