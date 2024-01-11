#include <check.h>

#include "s21_SmartCalc.h"

START_TEST(calc_test_1) {
  char str[20] = "-2.^(2+.0*(2.)*.2)=";
  double solve = 0.0;
  calculation(str, &solve);
  ck_assert_double_eq(solve, -4);
}
END_TEST

START_TEST(calc_test_2) {
  char *str =
      "(-sin(0.5)+cos(0.5)+tan(0.5)+atan(0.5)+acos(0.5)+asin(0.5)*5)/"
      "0.3^2+sqrt(9)-7%3-5+ln(3)-log(2)=";
  double solve = 0.0;
  calculation(str, &solve);
  ck_assert_double_eq_tol(solve, 54.1675661, 1e-7);
  // ck_assert_double_eq_tol(solve, solve, 1e-6);
}
END_TEST

START_TEST(calc_test_3) {
  char *str = "2^3^2=";
  double solve = 0.0;
  calculation(str, &solve);
  ck_assert_double_eq(solve, 512);
}
END_TEST

START_TEST(calc_test_4) {
  char str[15] = "(1+2))=";
  double solve = 0.0;
  int error_code = calculation(str, &solve);
  ck_assert_int_eq(error_code, 1);
}
END_TEST

START_TEST(calc_test_5) {
  char *str = "ssin(15)=";
  double solve = 0.0;
  int error_code = calculation(str, &solve);
  ck_assert_double_eq(solve, 0.0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST

START_TEST(calc_test_6) {
  char *str = "2*/3=";
  double solve = 0.0;
  int error_code = calculation(str, &solve);
  ck_assert_double_eq(solve, 0.0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST

START_TEST(calc_test_7) {
  char *str = "2+3+x=";
  int lexems_count = 0;
  Token_total line[255] = {};
  s21_inflix_to_struct(str, line, &lexems_count);
  double solve = 0.0;
  solve = s21_calculation_graph(line, lexems_count, 7);
  ck_assert_double_eq(solve, 12.0);
}
END_TEST

START_TEST(s21_smart) {
  double res = 0;
  res = 0;
  char *af_str = "-0.456+4*2*(456+3.567)=";
  calculation(af_str, &res);
  ck_assert_float_eq_tol(res, 3676.08, 1e-7);
  double res2 = 0;
  res2 = 0;
  char *af_str2 = "-0.456+4*2*sin(45)/2*(4+8)-ln(45)=";
  calculation(af_str2, &res2);
  // ck_assert_double_eq(res2, res2);
  ck_assert_float_eq_tol(res2, 36.5807066, 1e-7);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_2);
  tcase_add_test(tc1_1, calc_test_3);
  tcase_add_test(tc1_1, calc_test_4);
  tcase_add_test(tc1_1, calc_test_5);
  tcase_add_test(tc1_1, calc_test_6);
  tcase_add_test(tc1_1, calc_test_7);
  tcase_add_test(tc1_1, s21_smart);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}