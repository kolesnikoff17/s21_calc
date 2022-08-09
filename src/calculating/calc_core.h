#ifndef SRC_CALC_CORE_H
#define SRC_CALC_CORE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "stack.h"

STACK_DECLARE(double)

int is_binary(char a);
char* number_handler(char* polish, stack** head);
char* x_handler(char* polish, stack** head, double x);
void unary_handler(char a, stack* head);
void binary_handler(char a, stack** head, int* err);

#endif  // SRC_CALC_CORE_H
