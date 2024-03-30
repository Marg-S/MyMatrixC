#include "my_matrix.h"

int my_transpose(matrix_t *A, matrix_t *result) {
  int error_code = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    error_code = INCORRECT_MATRIX;
  else if ((error_code = my_create_matrix(A->columns, A->rows, result)) == OK)
    for (int i = 0; i < result->rows; i++)
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[j][i];

  return error_code;
}