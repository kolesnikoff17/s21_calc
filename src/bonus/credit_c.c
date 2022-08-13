#include <math.h>

#include "../calc_c.h"

cr_res credit_res(double sum, int time, double perc, int mode) {
  cr_res res = {0};
  double i = perc / 12 / 100;
  if (!mode) {
    double k = i / (1 - pow(1 + i, -time));
    res.total = round(k * sum * time);
    res.monthly = round(k * sum);
    res.over = round(sum * (k * time - 1));
  } else {
    double main = sum / time;
    res.monthly = round(main + sum * i);
    res.monthly2 = round(main + main * i);
    res.over = round(i * sum * (time + 1) / 2.);
    res.total = round(res.over + sum);
  }
  return res;
}