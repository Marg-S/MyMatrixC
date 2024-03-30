#include "my_matrix_tests.h"

START_TEST(test_eq_matrix_1) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 12345.678;
    B.matrix[0][0] = 12345.678;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, SUCCESS);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code1 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_2) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 12345.678;
    B.matrix[0][0] = 123.45678;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code1 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_3) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 123.45678;
    B.matrix[0][0] = 12345.678;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code1 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_4) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 12345.;
    B.matrix[0][0] = 12345.678;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_5) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 12345.678;
    B.matrix[0][0] = 12345.;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_6) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 12344.;
    B.matrix[0][0] = 12345.;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_7) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 12345.67891;
    B.matrix[0][0] = 12345.6789;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_8) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 123.456788;
    B.matrix[0][0] = 123.456789;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_9) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 12.3456788;
    B.matrix[0][0] = 12.3456789;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, SUCCESS);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_10) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 2, &B);
  if (error_code1 == OK && error_code2 == OK) {
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_11) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(2, 1, &B);
  if (error_code1 == OK && error_code2 == OK) {
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_12) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(100, 100, &A);
  int error_code2 = my_create_matrix(10, 10, &B);
  if (error_code1 == OK && error_code2 == OK) {
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_13) {
  matrix_t A = {0}, B = {0};
  int error_code1 = my_create_matrix(1, 1, &A);
  if (error_code1 == OK) {
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_eq_matrix_14) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(100, 100, &A);
  int error_code2 = my_create_matrix(100, 100, &B);
  if (error_code1 == OK && error_code2 == OK) {
    for (int i = 0, k = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) {
        A.matrix[i][j] = ++k;
        B.matrix[i][j] = k;
      }
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, SUCCESS);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_15) {
  matrix_t A, B;
  int error_code1 = my_create_matrix(100, 100, &A);
  int error_code2 = my_create_matrix(100, 100, &B);
  if (error_code1 == OK && error_code2 == OK) {
    for (int i = 0, k = 0; i < A.rows; i++)
      for (int j = 0; j < A.columns; j++) {
        A.matrix[i][j] = ++k;
        B.matrix[i][j] = k;
      }
    B.matrix[50][50] = DBL_MAX;
    int equal = my_eq_matrix(&A, &B);
    ck_assert_int_eq(equal, FAILURE);
  }
  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&B);
}
END_TEST

TCase* tcase_my_eq_matrix() {
  TCase* tcase = tcase_create("tcase_my_eq_matrix");

  tcase_add_test(tcase, test_eq_matrix_1);
  tcase_add_test(tcase, test_eq_matrix_2);
  tcase_add_test(tcase, test_eq_matrix_3);
  tcase_add_test(tcase, test_eq_matrix_4);
  tcase_add_test(tcase, test_eq_matrix_5);
  tcase_add_test(tcase, test_eq_matrix_6);
  tcase_add_test(tcase, test_eq_matrix_7);
  tcase_add_test(tcase, test_eq_matrix_8);
  tcase_add_test(tcase, test_eq_matrix_9);
  tcase_add_test(tcase, test_eq_matrix_10);
  tcase_add_test(tcase, test_eq_matrix_11);
  tcase_add_test(tcase, test_eq_matrix_12);
  tcase_add_test(tcase, test_eq_matrix_13);
  tcase_add_test(tcase, test_eq_matrix_14);
  tcase_add_test(tcase, test_eq_matrix_15);

  return tcase;
}
