#include "my_matrix.h"

void my_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}