#include "my_matrix_tests.h"

START_TEST(test_transpose_1) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(2, 3, &A);
  int error_code2 = my_create_matrix(3, 2, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    for (int i = 0, k = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        A.matrix[i][j] = ++k;
        goal.matrix[j][i] = k;
      }
    }

    int error_code_transp = my_transpose(&A, &result);
    ck_assert_int_eq(error_code_transp, OK);
    if (error_code_transp == OK) {
      ck_assert_int_eq(my_eq_matrix(&goal, &result), SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_transpose_2) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double values[3][3] = {{-1, 38, -27}, {1, -41, 29}, {-1, 34, -24}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double goal_values[3][3] = {{-1, 1, -1}, {38, -41, 34}, {-27, 29, -24}};
    memcpy(goal.matrix[0], goal_values,
           goal.rows * goal.columns * sizeof(double));

    int error_code_transp = my_transpose(&A, &result);
    ck_assert_int_eq(error_code_transp, OK);
    if (error_code_transp == OK) {
      ck_assert_int_eq(my_eq_matrix(&result, &goal), SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_transpose_3) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 1.25;
    goal.matrix[0][0] = 1.25;

    int error_code_transp = my_transpose(&A, &result);
    ck_assert_int_eq(error_code_transp, OK);
    if (error_code_transp == OK) {
      ck_assert_int_eq(my_eq_matrix(&result, &goal), SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_transpose_4) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double values[3][3] = {
        {0.25, 1.25, 2.25}, {3.25, 4.25, 5.25}, {6.25, 7.25, 8.25}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double goal_values[3][3] = {
        {0.25, 3.25, 6.25}, {1.25, 4.25, 7.25}, {2.25, 5.25, 8.25}};
    memcpy(goal.matrix[0], goal_values,
           goal.rows * goal.columns * sizeof(double));

    int error_code_transp = my_transpose(&A, &result);
    ck_assert_int_eq(error_code_transp, OK);
    if (error_code_transp == OK) {
      ck_assert_int_eq(my_eq_matrix(&result, &goal), SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_transpose_5) {
  matrix_t A, result;
  int error_code = my_create_matrix(1, 1, &A);

  if (error_code == OK) {
    A.columns = -1;

    int error_code_transp = my_transpose(&A, &result);
    ck_assert_int_eq(error_code_transp, INCORRECT_MATRIX);
    if (error_code_transp == OK) my_remove_matrix(&result);
  }

  if (error_code == OK) my_remove_matrix(&A);
}
END_TEST

TCase* tcase_my_transpose() {
  TCase* tcase = tcase_create("tcase_my_transpose");

  tcase_add_test(tcase, test_transpose_1);
  tcase_add_test(tcase, test_transpose_2);
  tcase_add_test(tcase, test_transpose_3);
  tcase_add_test(tcase, test_transpose_4);
  tcase_add_test(tcase, test_transpose_5);

  return tcase;
}
