#include "s21_matrix_test.h"

int main(void) {
  int number_failed = 0;
  Suite* s[] = {s21_create_matrix_suite(),  s21_remove_matrix_suite(),
                s21_eq_matrix_suite(),      s21_sum_matrix_suite(),
                s21_sub_matrix_suite(),     s21_mult_number_suite(),
                s21_mult_matrix_suite(),    s21_transpose_suite(),
                s21_determinant_suite(),    s21_calc_complements_suite(),
                s21_inverse_matrix_suite(), NULL};
  for (Suite** current_suite = s; *current_suite != NULL; current_suite++) {
    s21_test_one_suite(*current_suite, &number_failed);
  }
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void s21_test_one_suite(Suite* current_suit, int* sum_of_errors) {
  SRunner* sr;
  sr = srunner_create(current_suit);
  srunner_run_all(sr, CK_NORMAL);
  *sum_of_errors += srunner_ntests_failed(sr);
  srunner_free(sr);
}