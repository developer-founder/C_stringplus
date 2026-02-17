#include "s21_tests.h"

START_TEST(test_strncmp_basic_equal) {
    char str1[] = "Hello";
    char str2[] = "Hello";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_basic_not_equal) {
    char str1[] = "Hello";
    char str2[] = "World";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_partial_equal) {
    char str1[] = "Hello World";
    char str2[] = "Hello There";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_partial_not_equal) {
    char str1[] = "Hello World";
    char str2[] = "Hello There";

    ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

START_TEST(test_strncmp_zero_count) {
    char str1[] = "Hello";
    char str2[] = "World";

    ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(test_strncmp_empty_strings) {
    char str1[] = "";
    char str2[] = "";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_one_empty) {
    char str1[] = "";
    char str2[] = "Hello";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_other_empty) {
    char str1[] = "Hello";
    char str2[] = "";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_case_sensitive) {
    char str1[] = "Hello";
    char str2[] = "hello";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_special_chars) {
    char str1[] = "Test\n\t\r";
    char str2[] = "Test\n\t";

    ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

START_TEST(test_strncmp_unicode) {
    char str1[] = "Привет";
    char str2[] = "Пока";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_count_greater_than_strings) {
    char str1[] = "Hi";
    char str2[] = "Hi";

    ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(test_strncmp_count_greater_than_strings_diff) {
    char str1[] = "Hi";
    char str2[] = "Ha";

    ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(test_strncmp_different_length_equal_prefix) {
    char str1[] = "Hello";
    char str2[] = "Hello World";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_different_length_diff_prefix) {
    char str1[] = "Hello";
    char str2[] = "Help World";

    ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(test_strncspn_same_pointers) {
    char str[] = "Hello";

    ck_assert_int_eq(s21_strncmp(str, str, 5), strncmp(str, str, 5));
}
END_TEST

START_TEST(test_strncmp_nulls_in_middle) {
    char str1[] = {'H', 'e', '\0', 'l', 'o'};
    char str2[] = {'H', 'e', 'l', 'l', 'o'};

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_negative_result) {
    char str1[] = "Apple";
    char str2[] = "Banana";

    int result1 = s21_strncmp(str1, str2, 1);
    int result2 = strncmp(str1, str2, 1);

    ck_assert_int_eq(result1 < 0, result2 < 0);
}
END_TEST

START_TEST(test_strncmp_positive_result) {
    char str1[] = "Banana";
    char str2[] = "Apple";

    int result1 = s21_strncmp(str1, str2, 1);
    int result2 = strncmp(str1, str2, 1);

    ck_assert_int_eq(result1 > 0, result2 > 0);
}
END_TEST

START_TEST(test_strncspn_numbers) {
    char str1[] = "12345";
    char str2[] = "12340";

    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_mixed_alphanumeric) {
    char str1[] = "Test123";
    char str2[] = "Test456";

    ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

START_TEST(test_strncmp_spaces) {
    char str1[] = "Hello World";
    char str2[] = "Hello World";

    ck_assert_int_eq(s21_strncmp(str1, str2, 11), strncmp(str1, str2, 11));
}
END_TEST

Suite* s21_strncmp_suites(void) {
    Suite* strncmp_suite = suite_create("strncmp_tests");

    TCase* all_strncmp = tcase_create("strncmp");
    tcase_add_test(all_strncmp, test_strncmp_basic_equal);
    tcase_add_test(all_strncmp, test_strncmp_basic_not_equal);
    tcase_add_test(all_strncmp, test_strncmp_partial_equal);
    tcase_add_test(all_strncmp, test_strncmp_partial_not_equal);
    tcase_add_test(all_strncmp, test_strncmp_zero_count);
    tcase_add_test(all_strncmp, test_strncmp_empty_strings);
    tcase_add_test(all_strncmp, test_strncmp_one_empty);
    tcase_add_test(all_strncmp, test_strncmp_other_empty);
    tcase_add_test(all_strncmp, test_strncmp_case_sensitive);
    tcase_add_test(all_strncmp, test_strncmp_special_chars);
    tcase_add_test(all_strncmp, test_strncmp_unicode);
    tcase_add_test(all_strncmp, test_strncmp_count_greater_than_strings);
    tcase_add_test(all_strncmp, test_strncmp_count_greater_than_strings_diff);
    tcase_add_test(all_strncmp, test_strncmp_different_length_equal_prefix);
    tcase_add_test(all_strncmp, test_strncmp_different_length_diff_prefix);
    tcase_add_test(all_strncmp, test_strncspn_same_pointers);
    tcase_add_test(all_strncmp, test_strncmp_nulls_in_middle);
    tcase_add_test(all_strncmp, test_strncmp_negative_result);
    tcase_add_test(all_strncmp, test_strncmp_positive_result);
    tcase_add_test(all_strncmp, test_strncspn_numbers);
    tcase_add_test(all_strncmp, test_strncmp_mixed_alphanumeric);
    tcase_add_test(all_strncmp, test_strncmp_spaces);

    suite_add_tcase(strncmp_suite, all_strncmp);

    return strncmp_suite;
}