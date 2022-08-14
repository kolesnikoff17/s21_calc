#include "calc_core.h"

#include "../calc_c.h"

double calc_res(char* polish, int* err, double x) {
  char* end;
  double res = strtod(polish, &end);
  if (end == polish && *polish != 'x') {
    // printf("%s\n", polish);
    *err = 1;
    // printf("aboba\n");
    return 0;
  }
  stack* head = NULL;
  if (*polish == 'x') {
    head = init_double(x);
    ++polish;
  } else {
    head = init_double(res);
    polish = end;
  }
  // printf("%lf %d\n", res, *err);
  // printf("%lf\n", head->value);
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
  if (head) destroy_double(head);
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
  *head = push_double(*head, strtod(polish, &end));
  return end;
}

char* x_handler(char* polish, stack** head, double x) {
  *head = push_double(*head, x);
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
  if (!(*head)->next) {
    *err = 1;
  } else {
    double tmp = pop_double(head);
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
