#include "s21_tests.h"

START_TEST(test_strpbrk_basic) {
    char* str = "Hello, World!";
    ck_assert_ptr_eq(s21_strpbrk(str, " ,!"), strpbrk(str, " ,!"));
}
END_TEST

START_TEST(test_strpbrk_empty) {
    ck_assert_ptr_eq(s21_strpbrk("", "abc"), strpbrk("", "abc"));
    ck_assert_ptr_eq(s21_strpbrk("hello", ""), strpbrk("hello", ""));
    ck_assert_ptr_eq(s21_strpbrk("", ""), strpbrk("", ""));
}
END_TEST

START_TEST(test_strpbrk_first_char) {
    ck_assert_ptr_eq(s21_strpbrk("hello", "h"), strpbrk("hello", "h"));
    ck_assert_ptr_eq(s21_strpbrk("test", "t"), strpbrk("test", "t"));
}
END_TEST

START_TEST(test_strpbrk_last_char) { ck_assert_ptr_eq(s21_strpbrk("hello", "o"), strpbrk("hello", "o")); }
END_TEST

START_TEST(test_strpbrk_all_chars) {
    ck_assert_ptr_eq(s21_strpbrk("hello", "hello"), strpbrk("hello", "hello"));
}
END_TEST

START_TEST(test_strpbrk_special_chars) {
    ck_assert_ptr_eq(s21_strpbrk("line1\nline2", "\n"), strpbrk("line1\nline2", "\n"));
    ck_assert_ptr_eq(s21_strpbrk("line1\tline2", "\t"), strpbrk("line1\tline2", "\t"));
    ck_assert_ptr_eq(s21_strpbrk("line1\n\tline2", "\n\t"), strpbrk("line1\n\tline2", "\n\t"));
}
END_TEST

Suite* strpbrk_suites(void) {
    Suite* strpbrk_suite = suite_create("strpbrk_tests");

    TCase* all_strpbrk = tcase_create("strpbrk");
    tcase_add_test(all_strpbrk, test_strpbrk_basic);
    tcase_add_test(all_strpbrk, test_strpbrk_empty);
    tcase_add_test(all_strpbrk, test_strpbrk_first_char);
    tcase_add_test(all_strpbrk, test_strpbrk_last_char);
    tcase_add_test(all_strpbrk, test_strpbrk_all_chars);
    tcase_add_test(all_strpbrk, test_strpbrk_special_chars);

    suite_add_tcase(strpbrk_suite, all_strpbrk);

    return strpbrk_suite;
}

// добавить пару тестов