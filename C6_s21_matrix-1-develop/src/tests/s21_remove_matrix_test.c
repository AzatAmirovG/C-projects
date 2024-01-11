#include "s21_matrix_test.h"

START_TEST(two_for_two) {
  matrix_t result;
  s21_create_matrix(2, 2, &result);
  s21_remove_matrix(&result);
  ck_assert_int_eq(result.columns, 0);
  ck_assert_int_eq(result.rows, 0);
  ck_assert_ptr_null(result.matrix);
}
END_TEST

START_TEST(three_for_three) {
  matrix_t result;
  s21_create_matrix(3, 3, &result);
  s21_remove_matrix(&result);
  ck_assert_int_eq(result.columns, 0);
  ck_assert_int_eq(result.rows, 0);
  ck_assert_ptr_null(result.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERROR_INIT;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_02) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERROR_INIT;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_03) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERROR_INIT;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_04) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERROR_INIT;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_05) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERROR_INIT;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

Suite* s21_remove_matrix_suite(void) {
  Suite* s = suite_create("suite_remove_matrix");
  TCase* tc = tcase_create("case_remove_matrix");
  tcase_add_test(tc, two_for_two);
  tcase_add_test(tc, three_for_three);
  tcase_add_test(tc, s21_remove_matrix_01);
  tcase_add_test(tc, s21_remove_matrix_02);
  tcase_add_test(tc, s21_remove_matrix_03);
  tcase_add_test(tc, s21_remove_matrix_04);
  tcase_add_test(tc, s21_remove_matrix_05);

  suite_add_tcase(s, tc);
  return s;
}
