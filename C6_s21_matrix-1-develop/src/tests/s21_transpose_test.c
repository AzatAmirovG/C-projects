#include "s21_matrix_test.h"

START_TEST(s21_transpose_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, ERROR_INIT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_init_matrix(1.0, &A);
  res = s21_transpose(&A, &B);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t T = {0};
  matrix_t B = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;

  res = s21_transpose(&A, &T);
  res = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&B);
}
END_TEST

Suite* s21_transpose_suite(void) {
  Suite* s = suite_create("suite_transpose");
  TCase* tc = tcase_create("case_transpose");
  tcase_add_test(tc, s21_transpose_01);
  tcase_add_test(tc, s21_transpose_02);
  tcase_add_test(tc, s21_transpose_03);

  suite_add_tcase(s, tc);
  return s;
}
