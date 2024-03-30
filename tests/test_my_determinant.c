#include "my_matrix_tests.h"

START_TEST(test_determinant_1) {
  matrix_t A;
  int error_code = my_create_matrix(5, 5, &A);

  if (error_code == OK) {
    for (int i = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) A.matrix[i][j] = j;

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, 0, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_2) {
  matrix_t A;
  int error_code = my_create_matrix(4, 4, &A);

  if (error_code == OK) {
    for (int i = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) A.matrix[i][j] = i + j;

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, 0, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_3) {
  matrix_t A;
  int error_code = my_create_matrix(5, 5, &A);

  if (error_code == OK) {
    double values[5][5] = {{0, 6, -2, -1, 5},
                           {0, 0, 0, -9, -7},
                           {0, 15, 35, 0, 0},
                           {0, -1, -11, -2, 1},
                           {-2, -2, 3, 0, -2}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, 2480, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_4) {
  matrix_t A;
  int error_code = my_create_matrix(3, 3, &A);

  if (error_code == OK) {
    double values[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, -1., EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_5) {
  matrix_t A;
  int error_code = my_create_matrix(1, 1, &A);

  if (error_code == OK) {
    A.matrix[0][0] = 1.25;

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, 1.25, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_6) {
  matrix_t A;
  int error_code = my_create_matrix(3, 3, &A);

  if (error_code == OK) {
    double values[3][3] = {
        {0.25, 1.25, 2.25}, {3.25, 10, 5.25}, {6.25, 7.25, 8.25}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, -69, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_7) {
  matrix_t A;
  int error_code = my_create_matrix(3, 3, &A);

  if (error_code == OK) {
    double values[3][3] = {{2, 4, -6}, {-5, -7, 5}, {3, 5, -6}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, -2, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_8) {
  matrix_t A;
  int error_code = my_create_matrix(3, 3, &A);

  if (error_code == OK) {
    double values[3][3] = {{-3, 4, -6}, {2, -7, 5}, {-4, 5, -6}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, 25, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_9) {
  matrix_t A;
  int error_code = my_create_matrix(3, 3, &A);

  if (error_code == OK) {
    double values[3][3] = {{-3, 2, -6}, {2, -5, 5}, {-4, 3, -6}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, 23, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_10) {
  matrix_t A;
  int error_code = my_create_matrix(3, 3, &A);

  if (error_code == OK) {
    double values[3][3] = {{-3, 2, 4}, {2, -5, -7}, {-4, 3, 5}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, -8, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_11) {
  matrix_t A;
  int error_code = my_create_matrix(5, 5, &A);

  if (error_code == OK) {
    double values[5][5] = {{0.25, 1.25, 2.25, 3.25, 2.25},
                           {3.25, 10, 5.25, 5.25, 5.25},
                           {6.25, 7.25, 8.25, 6.25, 6.25},
                           {6.25, 7.25, 8.25, 6.25, 7.25},
                           {6.25, 7.25, 8.25, 6, 8.25}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK)
      ck_assert_double_eq_tol(result, -69.0 / 4.0, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_12) {
  matrix_t A;
  int error_code = my_create_matrix(4, 4, &A);

  if (error_code == OK) {
    double values[4][4] = {
        {1, 2, 3, 13}, {4, 5, 6, 16}, {7, 8, 90, 19}, {1, 7, 7, 17}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, OK);
    if (error_code_det == OK) ck_assert_double_eq_tol(result, 13608, EPSILON);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_13) {
  matrix_t A;
  int error_code = my_create_matrix(4, 5, &A);

  if (error_code == OK) {
    double result;
    int error_code_det = my_determinant(&A, &result);
    ck_assert_int_eq(error_code_det, CALCULATION_ERROR);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_determinant_14) {
  matrix_t* A = NULL;
  double result;
  int error_code_det = my_determinant(A, &result);
  ck_assert_int_eq(error_code_det, INCORRECT_MATRIX);
}
END_TEST

TCase* tcase_my_determinant() {
  TCase* tcase = tcase_create("tcase_my_determinant");

  tcase_add_test(tcase, test_determinant_1);
  tcase_add_test(tcase, test_determinant_2);
  tcase_add_test(tcase, test_determinant_3);
  tcase_add_test(tcase, test_determinant_4);
  tcase_add_test(tcase, test_determinant_5);
  tcase_add_test(tcase, test_determinant_6);
  tcase_add_test(tcase, test_determinant_7);
  tcase_add_test(tcase, test_determinant_8);
  tcase_add_test(tcase, test_determinant_9);
  tcase_add_test(tcase, test_determinant_10);
  tcase_add_test(tcase, test_determinant_11);
  tcase_add_test(tcase, test_determinant_12);
  tcase_add_test(tcase, test_determinant_13);
  tcase_add_test(tcase, test_determinant_14);

  return tcase;
}
