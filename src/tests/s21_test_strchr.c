#include "s21_tests.h"

START_TEST(test_strchr_basic_found) {
    char str[] = "Hello World";
    int ch = 'o';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_basic_not_found) {
    char str[] = "Hello World";
    int ch = 'z';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_first_char) {
    char str[] = "Hello World";
    int ch = 'H';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_last_char) {
    char str[] = "Hello World";
    int ch = 'd';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_multiple_occurrences) {
    char str[] = "Hello World";
    int ch = 'l';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_null_terminator) {
    char str[] = "Hello";
    int ch = '\0';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_empty_string) {
    char str[] = "";
    int ch = 'a';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_empty_string_null) {
    char str[] = "";
    int ch = '\0';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_special_chars) {
    char str[] = "Test\n\t\r";
    int ch = '\n';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_number_search) {
    char str[] = "123456789";
    int ch = '5';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_negative_char) {
    char str[] = "Hello";
    int ch = -1;

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_char_beyond_ascii) {
    char str[] = "Hello";
    int ch = 200;

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_zero_char) {
    char str[] = "Hello";
    int ch = 0;

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_middle_null) {
    char str[] = {'H', 'e', '\0', 'l', 'o', '\0'};
    int ch = 'l';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_only_target_char) {
    char str[] = "aaaaa";
    int ch = 'a';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_space) {
    char str[] = "Hello World";
    int ch = ' ';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_uppercase_lowercase) {
    char str[] = "Hello World";
    int ch = 'h';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_repeated_pattern) {
    char str[] = "abcabcabc";
    int ch = 'b';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_long_string) {
    char str[] = "This is a very long string with multiple characters to test the function";
    int ch = 't';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_strchr_numeric_zero) {
    char str[] = "0";
    int ch = '0';

    char* s21 = s21_strchr(str, ch);
    char* original = strchr(str, ch);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

Suite* s21_strchr_suites(void) {
    Suite* strchr_suite = suite_create("strchr_tests");

    TCase* all_strchr = tcase_create("strchr");
    tcase_add_test(all_strchr, test_strchr_basic_found);
    tcase_add_test(all_strchr, test_strchr_basic_not_found);
    tcase_add_test(all_strchr, test_strchr_first_char);
    tcase_add_test(all_strchr, test_strchr_last_char);
    tcase_add_test(all_strchr, test_strchr_multiple_occurrences);
    tcase_add_test(all_strchr, test_strchr_null_terminator);
    tcase_add_test(all_strchr, test_strchr_empty_string);
    tcase_add_test(all_strchr, test_strchr_empty_string_null);
    tcase_add_test(all_strchr, test_strchr_special_chars);
    tcase_add_test(all_strchr, test_strchr_number_search);
    tcase_add_test(all_strchr, test_strchr_negative_char);
    tcase_add_test(all_strchr, test_strchr_char_beyond_ascii);
    tcase_add_test(all_strchr, test_strchr_zero_char);
    tcase_add_test(all_strchr, test_strchr_middle_null);
    tcase_add_test(all_strchr, test_strchr_only_target_char);
    tcase_add_test(all_strchr, test_strchr_space);
    tcase_add_test(all_strchr, test_strchr_uppercase_lowercase);
    tcase_add_test(all_strchr, test_strchr_repeated_pattern);
    tcase_add_test(all_strchr, test_strchr_long_string);
    tcase_add_test(all_strchr, test_strchr_numeric_zero);

    suite_add_tcase(strchr_suite, all_strchr);

    return strchr_suite;
}