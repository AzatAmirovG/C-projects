#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int check = 1;
  if ((rows > 0) && (columns > 0)) {
    result->matrix = (double **)calloc(rows, sizeof(double));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
    check = 0;
  }
  return check;
}