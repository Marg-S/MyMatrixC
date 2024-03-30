#include "my_matrix_tests.h"

START_TEST(test_create_matrix_1) {
  matrix_t A;
  int error_code = my_create_matrix(1, 1, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 1);
    ck_assert_int_eq(A.columns, 1);
    ck_assert_double_eq(A.matrix[0][0], 0);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_create_matrix_2) {
  matrix_t A;
  int error_code = my_create_matrix(1, 2, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 1);
    ck_assert_int_eq(A.columns, 2);
    ck_assert_double_eq(A.matrix[0][0], 0);
    ck_assert_double_eq(A.matrix[0][1], 0);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_create_matrix_3) {
  matrix_t A;
  int error_code = my_create_matrix(2, 1, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 2);
    ck_assert_int_eq(A.columns, 1);
    ck_assert_double_eq(A.matrix[0][0], 0);
    ck_assert_double_eq(A.matrix[1][0], 0);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_create_matrix_4) {
  matrix_t A;
  int error_code = my_create_matrix(2, 2, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 2);
    ck_assert_int_eq(A.columns, 2);
    for (int i = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++)
        ck_assert_double_eq(A.matrix[i][j], 0);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_create_matrix_5) {
  matrix_t A;
  int error_code = my_create_matrix(100, 100, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 100);
    ck_assert_int_eq(A.columns, 100);
    for (int i = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++)
        ck_assert_double_eq(A.matrix[i][j], 0);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_create_matrix_6) {
  matrix_t A;
  int error_code = my_create_matrix(0, 0, &A);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  if (error_code == OK) my_remove_matrix(&A);
}
END_TEST

START_TEST(test_create_matrix_7) {
  matrix_t A;
  int error_code = my_create_matrix(0, 1, &A);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  if (error_code == OK) my_remove_matrix(&A);
}
END_TEST

START_TEST(test_create_matrix_8) {
  matrix_t A;
  int error_code = my_create_matrix(1, 0, &A);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  if (error_code == OK) my_remove_matrix(&A);
}
END_TEST

START_TEST(test_create_matrix_9) {
  matrix_t A;
  int error_code = my_create_matrix(0, 100, &A);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  if (error_code == OK) my_remove_matrix(&A);
}
END_TEST

START_TEST(test_create_matrix_10) {
  matrix_t* A = NULL;
  int error_code = my_create_matrix(100, 100, A);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  if (error_code == OK) my_remove_matrix(A);
}
END_TEST

START_TEST(test_create_matrix_11) {
  matrix_t A;
  int error_code = my_create_matrix(1, -1, &A);
  ck_assert_int_eq(error_code, INCORRECT_MATRIX);
  if (error_code == OK) my_remove_matrix(&A);
}
END_TEST

TCase* tcase_my_create_matrix() {
  TCase* tcase = tcase_create("tcase_my_create_matrix");

  tcase_add_test(tcase, test_create_matrix_1);
  tcase_add_test(tcase, test_create_matrix_2);
  tcase_add_test(tcase, test_create_matrix_3);
  tcase_add_test(tcase, test_create_matrix_4);
  tcase_add_test(tcase, test_create_matrix_5);
  tcase_add_test(tcase, test_create_matrix_6);
  tcase_add_test(tcase, test_create_matrix_7);
  tcase_add_test(tcase, test_create_matrix_8);
  tcase_add_test(tcase, test_create_matrix_9);
  tcase_add_test(tcase, test_create_matrix_10);
  tcase_add_test(tcase, test_create_matrix_11);

  return tcase;
}
