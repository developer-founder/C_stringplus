#include "s21_tests.h"

START_TEST(test_strstr_basic_found) {
    char* haystack = "Hello, world!";
    char* needle = "world";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_at_beginning) {
    char* haystack = "Hello, world!";
    char* needle = "Hello";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, haystack);
}
END_TEST

START_TEST(test_strstr_at_end) {
    char* haystack = "Hello, world!";
    char* needle = "world!";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_not_found) {
    char* haystack = "Hello, world!";
    char* needle = "test";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strstr_empty_needle) {
    char* haystack = "Hello, world!";
    char* needle = "";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, haystack);
}
END_TEST

START_TEST(test_strstr_both_empty) {
    char* haystack = "";
    char* needle = "";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, haystack);
}
END_TEST

START_TEST(test_strstr_empty_haystack) {
    char* haystack = "";
    char* needle = "test";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strstr_multiple_occurrences) {
    char* haystack = "abababab";
    char* needle = "ab";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, haystack);  // Первое вхождение
}
END_TEST

START_TEST(test_strstr_overlapping) {
    char* haystack = "aaaaa";
    char* needle = "aa";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, haystack);  // Первое вхождение
}
END_TEST

START_TEST(test_strstr_partial_match) {
    char* haystack = "abcabd";
    char* needle = "abd";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result, haystack + 3);
}
END_TEST

START_TEST(test_strstr_almost_match) {
    char* haystack = "Hello, world!";
    char* needle = "world?";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strstr_needle_longer) {
    char* haystack = "abc";
    char* needle = "abcd";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strstr_with_spaces) {
    char* haystack = "Hello world test";
    char* needle = "world test";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_with_whitespace) {
    char* haystack = "Line1\nLine2\tLine3";
    char* needle = "\nLine2\t";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_with_null_byte) {
    char haystack[] = "Hello\0world";
    char* needle = "world";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strstr_case_sensitive) {
    char* haystack = "Hello WORLD";
    char* needle = "world";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_strstr_mixed_case) {
    char* haystack = "HeLLo WoRLd";
    char* needle = "Lo Wo";
    char* result = s21_strstr(haystack, needle);
    char* expected = strstr(haystack, needle);
    ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_very_long_needle) {
    char haystack[] = "short";
    char long_needle[1000];

    for (int i = 0; i < 999; i++) {
        long_needle[i] = 'a';
    }
    long_needle[999] = '\0';

    char* result = s21_strstr(haystack, long_needle);
    char* expected = strstr(haystack, long_needle);
    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_null(result);
}
END_TEST

Suite* strstr_suites(void) {
    Suite* strstr_suite = suite_create("strstr_tests");

    TCase* all_strstr = tcase_create("strstr");
    tcase_add_test(all_strstr, test_strstr_basic_found);
    tcase_add_test(all_strstr, test_strstr_at_beginning);
    tcase_add_test(all_strstr, test_strstr_at_end);
    tcase_add_test(all_strstr, test_strstr_not_found);
    tcase_add_test(all_strstr, test_strstr_empty_needle);
    tcase_add_test(all_strstr, test_strstr_both_empty);
    tcase_add_test(all_strstr, test_strstr_empty_haystack);
    tcase_add_test(all_strstr, test_strstr_multiple_occurrences);
    tcase_add_test(all_strstr, test_strstr_overlapping);
    tcase_add_test(all_strstr, test_strstr_partial_match);
    tcase_add_test(all_strstr, test_strstr_almost_match);
    tcase_add_test(all_strstr, test_strstr_needle_longer);
    tcase_add_test(all_strstr, test_strstr_with_spaces);
    tcase_add_test(all_strstr, test_strstr_with_whitespace);
    tcase_add_test(all_strstr, test_strstr_with_null_byte);
    tcase_add_test(all_strstr, test_strstr_case_sensitive);
    tcase_add_test(all_strstr, test_strstr_mixed_case);
    tcase_add_test(all_strstr, test_strstr_very_long_needle);

    suite_add_tcase(strstr_suite, all_strstr);

    return strstr_suite;
}