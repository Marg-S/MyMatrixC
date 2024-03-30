#include "my_matrix_tests.h"

START_TEST(test_sum_matrix_1) {
  matrix_t A, B, goal, result;
  int error_code1 = my_create_matrix(4, 40, &A);
  int error_code2 = my_create_matrix(4, 40, &B);
  int error_code3 = my_create_matrix(4, 40, &goal);

  if (error_code1 == OK && error_code2 == OK && error_code3 == OK) {
    for (int i = 0, k = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) {
        A.matrix[i][j] = ++k;
        B.matrix[i][j] = k;
      }

    for (int i = 0, k = 2; i < goal.rows; i++)
      for (int j = 0; j < goal.columns; j++, k += 2) goal.matrix[i][j] = k;

    int error_code_sum = my_sum_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_sum, OK);
    if (error_code_sum == OK) {
      int equal = my_eq_matrix(&result, &goal);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
  if (error_code3 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_sum_matrix_2) {
  matrix_t A, B, goal, result;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  int error_code3 = my_create_matrix(1, 1, &goal);

  if (error_code1 == OK && error_code2 == OK && error_code3 == OK) {
    A.matrix[0][0] = 5.55;
    B.matrix[0][0] = 4.44;

    goal.matrix[0][0] = 9.99;

    int error_code_sum = my_sum_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_sum, OK);
    if (error_code_sum == OK) {
      int equal = my_eq_matrix(&result, &goal);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
  if (error_code3 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_sum_matrix_3) {
  matrix_t A, B, result;
  int error_code1 = my_create_matrix(10, 10, &A);
  int error_code2 = my_create_matrix(10, 11, &B);

  if (error_code1 == OK && error_code2 == OK) {
    int error_code_sum = my_sum_matrix(&A, &B, &result);
    ck_assert_int_eq(error_code_sum, CALCULATION_ERROR);
    if (error_code_sum == OK) my_remove_matrix(&result);
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_4) {
  matrix_t *A = NULL, *B = NULL, result;
  int error_code_sum = my_sum_matrix(A, B, &result);
  ck_assert_int_eq(error_code_sum, INCORRECT_MATRIX);
  if (error_code_sum == OK) my_remove_matrix(&result);
}
END_TEST

TCase* tcase_my_sum_matrix() {
  TCase* tcase = tcase_create("tcase_my_sum_matrix");

  tcase_add_test(tcase, test_sum_matrix_1);
  tcase_add_test(tcase, test_sum_matrix_2);
  tcase_add_test(tcase, test_sum_matrix_3);
  tcase_add_test(tcase, test_sum_matrix_4);

  return tcase;
}
