#include "my_matrix.h"

int my_minor_item(matrix_t *A, int row, int column, double *result) {
  int error_code = OK;

  matrix_t B = {0};
  if ((error_code = my_create_matrix(A->rows - 1, A->columns - 1, &B)) == OK) {
    for (int i = 0, x = 0; i < A->rows; i++)
      if (i != row) {
        for (int j = 0, y = 0; j < A->columns; j++)
          if (j != column) B.matrix[x][y++] = A->matrix[i][j];
        x++;
      }
    error_code = my_determinant(&B, result);
    my_remove_matrix(&B);
  }

  return error_code;
}

int my_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    error_code = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    error_code = CALCULATION_ERROR;
  else {
    if ((error_code = my_create_matrix(A->rows, A->columns, result)) == OK) {
      if (A->rows == 1)
        result->matrix[0][0] = 1;
      else
        for (int i = 0; i < A->rows; i++)
          for (int j = 0; j < A->columns; j++) {
            double minor;
            my_minor_item(A, i, j, &minor);
            result->matrix[i][j] = minor * pow(-1, i + j);
          }
    }
  }

  return error_code;
}