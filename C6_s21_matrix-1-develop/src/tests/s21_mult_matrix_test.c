#include "s21_matrix_test.h"

START_TEST(test_s21_mult_matrix) {
  matrix_t mat_1, mat_2, res_mat, res_org;

  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(2, 2, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat_1.matrix[i][j] = i + j + 1;
      mat_2.matrix[i][j] = i + j + 1;
    }
  }
  res_org.matrix[0][0] = 5;
  res_org.matrix[0][1] = 8;
  res_org.matrix[1][0] = 8;
  res_org.matrix[1][1] = 13;
  int ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(3, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(3, 2, &res_org);
  ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 7, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
}
END_TEST

START_TEST(simple_mult) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = c++;

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);
  check.matrix[0][0] = 58;
  check.matrix[0][1] = 64;
  check.matrix[1][0] = 139;
  check.matrix[1][1] = 154;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix_01) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 90.0;
  X.matrix[0][1] = 100.0;
  X.matrix[0][2] = 110.0;
  X.matrix[0][3] = 120.0;
  X.matrix[1][0] = 202.0;
  X.matrix[1][1] = 228.0;
  X.matrix[1][2] = 254.0;
  X.matrix[1][3] = 280.0;
  X.matrix[2][0] = 314.0;
  X.matrix[2][1] = 356.0;
  X.matrix[2][2] = 398.0;
  X.matrix[2][3] = 440.0;
  X.matrix[3][0] = 426.0;
  X.matrix[3][1] = 484.0;
  X.matrix[3][2] = 542.0;
  X.matrix[3][3] = 600.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-5.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 30.0;
  X.matrix[0][1] = 40.0;
  X.matrix[0][2] = 50.0;
  X.matrix[0][3] = 60.0;
  X.matrix[1][0] = 46.0;
  X.matrix[1][1] = 72.0;
  X.matrix[1][2] = 98.0;
  X.matrix[1][3] = 124.0;
  X.matrix[2][0] = 62.0;
  X.matrix[2][1] = 104.0;
  X.matrix[2][2] = 146.0;
  X.matrix[2][3] = 188.0;
  X.matrix[3][0] = 78.0;
  X.matrix[3][1] = 136.0;
  X.matrix[3][2] = 194.0;
  X.matrix[3][3] = 252.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_03) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -78.0;
  X.matrix[0][1] = -92.0;
  X.matrix[0][2] = -106.0;
  X.matrix[0][3] = -120.0;
  X.matrix[1][0] = 34.0;
  X.matrix[1][1] = 36.0;
  X.matrix[1][2] = 38.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 146.0;
  X.matrix[2][1] = 164.0;
  X.matrix[2][2] = 182.0;
  X.matrix[2][3] = 200.0;
  X.matrix[3][0] = 258.0;
  X.matrix[3][1] = 292.0;
  X.matrix[3][2] = 326.0;
  X.matrix[3][3] = 360.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_04) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -25.0;
  X.matrix[0][1] = -34.0;
  X.matrix[0][2] = -43.0;
  X.matrix[0][3] = -52.0;
  X.matrix[1][0] = -13.0;
  X.matrix[1][1] = -18.0;
  X.matrix[1][2] = -23.0;
  X.matrix[1][3] = -28.0;
  X.matrix[2][0] = -1.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -3.0;
  X.matrix[2][3] = -4.0;
  X.matrix[3][0] = 11.0;
  X.matrix[3][1] = 14.0;
  X.matrix[3][2] = 17.0;
  X.matrix[3][3] = 20.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_05) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(1, 1, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(1, 1, &X);

  X.matrix[0][0] = -5.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_06) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  res = s21_mult_matrix(&A, &B, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, ERROR_INIT);
}
END_TEST

START_TEST(s21_mult_matrix_07) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 2, &B);
  s21_init_matrix(1.0, &B);

  res = s21_mult_matrix(&A, &B, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, ERROR_CALC);
}
END_TEST

Suite* s21_mult_matrix_suite(void) {
  Suite* s = suite_create("suite_mult_matrix");
  TCase* tc = tcase_create("case_mult_matrix");
  tcase_add_test(tc, test_s21_mult_matrix);
  tcase_add_test(tc, simple_mult);
  tcase_add_test(tc, s21_mult_matrix_01);
  tcase_add_test(tc, s21_mult_matrix_02);
  tcase_add_test(tc, s21_mult_matrix_03);
  tcase_add_test(tc, s21_mult_matrix_04);
  tcase_add_test(tc, s21_mult_matrix_05);
  tcase_add_test(tc, s21_mult_matrix_06);
  tcase_add_test(tc, s21_mult_matrix_07);

  suite_add_tcase(s, tc);
  return s;
}
