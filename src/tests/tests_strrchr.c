#include "s21_tests.h"

START_TEST(test_strrchr_basic) {
    char* str = "Hello, world!";
    int ch = 'o';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strrchr_first_char) {
    char* str = "Hello";
    int ch = 'H';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strrchr_last_char) {
    char* str = "Hello";
    int ch = 'o';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strrchr_multiple_occurrences) {
    char* str = "Hello, world! Hello!";
    int ch = 'l';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, str + 17);
}
END_TEST

START_TEST(test_strrchr_not_found) {
    char* str = "Hello, world!";
    int ch = 'z';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strrchr_null_terminator) {
    char* str = "Hello";
    int ch = '\0';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, str + 5);
}
END_TEST

START_TEST(test_strrchr_empty_string_null_char) {
    char* str = "";
    int ch = '\0';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, str);
}
END_TEST

START_TEST(test_strrchr_empty_string) {
    char* str = "";
    int ch = 'a';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strrchr_tab) {
    char* str = "Hello\tworld\t\tend";
    int ch = '\t';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strrchr_newline) {
    char* str = "Line1\nLine2\nLine3";
    int ch = '\n';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strrchr_digit) {
    char* str = "test123test456";
    int ch = '3';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strrchr_zero_digit) {
    char* str = "test102030";
    int ch = '0';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, str + 9);
}
END_TEST

START_TEST(test_strrchr_case_sensitive) {
    char* str = "Hello World HELLO";
    int ch = 'H';
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, str + 12);
}
END_TEST

START_TEST(test_strrchr_negative_char) {
    char* str = "Hello\xFFWorld";
    int ch = -1;
    char* result = s21_strrchr(str, ch);
    char* expected = strrchr(str, ch);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite* strrchr_suites(void) {
    Suite* strrchr_suite = suite_create("strrchr_tests");

    TCase* all_strrchr = tcase_create("strrchr");
    tcase_add_test(all_strrchr, test_strrchr_basic);
    tcase_add_test(all_strrchr, test_strrchr_first_char);
    tcase_add_test(all_strrchr, test_strrchr_last_char);
    tcase_add_test(all_strrchr, test_strrchr_multiple_occurrences);
    tcase_add_test(all_strrchr, test_strrchr_not_found);
    tcase_add_test(all_strrchr, test_strrchr_null_terminator);
    tcase_add_test(all_strrchr, test_strrchr_empty_string_null_char);
    tcase_add_test(all_strrchr, test_strrchr_empty_string);
    tcase_add_test(all_strrchr, test_strrchr_tab);
    tcase_add_test(all_strrchr, test_strrchr_newline);
    tcase_add_test(all_strrchr, test_strrchr_digit);
    tcase_add_test(all_strrchr, test_strrchr_zero_digit);
    tcase_add_test(all_strrchr, test_strrchr_case_sensitive);
    tcase_add_test(all_strrchr, test_strrchr_negative_char);

    suite_add_tcase(strrchr_suite, all_strrchr);

    return strrchr_suite;
}