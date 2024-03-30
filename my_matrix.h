#ifndef MY_MATRIX
#define MY_MATRIX

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

#define EPSILON 9e-7

#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int my_create_matrix(int rows, int columns, matrix_t *result);
void my_remove_matrix(matrix_t *A);
int my_eq_matrix(matrix_t *A, matrix_t *B);
int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_mult_number(matrix_t *A, double number, matrix_t *result);
int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int my_transpose(matrix_t *A, matrix_t *result);
int my_calc_complements(matrix_t *A, matrix_t *result);
int my_determinant(matrix_t *A, double *result);
int my_inverse_matrix(matrix_t *A, matrix_t *result);

// utils
int my_minor_item(matrix_t *A, int row, int column, double *result);

#endif  // MY_MATRIX