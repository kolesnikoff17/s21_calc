#include "common.h"

int is_number(char a) {
  int res = 0;
  if (a >= '0' && a <= '9') res = 1;
  return res;
}
