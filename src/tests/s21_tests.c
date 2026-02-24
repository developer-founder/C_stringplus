#include "s21_tests.h"

#include "../s21_string.h"

int main(void) {
  int failed = 0;
  SRunner* sr = srunner_create(NULL);

  srunner_add_suite(sr, s21_insert_suites());
  srunner_add_suite(sr, s21_memchr_suites());
  srunner_add_suite(sr, s21_memcmp_suites());
  srunner_add_suite(sr, s21_memcpy_suites());
  srunner_add_suite(sr, s21_memset_suites());
  srunner_add_suite(sr, s21_strncat_suites());
  srunner_add_suite(sr, s21_strchr_suites());
  srunner_add_suite(sr, s21_strncmp_suites());
  srunner_add_suite(sr, s21_strncpy_suites());
  srunner_add_suite(sr, s21_strcspn_suites());
  srunner_add_suite(sr, s21_strerror_suites());
  srunner_add_suite(sr, s21_strlen_suites());
  srunner_add_suite(sr, s21_strpbrk_suites());
  srunner_add_suite(sr, s21_strrchr_suites());
  srunner_add_suite(sr, s21_strstr_suites());
  srunner_add_suite(sr, s21_strtok_suites());
  srunner_add_suite(sr, s21_sprintf_suites());
  srunner_add_suite(sr, s21_to_lower_suites());
  srunner_add_suite(sr, s21_to_upper_suites());
  srunner_add_suite(sr, s21_trim_suites());

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
