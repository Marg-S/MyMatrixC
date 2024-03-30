#include "my_matrix_tests.h"

START_TEST(test_mult_matrix_1) {
  matrix_t A, B, goal, result;
  int error_code1 = my_create_matrix(6, 5, &A);
  int error_code2 = my_create_matrix(5, 6, &B);
  int error_code3 = my_create_matrix(6, 6, &goal);

  if (error_code1 == OK && error_code2 == OK && error_code3 == OK) {
    for (int i = 0, k = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) A.matrix[i][j] = ++k;

    for (int i = 0, k = 1; i < B.rows; i++)
      for (int j = 0; j < B.columns; j++) B.matrix[i][j] = ++k;

    for (int i = 0; i < goal.rows; i++)
      for (int j = 0; j < goal.columns; j++)
        for (int k = 0; k < A.columns; k++)
          goal.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];

    int error_code_mult = my_mult_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_mult, OK);
    if (error_code_mult == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
  if (error_code3 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_mult_matrix_2) {
  matrix_t A, B, result;
  int error_code1 = my_create_matrix(5, 5, &A);
  int error_code2 = my_create_matrix(6, 6, &B);

  if (error_code1 == OK && error_code2 == OK) {
    int error_code_mult = my_mult_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_mult, CALCULATION_ERROR);
    if (error_code_mult == OK) my_remove_matrix(&result);
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_matrix_3) {
  matrix_t A, B, result;
  int error_code1 = my_create_matrix(5, 5, &A);
  int error_code2 = my_create_matrix(5, 5, &B);
  A.rows = -10;

  if (error_code1 == OK && error_code2 == OK) {
    int error_code_mult = my_mult_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_mult, INCORRECT_MATRIX);
    if (error_code_mult == OK) my_remove_matrix(&result);
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_matrix_4) {
  matrix_t A, B, goal, result;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  int error_code3 = my_create_matrix(1, 1, &goal);

  if (error_code1 == OK && error_code2 == OK && error_code3 == OK) {
    A.matrix[0][0] = -10.3;
    B.matrix[0][0] = 30.11111;
    goal.matrix[0][0] = -310.144433;

    int error_code_mult = my_mult_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_mult, OK);
    if (error_code_mult == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
  if (error_code3 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_mult_matrix_5) {
  matrix_t A, B, goal, result;
  int error_code1 = my_create_matrix(3, 2, &A);
  int error_code2 = my_create_matrix(2, 4, &B);
  int error_code3 = my_create_matrix(3, 4, &goal);

  if (error_code1 == OK && error_code2 == OK && error_code3 == OK) {
    double values1[3][2] = {{0, 1}, {3, 4}, {6, 7}};
    memcpy(A.matrix[0], values1, A.rows * A.columns * sizeof(double));

    double values2[2][4] = {{9, 8, 7, 7}, {6, 5, 4, 7}};
    memcpy(B.matrix[0], values2, B.rows * B.columns * sizeof(double));

    double goal_values[3][4] = {
        {6, 5, 4, 7}, {51, 44, 37, 49}, {96, 83, 70, 91}};
    memcpy(goal.matrix[0], goal_values,
           goal.rows * goal.columns * sizeof(double));

    int error_code_mult = my_mult_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_mult, OK);
    if (error_code_mult == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
  if (error_code3 == OK) my_remove_matrix(&goal);
}
END_TEST

TCase* tcase_my_mult_matrix() {
  TCase* tcase = tcase_create("tcase_my_mult_matrix");

  tcase_add_test(tcase, test_mult_matrix_1);
  tcase_add_test(tcase, test_mult_matrix_2);
  tcase_add_test(tcase, test_mult_matrix_3);
  tcase_add_test(tcase, test_mult_matrix_4);
  tcase_add_test(tcase, test_mult_matrix_5);

  return tcase;
}
