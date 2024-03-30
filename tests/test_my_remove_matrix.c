#include "my_matrix_tests.h"

START_TEST(test_remove_matrix_1) {
  matrix_t A;
  int error_code = my_create_matrix(1, 1, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 1);
    ck_assert_int_eq(A.columns, 1);

    my_remove_matrix(&A);
    ck_assert_ptr_null(A.matrix);
    ck_assert_int_eq(A.rows, 0);
    ck_assert_int_eq(A.columns, 0);
  }
}
END_TEST

START_TEST(test_remove_matrix_2) {
  matrix_t A;
  int error_code = my_create_matrix(12, 30, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 12);
    ck_assert_int_eq(A.columns, 30);

    my_remove_matrix(&A);
    ck_assert_ptr_null(A.matrix);
    ck_assert_int_eq(A.rows, 0);
    ck_assert_int_eq(A.columns, 0);
  }
}
END_TEST

START_TEST(test_remove_matrix_3) {
  matrix_t A;
  int error_code = my_create_matrix(1000, 1000, &A);
  ck_assert_int_eq(error_code, OK);
  if (error_code == OK) {
    ck_assert_int_eq(A.rows, 1000);
    ck_assert_int_eq(A.columns, 1000);

    my_remove_matrix(&A);
    ck_assert_ptr_null(A.matrix);
    ck_assert_int_eq(A.rows, 0);
    ck_assert_int_eq(A.columns, 0);
  }
}
END_TEST

TCase* tcase_my_remove_matrix() {
  TCase* tcase = tcase_create("tcase_my_remove_matrix");

  tcase_add_test(tcase, test_remove_matrix_1);
  tcase_add_test(tcase, test_remove_matrix_2);
  tcase_add_test(tcase, test_remove_matrix_3);

  return tcase;
}
