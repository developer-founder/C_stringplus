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
    char buffer2[256];
    char* s = "ello";
    int d = 123;

    int result1 = s21_sprintf(buffer, "H%s %%orld%d", s, d);
    int result2 = sprintf(buffer2, "H%s %%orld%d", s, d);

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
