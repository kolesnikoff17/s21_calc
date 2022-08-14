#include <math.h>

#include "../calc_c.h"

dep_res deposit_res(double sum, int time, double perc, double tax, int reinvest,
                    int payout_time, int add_time, double add, int dec_time,
                    double dec) {
  dep_res res = {0};
  double tmp_sum = sum;
  double inc = 0, tax_sum = 0;
  double k = perc / 12 / 100 * payout_time;
  for (int i = 1; i < time + 1 && !res.err; ++i) {
    if (reinvest) {
      if (!(i % payout_time)) {
        inc += tmp_sum * k * (1 - tax);
        tax_sum += tmp_sum * k * tax;
        tmp_sum += tmp_sum * k * (1 - tax);
      }
      if (add_time && !(i % add_time)) tmp_sum += add;
      if (dec_time && !(i % dec_time)) tmp_sum -= dec;
    } else {
      if (!(i % payout_time)) {
        // printf("%lf\n", inc);
        inc += tmp_sum * k * (1 - tax);
        tax_sum += tmp_sum * k * tax;
      }
      if (add_time && !(i % add_time)) tmp_sum += add;
      if (dec_time && !(i % dec_time)) tmp_sum -= dec;
    }
    if (tmp_sum < 0) res.err = 1;
  }
  res.income = round(inc);
  res.total = round(tmp_sum);
  res.tax = round(tax_sum);
  return res;
}
