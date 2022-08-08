#ifndef SRC_CALC_CORE_H
#define SRC_CALC_CORE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "stack.h"

double calc_res(char* polish, int* err, double x);

#endif  // SRC_CALC_CORE_H
