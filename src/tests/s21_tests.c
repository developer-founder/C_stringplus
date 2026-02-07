#include "s21_tests.h"
#include "../s21_string.h"

int main(void) {
    int failed = 0;
    SRunner* sr = srunner_create(NULL);

    srunner_add_suite(sr, memchr_suites());
    srunner_add_suite(sr, memcmp_suites());
    srunner_add_suite(sr, memcpy_suites());
    srunner_add_suite(sr, memset_suites());
    srunner_add_suite(sr, strncat_suites());
    srunner_add_suite(sr, strchr_suites());
    srunner_add_suite(sr, strncmp_suites());
    srunner_add_suite(sr, strncpy_suites());
    srunner_add_suite(sr, strcspn_suites());
    srunner_add_suite(sr, strerror_suites());
    srunner_add_suite(sr, strlen_suites());
    srunner_add_suite(sr, strpbrk_suites());
    srunner_add_suite(sr, strrchr_suites());
    srunner_add_suite(sr, strstr_suites());
    srunner_add_suite(sr, strtok_suites());

    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    char buffer[256];
    int d = -123;

    s21_sprintf(buffer, "He%d %%orld", d);

    if (strcmp(buffer, "He-123 %orld") == 0) {
        printf("TEST PASSED\n");
        printf("Expected: He-123 %%orld\n");
        printf("Got: %s\n", buffer);
    } else {
        printf("TEST FAILED\n");
        printf("Expected: He-123 %%orld\n");
        printf("Got: %s\n", buffer);
    }

    return failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
