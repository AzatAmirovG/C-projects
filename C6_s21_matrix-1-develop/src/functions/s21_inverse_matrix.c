#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int check = 0;
  if (s21_is_matrix_correct(A)) {
    return check = 1;
  }
  double determinant = 0;
  s21_determinant(A, &determinant);
  if ((A->rows == A->columns) && (determinant != 0)) {
    int rows = A->rows;
    s21_create_matrix(rows, rows, result);
    matrix_t temp1 = {0};
    matrix_t temp2 = {0};
    s21_calc_complements(A, &temp1);
    s21_transpose(&temp1, &temp2);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < rows; j++) {
        result->matrix[i][j] = temp2.matrix[i][j] / determinant;
      }
    }
    s21_remove_matrix(&temp1);
    s21_remove_matrix(&temp2);
  } else {
    check = 2;
  }
  return check;
}