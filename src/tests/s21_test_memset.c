#include "s21_tests.h"

START_TEST(test_memset_basic) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1, '*', 5);
  memset(str2, '*', 5);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

START_TEST(test_memset_entire_string) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1, '*', 11);
  memset(str2, '*', 11);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

START_TEST(test_memset_zero_bytes) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1, '*', 0);
  memset(str2, '*', 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_memset_empty_buffer) {
  char str1[1] = "";
  char str2[1] = "";

  s21_memset(str1, 'A', 0);
  memset(str2, 'A', 0);
  ck_assert_mem_eq(str1, str2, 1);
}
END_TEST

START_TEST(test_memset_int_array) {
  int s21[5] = {1, 2, 3, 4, 5};
  int original[5] = {1, 2, 3, 4, 5};

  s21_memset(s21, 0, 5 * sizeof(int));
  memset(original, 0, 5 * sizeof(int));
  ck_assert_mem_eq(s21, original, 5 * sizeof(int));
}
END_TEST

START_TEST(test_memset_partial_int) {
  int s21[5] = {1, 2, 3, 4, 5};
  int original[5] = {1, 2, 3, 4, 5};

  s21_memset(s21, 0xFF, 2 * sizeof(int));
  memset(original, 0xFF, 2 * sizeof(int));
  ck_assert_mem_eq(s21, original, 5 * sizeof(int));
}
END_TEST

START_TEST(test_memset_null_character) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1, '\0', 5);
  memset(str2, '\0', 5);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

START_TEST(test_memset_negative_value) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1, -1, 5);
  memset(str2, -1, 5);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

START_TEST(test_memset_large_value) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1, 0x7F, 5);
  memset(str2, 0x7F, 5);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

START_TEST(test_memset_unsigned_char_overflow) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1, 300, 5);
  memset(str2, 300, 5);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

START_TEST(test_memset_complete_overwrite) {
  char str1[20];
  char str2[20];

  s21_memset(str1, 0xAA, 20);
  memset(str2, 0xAA, 20);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

START_TEST(test_memset_struct) {
  struct test_struct {
    int a;
    double b;
    char c[10];
  } s1, s2;

  s21_memset(&s1, 0, sizeof(struct test_struct));
  memset(&s2, 0, sizeof(struct test_struct));
  ck_assert_mem_eq(&s1, &s2, sizeof(struct test_struct));
}
END_TEST

START_TEST(test_memset_alignment_test) {
  char buffer1[64];
  char buffer2[64];

  for (int offset = 0; offset < 8; offset++) {
    s21_memset(buffer1 + offset, 0xCC, 32);
    memset(buffer2 + offset, 0xCC, 32);
    ck_assert_mem_eq(buffer1 + offset, buffer2 + offset, 32);
  }
}
END_TEST

START_TEST(test_memset_one_byte) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";

  s21_memset(str1 + 6, '!', 1);
  memset(str2 + 6, '!', 1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_memset_pattern) {
  char pattern[] = {0x00, 0x01, 0x02, 0x03, 0x04};
  char buffer1[100];
  char buffer2[100];

  for (int i = 0; i < 100; i++) {
    buffer1[i] = pattern[i % 5];
    buffer2[i] = pattern[i % 5];
  }

  s21_memset(buffer1 + 10, 0xFF, 20);
  memset(buffer2 + 10, 0xFF, 20);
  ck_assert_mem_eq(buffer1, buffer2, 100);
}
END_TEST

START_TEST(test_memset_zero_pattern) {
  char buffer1[50];
  char buffer2[50];

  for (int i = 0; i < 50; i++) {
    buffer1[i] = i + 1;
    buffer2[i] = i + 1;
  }

  s21_memset(buffer1, 0, 50);
  memset(buffer2, 0, 50);
  ck_assert_mem_eq(buffer1, buffer2, 50);
}
END_TEST

START_TEST(test_memset_compare_with_loop) {
  char buffer1[100];
  char buffer2[100];

  for (int i = 0; i < 100; i++) {
    buffer1[i] = 'X';
  }

  s21_memset(buffer2, 'X', 100);
  ck_assert_mem_eq(buffer1, buffer2, 100);
}
END_TEST

START_TEST(test_memset_boundary_conditions) {
  char buffer1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  char buffer2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  s21_memset(buffer1, 0, 10);
  memset(buffer2, 0, 10);
  ck_assert_mem_eq(buffer1, buffer2, 10);
}
END_TEST

START_TEST(test_memset_double_array) {
  double s21[10];
  double original[10];

  s21_memset(s21, 0, 10 * sizeof(double));
  memset(original, 0, 10 * sizeof(double));
  ck_assert_mem_eq(s21, original, 10 * sizeof(double));
}
END_TEST

START_TEST(test_memset_pointer_array) {
  void* ptrs1[5];
  void* ptrs2[5];

  s21_memset(ptrs1, 0, 5 * sizeof(void*));
  memset(ptrs2, 0, 5 * sizeof(void*));
  ck_assert_mem_eq(ptrs1, ptrs2, 5 * sizeof(void*));
}
END_TEST

Suite* s21_memset_suites(void) {
  Suite* memset_suite = suite_create("memset_tests");

  TCase* all_memset = tcase_create("memset");
  tcase_add_test(all_memset, test_memset_basic);
  tcase_add_test(all_memset, test_memset_entire_string);
  tcase_add_test(all_memset, test_memset_zero_bytes);
  tcase_add_test(all_memset, test_memset_empty_buffer);
  tcase_add_test(all_memset, test_memset_int_array);
  tcase_add_test(all_memset, test_memset_partial_int);
  tcase_add_test(all_memset, test_memset_null_character);
  tcase_add_test(all_memset, test_memset_negative_value);
  tcase_add_test(all_memset, test_memset_large_value);
  tcase_add_test(all_memset, test_memset_unsigned_char_overflow);
  tcase_add_test(all_memset, test_memset_complete_overwrite);
  tcase_add_test(all_memset, test_memset_struct);
  tcase_add_test(all_memset, test_memset_alignment_test);
  tcase_add_test(all_memset, test_memset_one_byte);
  tcase_add_test(all_memset, test_memset_pattern);
  tcase_add_test(all_memset, test_memset_zero_pattern);
  tcase_add_test(all_memset, test_memset_compare_with_loop);
  tcase_add_test(all_memset, test_memset_boundary_conditions);
  tcase_add_test(all_memset, test_memset_double_array);
  tcase_add_test(all_memset, test_memset_pointer_array);

  suite_add_tcase(memset_suite, all_memset);

  return memset_suite;
}