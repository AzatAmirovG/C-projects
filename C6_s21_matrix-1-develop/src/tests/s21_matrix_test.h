#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#ifndef S21_MATRIX_TEST_H
#define S21_MATRIX_TEST_H

#define OK 0
#define ERROR_INIT 1
#define ERROR_CALC 2
#define MAX_DOUBLE 1.79769e+308
#define MIN_DOUBLE 2.22507e-308

Suite* s21_create_matrix_suite(void);
Suite* s21_remove_matrix_suite(void);
Suite* s21_eq_matrix_suite(void);
Suite* s21_sum_matrix_suite(void);
Suite* s21_sub_matrix_suite(void);
Suite* s21_mult_number_suite(void);
Suite* s21_mult_matrix_suite(void);
Suite* s21_transpose_suite(void);
Suite* s21_determinant_suite(void);
Suite* s21_calc_complements_suite(void);
Suite* s21_inverse_matrix_suite(void);

void s21_test_one_suite(Suite* current_suit, int* sum_of_errors);

#endif