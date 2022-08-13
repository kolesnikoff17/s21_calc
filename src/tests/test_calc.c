#include <check.h>
#include <stdlib.h>

#include "../calc_c.h"

START_TEST(parse_test_1) {
  int err = 0;
  char *out = parsing("3 - sin (  -3)", &err);
  ck_assert_str_eq(out, "3 3 u s - ");
  free(out);
}
END_TEST

START_TEST(parse_test_2) {
  int err = 0;
  char *out = parsing("56-3", &err);
  ck_assert_str_eq(out, "56 3 - ");
  free(out);
}
END_TEST

START_TEST(parse_test_3) {
  int err = 0;
  char *out = parsing("tan(  -log(-3)) + 3 / 8 ", &err);
  ck_assert_str_eq(out, "3 u g u t 3 8 / + ");
  free(out);
}
END_TEST

START_TEST(parse_test_4) {
  int err = 0;
  char *out = parsing("3^2^4", &err);
  ck_assert_str_eq(out, "3 2 4 ^ ^ ");
  free(out);
}
END_TEST

START_TEST(parse_test_5) {
  int err = 0;
  char *out = parsing("(3 + sin(3) - 8)", &err);
  ck_assert_str_eq(out, "3 3 s + 8 - ");
  free(out);
}
END_TEST

START_TEST(parse_test_6) {
  int err = 0;
  char *out = parsing("(X + sin(x) - 8)", &err);
  ck_assert_str_eq(out, "x x s + 8 - ");
  free(out);
}
END_TEST

START_TEST(parse_test_7) {
  int err = 0;
  char *out = parsing("ln(-1) ", &err);
  ck_assert_str_eq(out, "1 u l ");
  free(out);
}
END_TEST

START_TEST(parse_neg_1) {
  int err = 0;
  char *out = parsing("(3 + sin(3) - 8", &err);
  ck_assert_int_eq(err, 1);
  free(out);
}
END_TEST

START_TEST(parse_neg_2) {
  int err = 0;
  char *out = parsing("((((((", &err);
  ck_assert_int_eq(err, 1);
  free(out);
}
END_TEST

START_TEST(parse_neg_3) {
  int err = 0;
  char *out = parsing("())", &err);
  ck_assert_int_eq(err, 1);
  free(out);
}
END_TEST

START_TEST(parse_neg_4) {
  int err = 0;
  char *out = parsing("aboba", &err);
  ck_assert_int_eq(err, 1);
  free(out);
}
END_TEST

START_TEST(calc_test_1) {
  int err = 0;
  double out = calc_res("3 s ", &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, sin(3), 1e-7);
  else
    ck_assert_double_nan(sin(3));
}
END_TEST

START_TEST(calc_test_2) {
  int err = 0;
  char *a = parsing("2^3^4", &err);
  double out = calc_res(a, &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, pow(2, pow(3, 4)), 1e-7);
  else
    ck_assert_double_nan(pow(2, pow(3, 4)));
  free(a);
}
END_TEST

START_TEST(calc_test_3) {
  int err = 0;
  char *a = parsing("(3 + 3) - 7 * 8", &err);
  double out = calc_res(a, &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, 3 + 3 - 7 * 8, 1e-7);
  else
    ck_assert_double_nan(3 + 3 - 7 * 8);
  free(a);
}
END_TEST

START_TEST(calc_test_4) {
  int err = 0;
  char *a = parsing("tan(-log(-3)) + 3 / 8 ", &err);
  double out = calc_res(a, &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, tan(-log10(-3)) + 3 / 8, 1e-7);
  else
    ck_assert_double_nan(tan(-log10(-3)) + 3 / 8);
  free(a);
}
END_TEST

START_TEST(calc_test_5) {
  int err = 0;
  char *a = parsing("56-3", &err);
  double out = calc_res(a, &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, 56 - 3, 1e-7);
  else
    ck_assert_double_nan(56 - 3);
  free(a);
}
END_TEST

START_TEST(calc_test_6) {
  int err = 0;
  char *a = parsing("ln(x)", &err);
  double out = calc_res(a, &err, 4);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, log(4), 1e-7);
  else
    ck_assert_double_nan(log(4));
  free(a);
}
END_TEST

START_TEST(calc_test_7) {
  int err = 0;
  char *a = parsing("ln(x) - 4 mod x", &err);
  double out = calc_res(a, &err, -2.32);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, log(-2.32) - fmod(4, -2.32), 1e-7);
  else
    ck_assert_double_nan(log(-2.32) - fmod(4, -2.32));
  free(a);
}
END_TEST

