#ifndef SRC_PARSING_H
#define SRC_PARSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "stack.h"

STACK_DECLARE(char)

int is_short_operator(char a);
char is_long_operator(char* a);
char* number_handler_parse(char* input, char** res, int* len);
char* x_handler_parse(char* input, char** res, int* len);
char* short_operator_handler(char* input, char** res, int* len, int* err,
                             stack** head);
int long_operator_handler(char op, char** res, int* len, int* err,
                          stack** head);
void from_stack_to_queue(char** res, int* len, stack** head, int* err);
int unary_handler_parse(char* input, int len);
int precedence_check(char a, char b);
int precedence_list(char a);
int left_check(char a);
char space_trim(char* a);

#endif  // SRC_PARSING_H
