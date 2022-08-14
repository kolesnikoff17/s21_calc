#ifndef SRC_CALC_C_H_
#define SRC_CALC_C_H_

typedef struct credit_response {
  long monthly;
  long monthly2;
  long over;
  long total;
} cr_res;

typedef struct deposit_response {
  long income;
  long tax;
  long total;
  int err;
} dep_res;

dep_res deposit_res(double sum, int time, double perc, double tax, int reinvest,
                    int payout_time, int add_time, double add, int dec_time,
                    double dec);
cr_res credit_res(double sum, int time, double perc, int mode);
char* parsing(char* input, int* err);
double calc_res(char* polish, int* err, double x);

#endif  // SRC_CALC_C_H_
