#include "my_matrix_tests.h"

START_TEST(test_mult_number_1) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(4, 40, &A);
  int error_code2 = my_create_matrix(4, 40, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    for (int i = 0, k = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) A.matrix[i][j] = ++k;

    for (int i = 0, k = 3; i < goal.rows; i++)
      for (int j = 0; j < goal.columns; j++, k += 3) goal.matrix[i][j] = k;

    int error_code_mul = my_mult_number(&A, 3.0, &result);
    ck_assert_int_eq(error_code_mul, OK);
    if (error_code_mul == OK) {
      int equal = my_eq_matrix(&result, &goal);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_mult_number_2) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 1.25;
    goal.matrix[0][0] = -5;

    int error_code_mul = my_mult_number(&A, -4, &result);
    if (error_code_mul == OK) {
      int equal = my_eq_matrix(&result, &goal);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_mult_number_3) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double k = 0.25;
    for (int i = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++, k += 1) A.matrix[i][j] = k;

    for (int i = 0, k = 1; i < goal.rows; i++)
      for (int j = 0; j < goal.columns; j++, k += 4) goal.matrix[i][j] = k;

    int error_code_mul = my_mult_number(&A, 4, &result);
    if (error_code_mul == OK) {
      int equal = my_eq_matrix(&result, &goal);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_mult_number_4) {
  matrix_t *A = NULL, result;
  int error_code_mul = my_mult_number(A, 0., &result);
  ck_assert_int_eq(error_code_mul, INCORRECT_MATRIX);
  if (error_code_mul == OK) my_remove_matrix(A);
}
END_TEST

TCase* tcase_my_mult_number() {
  TCase* tcase = tcase_create("tcase_my_mult_number");

  tcase_add_test(tcase, test_mult_number_1);
  tcase_add_test(tcase, test_mult_number_2);
  tcase_add_test(tcase, test_mult_number_3);
  tcase_add_test(tcase, test_mult_number_4);

  return tcase;
}
