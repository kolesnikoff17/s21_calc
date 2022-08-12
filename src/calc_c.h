#ifndef SRC_CALC_C_H
#define SRC_CALC_C_H

typedef struct credit_response {
  long monthly;
  long monthly2;
  long over;
  long total;
} cr_res;

cr_res credit_res(double sum, int time, double perc, int mode);
char* parsing(char* input, int* err);
double calc_res(char* polish, int* err, double x);

#endif  // SRC_CALC_C_H
