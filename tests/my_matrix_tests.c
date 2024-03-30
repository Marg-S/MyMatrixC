#include "my_matrix_tests.h"

int main() {
  Suite *my_matrix_suite = suite_create("my_matrix_suite");
  SRunner *my_matrix_runner = srunner_create(my_matrix_suite);

  TCase *my_matrix_tcase[11];
  my_matrix_tcase[0] = tcase_my_create_matrix();
  my_matrix_tcase[1] = tcase_my_remove_matrix();
  my_matrix_tcase[2] = tcase_my_eq_matrix();
  my_matrix_tcase[3] = tcase_my_sum_matrix();
  my_matrix_tcase[4] = tcase_my_sub_matrix();
  my_matrix_tcase[5] = tcase_my_mult_number();
  my_matrix_tcase[6] = tcase_my_mult_matrix();
  my_matrix_tcase[7] = tcase_my_transpose();
  my_matrix_tcase[8] = tcase_my_calc_complements();
  my_matrix_tcase[9] = tcase_my_determinant();
  my_matrix_tcase[10] = tcase_my_inverse_matrix();

  for (int i = 0; i < 11; i++)
    suite_add_tcase(my_matrix_suite, my_matrix_tcase[i]);

  srunner_run_all(my_matrix_runner, CK_NORMAL);
  int failed = srunner_ntests_failed(my_matrix_runner);
  srunner_free(my_matrix_runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
