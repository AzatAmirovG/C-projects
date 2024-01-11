#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if (s21_is_matrix_correct(A) || s21_is_matrix_correct(B)) {
    return result = FAILURE;
  }
  if ((A->columns == B->columns) & (A->rows == B->rows)) {
    result = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; (j < A->columns) & (result == SUCCESS); j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}