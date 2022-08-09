#include <check.h>

#include "../calc_c.h"

START_TEST(test_1) {
  int err = 0;
  char *out = parsing("3 - sin (  3)", &err);
  ck_assert_str_eq(out, "3 3 s - ");
}
END_TEST

START_TEST(test_2) {
  int err = 0;
  char *out = parsing("4 + 2 * 9 / 8", &err);
  ck_assert_str_eq(out, "4 2 9 * 8 / + ");
}
END_TEST

START_TEST(test_3) {
  int err = 0;
  char *out = parsing("tan(-log(-3)) + 3 / 8 ", &err);
  ck_assert_str_eq(out, "3 u g u t 3 8 / + ");
}
END_TEST

START_TEST(test_4) {
  int err = 0;
  char *out = parsing("3^2^4", &err);
  ck_assert_str_eq(out, "3 2 4 ^ ^ ");
}
END_TEST

START_TEST(test_5) {
  int err = 0;
  char *out = parsing("(3 + sin(3) - 8)", &err);
  ck_assert_str_eq(out, "3 3 s + 8 - ");
}
END_TEST

START_TEST(neg_1) {
  int err = 0;
  char *out = parsing("(3 + sin(3) - 8", &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(neg_2) {
  int err = 0;
  char *out = parsing("((((((", &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(neg_3) {
  int err = 0;
  char *out = parsing("())", &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);

  tcase_add_test(tc1_1, neg_1);
  tcase_add_test(tc1_1, neg_2);
  tcase_add_test(tc1_1, neg_3);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
