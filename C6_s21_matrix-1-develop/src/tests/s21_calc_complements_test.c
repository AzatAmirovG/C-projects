#include "s21_matrix_test.h"

START_TEST(s21_calc_compl_2) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t res = {0};
  s21_create_matrix(3, 3, &res);
  matrix_t m;
  res.matrix[0][0] = 0;
  res.matrix[0][1] = 10;
  res.matrix[0][2] = -20;
  res.matrix[1][0] = 4;
  res.matrix[1][1] = -14;
  res.matrix[1][2] = 8;
  res.matrix[2][0] = -8;
  res.matrix[2][1] = -2;
  res.matrix[2][2] = 4;

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;
  s21_calc_complements(&a, &m);
  ck_assert_int_eq(s21_eq_matrix(&res, &m), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST
START_TEST(s21_calc_compl_1) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[0][2] = -20.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  C.matrix[1][2] = 8.0;
  C.matrix[2][0] = -8.0;
  C.matrix[2][1] = -2.0;
  C.matrix[2][2] = 4.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST
START_TEST(empty) {
  matrix_t a = {0};
  matrix_t b = {0};
  ck_assert_int_eq(s21_calc_complements(&a, &b), 1);
}
END_TEST

START_TEST(size_mismatch) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &b), 2);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(complements) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;
  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;

  matrix_t res = {0};
  s21_calc_complements(&m, &res);

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_calc_complements_01) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -2879514.0;
  X.matrix[0][1] = -1236631.0;
  X.matrix[0][2] = -1685096.0;
  X.matrix[0][3] = 880697.0;
  X.matrix[1][0] = 1162090.0;
  X.matrix[1][1] = -714015.0;
  X.matrix[1][2] = 4046255.0;
  X.matrix[1][3] = -3901600.0;
  X.matrix[2][0] = 4362897.0;
  X.matrix[2][1] = -2049432.0;
  X.matrix[2][2] = -532912.0;
  X.matrix[2][3] = -1370781.0;
  X.matrix[3][0] = 3412773.0;
  X.matrix[3][1] = -1569493.0;
  X.matrix[3][2] = 3144517.0;
  X.matrix[3][3] = 1284666.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_calc_complements_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = -30.0;
  X.matrix[0][2] = -108.0;
  X.matrix[0][3] = 106.0;
  X.matrix[1][0] = 138.0;
  X.matrix[1][1] = -726.0;
  X.matrix[1][2] = -1137.0;
  X.matrix[1][3] = 1061.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 12.0;
  X.matrix[2][2] = 57.0;
  X.matrix[2][3] = -47.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 6.0;
  X.matrix[3][2] = -75.0;
  X.matrix[3][3] = 57.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_calc_complements_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 3, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;

  res = s21_calc_complements(&A, &Z);

  s21_remove_matrix(&A);

  ck_assert_int_eq(res, ERROR_CALC);
}
END_TEST

START_TEST(s21_calc_complements_04) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);

  res = s21_calc_complements(&A, &Z);

  ck_assert_int_eq(res, ERROR_INIT);
}
END_TEST

Suite* s21_calc_complements_suite(void) {
  Suite* s = suite_create("suite_calc_complements");
  TCase* tc = tcase_create("case_calc_complements");

  tcase_add_test(tc, s21_calc_compl_2);
  tcase_add_test(tc, s21_calc_compl_1);
  tcase_add_test(tc, complements);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, size_mismatch);
  tcase_add_test(tc, s21_calc_complements_01);
  tcase_add_test(tc, s21_calc_complements_02);
  tcase_add_test(tc, s21_calc_complements_03);
  tcase_add_test(tc, s21_calc_complements_04);

  suite_add_tcase(s, tc);
  return s;
}
