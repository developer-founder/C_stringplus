#include "s21_tests.h"
#include "../s21_string.h"

int main(void) {
    int failed = 0;
    SRunner* sr = srunner_create(NULL);

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

    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    char buffer[256];
    char buffer2[256];
    char* s = "ello";
    double d = -123.1231239;

    int result1 = s21_sprintf(buffer, "H%s %%orld%f", s, d);
    int result2 = sprintf(buffer2, "H%s %%orld%f", s, d);

    if (strcmp(buffer, buffer2) == 0) {
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
    printf("Expected: %s\n", buffer2);
    printf("Got: %s\n", buffer);

    if (result1 == result2) {
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
    printf("Expected: %d\n", result2);
    printf("Got: %d\n", result1);

    return failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
