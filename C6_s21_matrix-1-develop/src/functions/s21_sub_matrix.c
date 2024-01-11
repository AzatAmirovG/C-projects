#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int resulted = 0;
  if (s21_is_matrix_correct(A) || s21_is_matrix_correct(B)) {
    return resulted = 1;
  }
  if ((A->rows == B->rows) & (A->columns == B->columns)) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    resulted = 2;
  }
  return resulted;
}