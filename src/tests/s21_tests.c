#include "s21_tests.h"

START_TEST(test_strcspn) {
    char* test = "Hello, world!";
    char* substr = "syeta";

    size_t s21_result = s21_strcspn(test, substr);
    size_t result = strcspn(test, substr);

    ck_assert_int_eq(s21_result, result);
}
END_TEST

Suite* string_suites(void) {
    Suite* string_suite = suite_create("string_tests");

    TCase* all_strcspn = tcase_create("strcspn");
    tcase_add_test(all_strcspn, test_strcspn);

    suite_add_tcase(string_suite, all_strcspn);

    return string_suite;
}

int main(void) {
    int failed = 0;
    Suite* s = string_suites();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
