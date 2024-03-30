#ifndef MY_MATRIX_TESTS
#define MY_MATRIX_TESTS

#include <check.h>

#include "../my_matrix.h"

TCase* tcase_my_create_matrix();
TCase* tcase_my_remove_matrix();
TCase* tcase_my_eq_matrix();
TCase* tcase_my_sum_matrix();
TCase* tcase_my_sub_matrix();
TCase* tcase_my_mult_number();
TCase* tcase_my_mult_matrix();
TCase* tcase_my_transpose();
TCase* tcase_my_calc_complements();
TCase* tcase_my_determinant();
TCase* tcase_my_inverse_matrix();

#endif  // MY_MATRIX_TESTS