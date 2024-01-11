#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int check = 0;
  int rows = A->rows;
  if (s21_is_matrix_correct(A)) {
    return check = 1;
  }
  if (A->rows == A->columns) {
    s21_create_matrix(rows, rows, result);
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      rows--;
      matrix_t temp = {0};
      s21_create_matrix(rows, rows, &temp);

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->rows; j++) {
          int index_i = 0;
          for (int m = 0; m < A->rows; m++) {
            int index_j = 0;
            if (m != i) {
              for (int k = 0; k < A->rows; k++) {
                if (k != j) {
                  temp.matrix[index_i][index_j] = A->matrix[m][k];
                  index_j++;
                }
              }
              index_i++;
            }
          }
          double element = 0;
          s21_determinant(&temp, &element);
          result->matrix[i][j] = element * pow(-1, i + j);
        }
      }
      s21_remove_matrix(&temp);
    }
  } else {
    check = 2;
  }
  return check;
}