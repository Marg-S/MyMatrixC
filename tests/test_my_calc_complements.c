#include "my_matrix_tests.h"

START_TEST(test_calc_complements_1) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double values[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double goal_values[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
    memcpy(goal.matrix[0], goal_values,
           goal.rows * goal.columns * sizeof(double));

    int error_code_calc = my_calc_complements(&A, &result);
    ck_assert_int_eq(error_code_calc, OK);
    if (error_code_calc == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_calc_complements_2) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double values[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double goal_values[3][3] = {{-1, 38, -27}, {1, -41, 29}, {-1, 34, -24}};
    memcpy(goal.matrix[0], goal_values,
           goal.rows * goal.columns * sizeof(double));

    int error_code_calc = my_calc_complements(&A, &result);
    ck_assert_int_eq(error_code_calc, OK);
    if (error_code_calc == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_calc_complements_3) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(3, 3, &A);
  int error_code2 = my_create_matrix(3, 3, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    double values[3][3] = {{5, -1, 1}, {2, 3, 4}, {1, 0, 3}};
    memcpy(A.matrix[0], values, A.rows * A.columns * sizeof(double));

    double goal_values[3][3] = {{9, -2, -3}, {3, 14, -1}, {-7, -18, 17}};
    memcpy(goal.matrix[0], goal_values,
           goal.rows * goal.columns * sizeof(double));

    int error_code_calc = my_calc_complements(&A, &result);
    ck_assert_int_eq(error_code_calc, OK);
    if (error_code_calc == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_calc_complements_4) {
  matrix_t A, result;
  int error_code = my_create_matrix(2, 3, &A);

  if (error_code == OK) {
    int error_code_calc = my_calc_complements(&A, &result);
    ck_assert_int_eq(error_code_calc, CALCULATION_ERROR);
    if (error_code_calc == OK) my_remove_matrix(&result);
    my_remove_matrix(&A);
  }
}
END_TEST

START_TEST(test_calc_complements_5) {
  matrix_t A, goal, result;
  int error_code1 = my_create_matrix(1, 1, &A);
  int error_code2 = my_create_matrix(1, 1, &goal);

  if (error_code1 == OK && error_code2 == OK) {
    A.matrix[0][0] = 5;
    goal.matrix[0][0] = 1;

    int error_code_calc = my_calc_complements(&A, &result);
    ck_assert_int_eq(error_code_calc, OK);
    if (error_code_calc == OK) {
      int equal = my_eq_matrix(&goal, &result);
      ck_assert_int_eq(equal, SUCCESS);
      my_remove_matrix(&result);
    }
  }

  if (error_code1 == OK) my_remove_matrix(&A);
  if (error_code2 == OK) my_remove_matrix(&goal);
}
END_TEST

START_TEST(test_calc_complements_6) {
  matrix_t *A = NULL, result;
  int error_code_calc = my_calc_complements(A, &result);
  ck_assert_int_eq(error_code_calc, INCORRECT_MATRIX);
  if (error_code_calc == OK) my_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_7) {
  matrix_t A = {0}, result;
  int error_code_calc = my_calc_complements(&A, &result);
  ck_assert_int_eq(error_code_calc, INCORRECT_MATRIX);
  if (error_code_calc == OK) my_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_8) {
  matrix_t A, result;
  int error_code = my_create_matrix(1, 2, &A);

  if (error_code == OK) {
    int error_code_calc = my_calc_complements(&A, &result);
    ck_assert_int_eq(error_code_calc, CALCULATION_ERROR);
    if (error_code_calc == OK) my_remove_matrix(&result);
    my_remove_matrix(&A);
  }
}
END_TEST

TCase* tcase_my_calc_complements() {
  TCase* tcase = tcase_create("tcase_my_calc_complements");

  tcase_add_test(tcase, test_calc_complements_1);
  tcase_add_test(tcase, test_calc_complements_2);
  tcase_add_test(tcase, test_calc_complements_3);
  tcase_add_test(tcase, test_calc_complements_4);
  tcase_add_test(tcase, test_calc_complements_5);
  tcase_add_test(tcase, test_calc_complements_6);
  tcase_add_test(tcase, test_calc_complements_7);
  tcase_add_test(tcase, test_calc_complements_8);

  return tcase;
}
