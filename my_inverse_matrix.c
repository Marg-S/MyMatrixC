#include "my_matrix.h"

int my_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    error_code = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    error_code = CALCULATION_ERROR;
  else {
    double det = 0;
    if ((error_code = my_determinant(A, &det)) == OK) {
      if (det == 0)
        error_code = CALCULATION_ERROR;
      else {
        matrix_t B1 = {0}, B2 = {0};
        my_calc_complements(A, &B1);
        my_transpose(&B1, &B2);
        error_code = my_mult_number(&B2, 1 / det, result);
        my_remove_matrix(&B2);
        my_remove_matrix(&B1);
      }
    }
  }

  return error_code;
}