#include "my_matrix.h"

int my_eq_matrix(matrix_t *A, matrix_t *B) {
  int equal = SUCCESS;

  if (A == NULL || B == NULL || A->rows != B->rows ||
      A->columns != B->columns || A->rows <= 0 || A->columns <= 0 ||
      B->rows <= 0 || B->columns <= 0 || A->matrix == NULL || B->matrix == NULL)
    equal = FAILURE;
  else {
    for (int i = 0; i < A->rows && equal == SUCCESS; i++) {
      for (int j = 0; j < A->columns && equal == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) equal = FAILURE;
      }
    }
  }

  return equal;
}