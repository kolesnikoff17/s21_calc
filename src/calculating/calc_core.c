#include "calc_core.h"

STACK_DECLARE(double)

int is_binary(char a);
char* number_handler(char* polish, stack** head);
char* x_handler(char* polish, stack** head, double x);
void unary_handler(char a, stack* head);
void binary_handler(char a, stack** head, int* err);

double calc_res(char* polish, int* err, double x) {
  char* end;
  double res = strtod(polish, &end);
  if (end == polish && *polish != 'x') {
    *err = 1;
    return 0;
  }
  stack* head = NULL;
  if (*polish == 'x') {
    head = init(x);
  } else {
    head = init(res);
    polish = end;
  }
  for (; *polish && !(*err) && head;) {
    if (*polish == ' ') {
      ++polish;
      continue;
    }
    if (is_number(*polish))
      polish = number_handler(polish, &head);
    else if (*polish == 'x')
      polish = x_handler(polish, &head, x);
    else if (!is_binary(*polish))
      unary_handler(*polish++, head);
    else if (is_binary(*polish))
      binary_handler(*polish++, &head, err);
  }
  if (!head || head->next) *err = 1;
  if (!(*err)) res = head->value;
  destroy(head);
  return res;
}

int is_binary(char a) {
  int res = 0;
  if (a == '*' || a == '+' || a == '-' || a == '^' || a == 'm' || a == '/')
    res = 1;
  return res;
}

char* number_handler(char* polish, stack** head) {
  char* end;
  *head = push(*head, strtod(polish, &end));
  return end;
}

char* x_handler(char* polish, stack** head, double x) {
  *head = push(*head, x);
  return ++polish;
}

void unary_handler(char a, stack* head) {
  if (a == 's')
    head->value = sin(head->value);
  else if (a == 'c')
    head->value = cos(head->value);
  else if (a == 't')
    head->value = tan(head->value);
  else if (a == 'a')
    head->value = acos(head->value);
  else if (a == 'o')
    head->value = acos(head->value);
  else if (a == 'i')
    head->value = asin(head->value);
  else if (a == 'l')
    head->value = log(head->value);
  else if (a == 'g')
    head->value = log10(head->value);
  else if (a == 'k')
    head->value = sqrt(head->value);
  else if (a == 'u')
    head->value = -head->value;
}

void binary_handler(char a, stack** head, int* err) {
  if (!(*head)->next)
    *err = 1;
  else {
    double tmp = pop(head);
    if (a == '+')
      (*head)->value = (*head)->value + tmp;
    else if (a == '-')
      (*head)->value = (*head)->value - tmp;
    else if (a == '/')
      (*head)->value = (*head)->value / tmp;
    else if (a == '*')
      (*head)->value = (*head)->value * tmp;
    else if (a == '^')
      (*head)->value = pow((*head)->value, tmp);
    else if (a == 'm')
      (*head)->value = fmod((*head)->value, tmp);
  }
}
