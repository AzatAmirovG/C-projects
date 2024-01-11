#include "../s21_matrix.h"

int s21_is_matrix_correct(matrix_t *A) {
  int result = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    result = 1;
  }
  return result;
}