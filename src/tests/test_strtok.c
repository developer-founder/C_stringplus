#include "s21_tests.h"

static void compare_tokens(const char* input, const char* delim) {
    char* s1 = strdup(input);
    char* s2 = strdup(input);

    ck_assert_ptr_nonnull(s1);
    ck_assert_ptr_nonnull(s2);

    char* t1 = strtok(s1, delim);
    char* t2 = s21_strtok(s2, delim);

    while (t1 != NULL || t2 != NULL) {
        ck_assert_ptr_nonnull(t1);
        ck_assert_ptr_nonnull(t2);
        ck_assert_str_eq(t1, t2);

        t1 = strtok(NULL, delim);
        t2 = s21_strtok(NULL, delim);
    }

    free(s1);
    free(s2);
}

START_TEST(test_simple_split) { compare_tokens("one two three", " "); }
END_TEST

START_TEST(test_multiple_delimiters) { compare_tokens("one,two;three:four", ",;:"); }
END_TEST

START_TEST(test_leading_trailing_delims) { compare_tokens("  hello world  ", " "); }
END_TEST

START_TEST(test_consecutive_delimiters) { compare_tokens("one,,,two,,three", ","); }
END_TEST

START_TEST(test_no_delimiters) { compare_tokens("hello", ","); }
END_TEST

START_TEST(test_only_delimiters) { compare_tokens(",,,,,", ","); }
END_TEST

START_TEST(test_empty_string) { compare_tokens("", " "); }
END_TEST

Suite* strtok_suites(void) {
    Suite* strtok_suite = suite_create("strtok_tests");

    TCase* all_strtok = tcase_create("strtok");
    tcase_add_test(all_strtok, test_simple_split);
    tcase_add_test(all_strtok, test_multiple_delimiters);
    tcase_add_test(all_strtok, test_leading_trailing_delims);
    tcase_add_test(all_strtok, test_consecutive_delimiters);
    tcase_add_test(all_strtok, test_no_delimiters);
    tcase_add_test(all_strtok, test_only_delimiters);
    tcase_add_test(all_strtok, test_empty_string);

    suite_add_tcase(strtok_suite, all_strtok);

    return strtok_suite;
}