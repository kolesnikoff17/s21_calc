#include <check.h>

#include "../calc_c.h"

START_TEST(parse_test_1) {
  int err = 0;
  char *out = parsing("3 - sin (  -3)", &err);
  ck_assert_str_eq(out, "3 3 u s - ");
}
END_TEST

START_TEST(parse_test_2) {
  int err = 0;
  char *out = parsing("56-3", &err);
  ck_assert_str_eq(out, "56 3 - ");
}
END_TEST

START_TEST(parse_test_3) {
  int err = 0;
  char *out = parsing("tan(  -log(-3)) + 3 / 8 ", &err);
  ck_assert_str_eq(out, "3 u g u t 3 8 / + ");
}
END_TEST

START_TEST(parse_test_4) {
  int err = 0;
  char *out = parsing("3^2^4", &err);
  ck_assert_str_eq(out, "3 2 4 ^ ^ ");
}
END_TEST

START_TEST(parse_test_5) {
  int err = 0;
  char *out = parsing("(3 + sin(3) - 8)", &err);
  ck_assert_str_eq(out, "3 3 s + 8 - ");
}
END_TEST

START_TEST(parse_test_6) {
  int err = 0;
  char *out = parsing("(X + sin(x) - 8)", &err);
  ck_assert_str_eq(out, "x x s + 8 - ");
}
END_TEST

START_TEST(parse_test_7) {
  int err = 0;
  char *out = parsing("ln(-1) ", &err);
  ck_assert_str_eq(out, "1 u l ");
}
END_TEST

START_TEST(parse_neg_1) {
  int err = 0;
  char *out = parsing("(3 + sin(3) - 8", &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(parse_neg_2) {
  int err = 0;
  char *out = parsing("((((((", &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(parse_neg_3) {
  int err = 0;
  char *out = parsing("())", &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(parse_neg_4) {
  int err = 0;
  char *out = parsing("aboba", &err);
  ck_assert_int_eq(err, 1);
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
  double out = calc_res(parsing("2^3^4", &err), &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, pow(2, pow(3, 4)), 1e-7);
  else
    ck_assert_double_nan(pow(2, pow(3, 4)));
}
END_TEST

START_TEST(calc_test_3) {
  int err = 0;
  double out = calc_res(parsing("(3 + 3) - 7 * 8", &err), &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, 3 + 3 - 7 * 8, 1e-7);
  else
    ck_assert_double_nan(3 + 3 - 7 * 8);
}
END_TEST

START_TEST(calc_test_4) {
  int err = 0;
  double out = calc_res(parsing("tan(-log(-3)) + 3 / 8 ", &err), &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, tan(-log10(-3)) + 3 / 8, 1e-7);
  else
    ck_assert_double_nan(tan(-log10(-3)) + 3 / 8);
}
END_TEST

START_TEST(calc_test_5) {
  int err = 0;
  double out = calc_res(parsing("56-3", &err), &err, 0);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, 56 - 3, 1e-7);
  else
    ck_assert_double_nan(56 - 3);
}
END_TEST

START_TEST(calc_test_6) {
  int err = 0;
  double out = calc_res(parsing("ln(x)", &err), &err, 4);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, log(4), 1e-7);
  else
    ck_assert_double_nan(log(4));
}
END_TEST

START_TEST(calc_test_7) {
  int err = 0;
  double out = calc_res(parsing("ln(x) - 4 mod x", &err), &err, -2.32);
  if (!isnan(out))
    ck_assert_double_eq_tol(out, log(-2.32) - fmod(4, -2.32), 1e-7);
  else
    ck_assert_double_nan(log(-2.32) - fmod(4, -2.32));
}
END_TEST

START_TEST(calc_neg_1) {
  int err = 0;
  double out = calc_res(parsing("ln(-1", &err), &err, 0);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(calc_neg_2) {
  int err = 0;
  double out = calc_res(parsing("ln(-+-+/1)", &err), &err, 0);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(calc_neg_3) {
  int err = 0;
  double out = calc_res(parsing("3+ 2 -", &err), &err, 0);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(calc_neg_4) {
  int err = 0;
  double out = calc_res(parsing("3 +", &err), &err, 0);
  ck_assert_int_eq(err, 1);
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

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
