#include "s21_matrix_test.h"

START_TEST(rows_0) {
  matrix_t result = {0};
  int check = s21_create_matrix(0, 5, &result);
  ck_assert_int_eq(check, 1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(colums_0) {
  matrix_t result = {0};
  int check = s21_create_matrix(5, 0, &result);
  ck_assert_int_eq(check, 1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_1) {
  matrix_t m = {0};
  s21_create_matrix(3, 2, &m);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-07);
    }
  }
  ck_assert_int_eq(m.rows, 3);
  ck_assert_int_eq(m.columns, 2);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_2) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), 1);
}
END_TEST

START_TEST(create_3) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), 1);
}
END_TEST

Suite* s21_create_matrix_suite(void) {
  Suite* s = suite_create("suite_create_matrix");
  TCase* tc = tcase_create("case_create_matrix");
  tcase_add_test(tc, rows_0);
  tcase_add_test(tc, colums_0);
  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);

  suite_add_tcase(s, tc);
  return s;
}
