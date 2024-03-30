#include "my_matrix.h"

int my_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    error_code = INCORRECT_MATRIX;
  else {
    if ((error_code = my_create_matrix(A->rows, A->columns, result)) == OK)
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] * number;
  }

  return error_code;
}