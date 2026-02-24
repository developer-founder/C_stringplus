#include "s21_tests.h"

START_TEST(test_strlen_basic) {
  char str[] = "Hello";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_empty) {
  char str[] = "";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_long_string) {
  char str[] = "This is a very long string to test the function properly";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_special_chars) {
  char str[] = "Test\n\t\r\0";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_spaces) {
  char str[] = "   ";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_mixed_spaces) {
  char str[] = "  Hello World  ";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_numbers) {
  char str[] = "1234567890";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_alphanumeric) {
  char str[] = "Test123String456";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_one_char) {
  char str[] = "A";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_unicode) {
  char str[] = "Привет";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_null_in_middle) {
  char str[] = {'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'};

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_max_chars) {
  char str[1025];

  for (int i = 0; i < 1024; i++) {
    str[i] = 'A';
  }
  str[1024] = '\0';

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_repeated_char) {
  char str[] = "aaaaaaaaaaaaaaaaaaaa";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_pattern) {
  char str[] = "ABABABABABABABAB";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_whitespace_only) {
  char str[] = "\n\t\r ";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_punctuation) {
  char str[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_mixed_punctuation) {
  char str[] = "Hello, World! How are you?";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_escape_chars) {
  char str[] = "Line1\nLine2\tLine3\r";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_hex_chars) {
  char str[] = "\x48\x65\x6C\x6C\x6F";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_very_long) {
  char* str = malloc(10001);

  for (int i = 0; i < 10000; i++) {
    str[i] = 'A' + (i % 26);
  }
  str[10000] = '\0';

  ck_assert_int_eq(s21_strlen(str), strlen(str));

  free(str);
}
END_TEST

START_TEST(test_strlen_only_null) {
  char str[] = {'\0'};

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_concatenated) {
  char str1[] = "Hello";
  char str2[] = " World";
  char result[20];

  strcpy(result, str1);
  strcat(result, str2);

  ck_assert_int_eq(s21_strlen(result), strlen(result));
}
END_TEST

START_TEST(test_strlen_after_strncpy) {
  char src[] = "Hello";
  char dest[10];

  strncpy(dest, src, 5);
  dest[5] = '\0';

  ck_assert_int_eq(s21_strlen(dest), strlen(dest));
}
END_TEST

START_TEST(test_strlen_pointer_arithmetic) {
  char str[] = "Hello World";

  ck_assert_int_eq(s21_strlen(str + 6), strlen(str + 6));
}
END_TEST

START_TEST(test_strlen_const_string) {
  const char* str = "Constant String";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strlen_literal) {
  ck_assert_int_eq(s21_strlen("Test Literal"), strlen("Test Literal"));
}
END_TEST

Suite* s21_strlen_suites(void) {
  Suite* strlen_suite = suite_create("strlen_tests");

  TCase* all_strlen = tcase_create("Core");
  tcase_add_test(all_strlen, test_strlen_basic);
  tcase_add_test(all_strlen, test_strlen_empty);
  tcase_add_test(all_strlen, test_strlen_long_string);
  tcase_add_test(all_strlen, test_strlen_special_chars);
  tcase_add_test(all_strlen, test_strlen_spaces);
  tcase_add_test(all_strlen, test_strlen_mixed_spaces);
  tcase_add_test(all_strlen, test_strlen_numbers);
  tcase_add_test(all_strlen, test_strlen_alphanumeric);
  tcase_add_test(all_strlen, test_strlen_one_char);
  tcase_add_test(all_strlen, test_strlen_unicode);
  tcase_add_test(all_strlen, test_strlen_null_in_middle);
  tcase_add_test(all_strlen, test_strlen_max_chars);
  tcase_add_test(all_strlen, test_strlen_repeated_char);
  tcase_add_test(all_strlen, test_strlen_pattern);
  tcase_add_test(all_strlen, test_strlen_whitespace_only);
  tcase_add_test(all_strlen, test_strlen_punctuation);
  tcase_add_test(all_strlen, test_strlen_mixed_punctuation);
  tcase_add_test(all_strlen, test_strlen_escape_chars);
  tcase_add_test(all_strlen, test_strlen_hex_chars);
  tcase_add_test(all_strlen, test_strlen_very_long);
  tcase_add_test(all_strlen, test_strlen_only_null);
  tcase_add_test(all_strlen, test_strlen_concatenated);
  tcase_add_test(all_strlen, test_strlen_after_strncpy);
  tcase_add_test(all_strlen, test_strlen_pointer_arithmetic);
  tcase_add_test(all_strlen, test_strlen_const_string);
  tcase_add_test(all_strlen, test_strlen_literal);

  suite_add_tcase(strlen_suite, all_strlen);

  return strlen_suite;
}