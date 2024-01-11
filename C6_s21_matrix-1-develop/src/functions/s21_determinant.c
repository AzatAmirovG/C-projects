#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int check = 0;
  int rows = A->rows;
  if (s21_is_matrix_correct(A)) {
    return check = 1;
  }
  if (A->rows == A->columns) {
    if (rows == 1) {
      check = 0;
      *result = A->matrix[0][0];
    } else if (rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
      return check;
    } else {
      rows--;
      matrix_t temp = {0};
      s21_create_matrix(rows, rows, &temp);
      for (int i = 0; i < A->rows; i++) {
        int index_i = 0;
        for (int j = 1; j < A->rows; j++) {
          int index_j = 0;
          for (int k = 0; k < A->rows; k++) {
            if (k != i) {
              temp.matrix[index_i][index_j] = A->matrix[j][k];
              index_j++;
            }
          }
          index_i++;
        }
        double temp_result = 0;
        s21_determinant(&temp, &temp_result);
        if (i % 2 == 0) {
          *result += A->matrix[0][i] * temp_result;
        } else {
          *result -= A->matrix[0][i] * temp_result;
        }
      }
      s21_remove_matrix(&temp);
    }
  } else {
    check = 2;
  }
  return check;
}