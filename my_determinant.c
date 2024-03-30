#include "my_matrix.h"

void my_get_zero(int i, int j, matrix_t *B) {
  if (B->matrix[j][j] == 0) {
    for (int k = 0; k < B->columns; k++) {
      double buf = B->matrix[j][k];
      B->matrix[j][k] = B->matrix[i][k];
      B->matrix[i][k] = -buf;
    }
  } else {
    double mult = B->matrix[i][j] / B->matrix[j][j];
    for (int k = 0; k < B->columns; k++)
      B->matrix[i][k] -= mult * B->matrix[j][k];
  }
}

int my_determinant(matrix_t *A, double *result) {
  int error_code = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    error_code = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    error_code = CALCULATION_ERROR;
  else {
    matrix_t B = {0};
    if ((error_code = my_create_matrix(A->rows, A->columns, &B)) == OK) {
      memcpy(B.matrix[0], A->matrix[0], A->rows * A->columns * sizeof(double));
      for (int j = 0; j < B.columns - 1; j++)
        for (int i = j + 1; i < B.rows; i++)
          if (B.matrix[i][j] != 0) my_get_zero(i, j, &B);
      double det = 1;
      for (int i = 0; i < B.rows; i++) det *= B.matrix[i][i];
      *result = det;
      my_remove_matrix(&B);
    }
  }

  return error_code;
}