START_TEST(calc_neg_1) {
  int err = 0;
  char *a = parsing("ln(-1", &err);
  double out = calc_res(a, &err, 0);
  ck_assert_int_eq(err, 1);
  free(a);
}
END_TEST

START_TEST(calc_neg_2) {
  int err = 0;
  char *a = parsing("ln(-+-+/1)", &err);
  double out = calc_res(a, &err, 0);
  ck_assert_int_eq(err, 1);
  free(a);
}
END_TEST

START_TEST(calc_neg_3) {
  int err = 0;
  char *a = parsing("3+ 2 -", &err);
  double out = calc_res(a, &err, 0);
  ck_assert_int_eq(err, 1);
  free(a);
}
END_TEST

START_TEST(calc_neg_4) {
  int err = 0;
  char *a = parsing("3 +", &err);
  double out = calc_res(a, &err, 0);
  ck_assert_int_eq(err, 1);
  free(a);
}
END_TEST

START_TEST(credit_test) {
  cr_res a = credit_res(10000, 12, 3, 0);
  cr_res d = credit_res(10000, 12, 3, 1);
  ck_assert_int_eq(a.total, 10163);
  ck_assert_int_eq(a.over, 163);
  ck_assert_int_eq(a.monthly, 847);
  ck_assert_int_eq(d.monthly, 858);
  ck_assert_int_eq(d.monthly2, 835);
  ck_assert_int_eq(d.over, 163);
  ck_assert_int_eq(d.total, 10163);
}
END_TEST

START_TEST(deposit_test) {
  dep_res r = deposit_res(100000, 12, 5, 0, 0, 1, 0, 0, 0, 0);
  ck_assert_int_eq(r.income, 5000);
  ck_assert_int_eq(r.tax, 0);
  ck_assert_int_eq(r.total, 100000);
  dep_res nr = deposit_res(100000, 12, 5, 0, 1, 1, 0, 0, 0, 0);
  ck_assert_int_eq(nr.income, 5116);
  ck_assert_int_eq(nr.tax, 0);
  ck_assert_int_eq(nr.total, 105116);
  dep_res wa = deposit_res(100000, 12, 5, 0, 1, 1, 1, 100, 0, 0);
  ck_assert_int_eq(wa.income, 5144);
  ck_assert_int_eq(wa.tax, 0);
  ck_assert_int_eq(wa.total, 106344);
  dep_res wa2 = deposit_res(100000, 12, 5, 0, 1, 1, 2, 100, 0, 0);
  ck_assert_int_eq(wa2.income, 5129);
  ck_assert_int_eq(wa2.tax, 0);
  ck_assert_int_eq(wa2.total, 105729);
  dep_res wd = deposit_res(100000, 12, 5, 0, 1, 1, 0, 0, 1, 300);
  ck_assert_int_eq(wd.income, 5033);
  ck_assert_int_eq(wd.tax, 0);
  ck_assert_int_eq(wd.total, 101433);
  dep_res we = deposit_res(100000, 12, 5, 0, 1, 1, 0, 0, 1, 4444444);
  ck_assert_int_eq(we.err, 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, parse_test_1);
  tcase_add_test(tc1_1, parse_test_2);
  tcase_add_test(tc1_1, parse_test_3);
  tcase_add_test(tc1_1, parse_test_4);
  tcase_add_test(tc1_1, parse_test_5);
  tcase_add_test(tc1_1, parse_test_6);
  tcase_add_test(tc1_1, parse_test_7);

  tcase_add_test(tc1_1, parse_neg_1);
  tcase_add_test(tc1_1, parse_neg_2);
  tcase_add_test(tc1_1, parse_neg_3);
  tcase_add_test(tc1_1, parse_neg_4);

  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_2);
  tcase_add_test(tc1_1, calc_test_3);
  tcase_add_test(tc1_1, calc_test_4);
  tcase_add_test(tc1_1, calc_test_5);
  tcase_add_test(tc1_1, calc_test_6);
  tcase_add_test(tc1_1, calc_test_7);

  tcase_add_test(tc1_1, calc_neg_1);
  tcase_add_test(tc1_1, calc_neg_2);
  tcase_add_test(tc1_1, calc_neg_3);
  tcase_add_test(tc1_1, calc_neg_4);

  tcase_add_test(tc1_1, credit_test);
  tcase_add_test(tc1_1, deposit_test);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
