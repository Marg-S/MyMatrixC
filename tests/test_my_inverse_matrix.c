#include "my_matrix_tests.h"

START_TEST(test_inverse_matrix_1) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 5;
    goal.matrix[0][0] = 1. / 5;

    int error_code_inverse = my_inverse_matrix(&A, &result);
    ck_assert_int_eq(error_code_inverse, OK);
    if (error_code_inverse == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double values[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    memcpy(A.matrix[0], values, 9 * sizeof(double));

    double goal_values[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
    memcpy(goal.matrix[0], goal_values, 9 * sizeof(double));

    int error_code_inverse = my_inverse_matrix(&A, &result);
    ck_assert_int_eq(error_code_inverse, OK);
    if (error_code_inverse == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double values[3][3] = {{2.8, 1.3, 7.01}, {-1.03, -2.3, 3.01}, {0, -3, 2}};
    memcpy(A.matrix[0], values, 9 * sizeof(double));

    double goal_values[3][3] = {
        {44300.0 / 367429.0, -236300.0 / 367429.0, 200360.0 / 367429.0},
        {20600.0 / 367429.0, 56000.0 / 367429.0, -156483.0 / 367429.0},
        {30900.0 / 367429.0, 84000.0 / 367429.0, -51010.0 / 367429.0}};
    memcpy(goal.matrix[0], goal_values, 9 * sizeof(double));

    int error_code_inverse = my_inverse_matrix(&A, &result);
    ck_assert_int_eq(error_code_inverse, OK);
    if (error_code_inverse == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 1431.12312331;
    goal.matrix[0][0] = 1. / 1431.12312331;

    int error_code_inverse = my_inverse_matrix(&A, &result);
    ck_assert_int_eq(error_code_inverse, OK);
    if (error_code_inverse == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_inverse_matrix_5) {
  matrix_t A, result;
  int error_code = my_create_matrix(1, 1, &A);

  if (error_code == OK) {
    int error_code_inverse = my_inverse_matrix(&A, &result);
    ck_assert_int_eq(error_code_inverse, CALCULATION_ERROR);
    if (error_code_inverse == OK) my_remove_matrix(&result);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_inverse_matrix_6) {
  matrix_t A = {0}, result;
  int error_code_inverse = my_inverse_matrix(&A, &result);
  ck_assert_int_eq(error_code_inverse, INCORRECT_MATRIX);
  if (error_code_inverse == OK) my_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_7) {
  matrix_t A, result;
  int error_code = my_create_matrix(1, 4, &A);

  if (error_code == OK) {
    int error_code_inverse = my_inverse_matrix(&A, &result);
    ck_assert_int_eq(error_code_inverse, CALCULATION_ERROR);
    if (error_code_inverse == OK) my_remove_matrix(&result);
    my_remove_matrix(&A);
  }
}
END_TEST

TCase* tcase_my_inverse_matrix() {
  TCase* tcase = tcase_create("tcase_my_inverse_matrix");

  tcase_add_test(tcase, test_inverse_matrix_1);
  tcase_add_test(tcase, test_inverse_matrix_2);
  tcase_add_test(tcase, test_inverse_matrix_3);
  tcase_add_test(tcase, test_inverse_matrix_4);
  tcase_add_test(tcase, test_inverse_matrix_5);
  tcase_add_test(tcase, test_inverse_matrix_6);
  tcase_add_test(tcase, test_inverse_matrix_7);

  return tcase;
}
