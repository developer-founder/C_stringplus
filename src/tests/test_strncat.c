#include "s21_tests.h"

START_TEST(test_strncat_basic) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = " World";

    s21_strncat(s21, src, 6);
    strncat(original, src, 6);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_partial_append) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = " World";

    s21_strncat(s21, src, 3);
    strncat(original, src, 3);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_zero_count) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = " World";

    s21_strncat(s21, src, 0);
    strncat(original, src, 0);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_empty_dest) {
    char s21[20] = "";
    char original[20] = "";
    char src[] = "Hello";

    s21_strncat(s21, src, 5);
    strncat(original, src, 5);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_empty_src) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = "";

    s21_strncat(s21, src, 5);
    strncat(original, src, 5);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_both_empty) {
    char s21[20] = "";
    char original[20] = "";
    char src[] = "";

    s21_strncat(s21, src, 5);
    strncat(original, src, 5);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_count_greater_than_src) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = "!!!";

    s21_strncat(s21, src, 5);
    strncat(original, src, 5);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_exact_buffer_size) {
    char s21[11] = "Hello";
    char original[11] = "Hello";
    char src[] = " World";

    s21_strncat(s21, src, 5);
    strncat(original, src, 5);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_special_chars) {
    char s21[20] = "Test";
    char original[20] = "Test";
    char src[] = "\n\t\r";

    s21_strncat(s21, src, 3);
    strncat(original, src, 3);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_numbers) {
    char s21[20] = "Number: ";
    char original[20] = "Number: ";
    char src[] = "12345";

    s21_strncat(s21, src, 3);
    strncat(original, src, 3);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_mixed_content) {
    char s21[30] = "Start: ";
    char original[30] = "Start: ";
    char src[] = "Middle123End";

    s21_strncat(s21, src, 10);
    strncat(original, src, 10);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_spaces) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = "   World";

    s21_strncat(s21, src, 8);
    strncat(original, src, 8);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_null_terminator_in_src) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = {'W', 'o', '\0', 'r', 'l', 'd', '\0'};

    s21_strncat(s21, src, 6);
    strncat(original, src, 6);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_large_count) {
    char s21[50] = "Start";
    char original[50] = "Start";
    char src[] = "Append";

    s21_strncat(s21, src, 20);
    strncat(original, src, 20);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_repeated) {
    char s21[30] = "A";
    char original[30] = "A";
    char src[] = "B";

    /* Добавляем несколько раз */
    s21_strncat(s21, src, 1);
    s21_strncat(s21, src, 1);
    s21_strncat(s21, src, 1);

    strncat(original, src, 1);
    strncat(original, src, 1);
    strncat(original, src, 1);

    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_case_sensitive) {
    char s21[20] = "Hello";
    char original[20] = "Hello";
    char src[] = "WORLD";

    s21_strncat(s21, src, 3);
    strncat(original, src, 3);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_buffer_boundary) {
    char s21[15] = "123456789";
    char original[15] = "123456789";
    char src[] = "abcdef";

    /* Буфер размером 15, уже занято 9 + '\0' = 10, осталось 5 */
    s21_strncat(s21, src, 5);
    strncat(original, src, 5);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_exact_fit) {
    char s21[12] = "Hello";  // 5 символов + '\0'
    char original[12] = "Hello";
    char src[] = " World";  // 6 символов

    /* s21 имеет размер 12, нужно 5 + 6 + '\0' = 12 */
    s21_strncat(s21, src, 6);
    strncat(original, src, 6);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncat_partial_null_terminator) {
    char s21[20] = "Test";
    char original[20] = "Test";
    char src[] = "String\0Extra";

    s21_strncat(s21, src, 10);
    strncat(original, src, 10);
    ck_assert_str_eq(s21, original);
}
END_TEST

Suite* strncat_suites(void) {
    Suite* strncat_suite = suite_create("strncat_tests");

    TCase* all_strncat = tcase_create("strncat");
    tcase_add_test(all_strncat, test_strncat_basic);
    tcase_add_test(all_strncat, test_strncat_partial_append);
    tcase_add_test(all_strncat, test_strncat_zero_count);
    tcase_add_test(all_strncat, test_strncat_empty_dest);
    tcase_add_test(all_strncat, test_strncat_empty_src);
    tcase_add_test(all_strncat, test_strncat_both_empty);
    tcase_add_test(all_strncat, test_strncat_count_greater_than_src);
    tcase_add_test(all_strncat, test_strncat_exact_buffer_size);
    tcase_add_test(all_strncat, test_strncat_special_chars);
    tcase_add_test(all_strncat, test_strncat_numbers);
    tcase_add_test(all_strncat, test_strncat_mixed_content);
    tcase_add_test(all_strncat, test_strncat_spaces);
    tcase_add_test(all_strncat, test_strncat_null_terminator_in_src);
    tcase_add_test(all_strncat, test_strncat_large_count);
    tcase_add_test(all_strncat, test_strncat_repeated);
    tcase_add_test(all_strncat, test_strncat_case_sensitive);
    tcase_add_test(all_strncat, test_strncat_buffer_boundary);
    tcase_add_test(all_strncat, test_strncat_exact_fit);
    tcase_add_test(all_strncat, test_strncat_partial_null_terminator);

    suite_add_tcase(strncat_suite, all_strncat);

    return strncat_suite;
}