#include "s21_tests.h"

START_TEST(test_strcspn_last_char) {
    char* str = "Hello, world!";
    char* substr = "!";

    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

START_TEST(test_strcspn_first_char) {
    char* str = "Hello";
    char* substr = "H";

    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

START_TEST(test_strcspn_no_match) {
    char* str = "Hello World";
    char* substr = "xyz";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

START_TEST(test_strcspn_empty_substr) {
    char* str = "Hello";
    char* substr = "";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

START_TEST(test_strcspn_both_empty) {
    char* str = "";
    char* substr = "";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

// тесты на регистр
START_TEST(test_strcspn_case_sensitive_no_match) {
    char* str = "Hello";
    char* substr = "HELLO";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

START_TEST(test_strcspn_mixed_case) {
    char* str = "Hello World";
    char* substr = "lw";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

// повторяющиеся символы
START_TEST(test_strcspn_duplicate_in_substr) {
    char* str = "Hello";
    char* substr = "lll";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

START_TEST(test_strcspn_multiple_matches) {
    char* str = "banana";
    char* substr = "na";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

// длинная строка
START_TEST(test_strcspn_long_strings) {
    char str[1000];
    char substr[100];

    memset(str, 'a', 999);
    str[999] = '\0';

    memset(substr, 'b', 99);
    substr[99] = '\0';

    ck_assert_int_eq(s21_strcspn(str, substr), strlen(str));
}
END_TEST

START_TEST(test_strcspn_all_match) {
    char* str = "aaaaa";
    char* substr = "a";
    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

START_TEST(test_strcspn_large_substr) {
    char* str = "Hello World";
    char substr[256];

    for (int i = 0; i < 255; i++) {
        substr[i] = (char)(i + 1);
    }
    substr[255] = '\0';

    ck_assert_int_eq(s21_strcspn(str, substr), strcspn(str, substr));
}
END_TEST

Suite* strcspn_suites(void) {
    Suite* strcspn_suite = suite_create("string_tests");

    TCase* all_strcspn = tcase_create("strcspn");
    tcase_add_test(all_strcspn, test_strcspn_last_char);
    tcase_add_test(all_strcspn, test_strcspn_first_char);
    tcase_add_test(all_strcspn, test_strcspn_no_match);
    tcase_add_test(all_strcspn, test_strcspn_empty_substr);
    tcase_add_test(all_strcspn, test_strcspn_both_empty);
    tcase_add_test(all_strcspn, test_strcspn_case_sensitive_no_match);
    tcase_add_test(all_strcspn, test_strcspn_mixed_case);
    tcase_add_test(all_strcspn, test_strcspn_duplicate_in_substr);
    tcase_add_test(all_strcspn, test_strcspn_multiple_matches);
    tcase_add_test(all_strcspn, test_strcspn_long_strings);
    tcase_add_test(all_strcspn, test_strcspn_all_match);
    tcase_add_test(all_strcspn, test_strcspn_large_substr);

    suite_add_tcase(strcspn_suite, all_strcspn);

    return strcspn_suite;
}