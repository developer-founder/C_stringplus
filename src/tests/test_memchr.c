#include "s21_tests.h"

START_TEST(test_memchr_basic_found) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, 'o', 11);
    void* original = memchr(str, 'o', 11);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_basic_not_found) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, 'z', 11);
    void* original = memchr(str, 'z', 11);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_first_char) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, 'H', 11);
    void* original = memchr(str, 'H', 11);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_last_char_in_range) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, 'd', 11);
    void* original = memchr(str, 'd', 11);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_char_after_range) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, 'd', 10);  // Ищем 'd' но только в первых 10 байтах
    void* original = memchr(str, 'd', 10);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_zero_bytes) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, 'H', 0);
    void* original = memchr(str, 'H', 0);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_null_byte_search) {
    char str[] = "Hello\0World";

    void* s21 = s21_memchr(str, '\0', 12);
    void* original = memchr(str, '\0', 12);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_middle_null) {
    char str[] = {'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'};

    void* s21 = s21_memchr(str, '\0', 12);
    void* original = memchr(str, '\0', 12);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_negative_char) {
    char str[] = "Hello";

    void* s21 = s21_memchr(str, -1, 5);
    void* original = memchr(str, -1, 5);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_large_char) {
    char str[] = "Hello";

    void* s21 = s21_memchr(str, 200, 5);
    void* original = memchr(str, 200, 5);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_int_array) {
    int arr[] = {1, 2, 3, 4, 5};
    int key = 3;

    void* s21 = s21_memchr(arr, key, 5 * sizeof(int));
    void* original = memchr(arr, key, 5 * sizeof(int));
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_struct) {
    struct test_struct {
        int a;
        char b;
        double c;
    } arr[3] = {{1, 'A', 1.1}, {2, 'B', 2.2}, {3, 'C', 3.3}};

    struct test_struct key = {2, 'B', 2.2};

    void* s21 = s21_memchr(arr, key.a, 3 * sizeof(struct test_struct));
    void* original = memchr(arr, key.a, 3 * sizeof(struct test_struct));
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_unsigned_chars) {
    unsigned char arr[] = {0, 128, 255, 127};

    void* s21 = s21_memchr(arr, 255, 4);
    void* original = memchr(arr, 255, 4);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_signed_chars) {
    signed char arr[] = {-128, -1, 0, 1, 127};

    void* s21 = s21_memchr(arr, -1, 5);
    void* original = memchr(arr, -1, 5);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_byte_pattern) {
    unsigned char arr[] = {0x00, 0x01, 0x02, 0x03, 0x04};

    void* s21 = s21_memchr(arr, 0x03, 5);
    void* original = memchr(arr, 0x03, 5);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_partial_search) {
    char str[] = "Hello World Hello World";

    // Ищем во второй половине строки
    void* s21 = s21_memchr(str + 12, 'W', 10);
    void* original = memchr(str + 12, 'W', 10);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_not_in_range) {
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Ищем 'Z' только в первых 10 символах
    void* s21 = s21_memchr(str, 'Z', 10);
    void* original = memchr(str, 'Z', 10);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_repeated_char) {
    char str[] = "aaaaabaaaa";

    // Ищем 'b' среди множества 'a'
    void* s21 = s21_memchr(str, 'b', 10);
    void* original = memchr(str, 'b', 10);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_exact_size) {
    char str[] = "Hello";

    // Ищем ровно в пределах строки
    void* s21 = s21_memchr(str, 'o', 5);
    void* original = memchr(str, 'o', 5);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_larger_than_size) {
    char str[] = "Hello";

    // Ищем за пределами фактической проверки
    void* s21 = s21_memchr(str, 'o', 10);
    void* original = memchr(str, 'o', 10);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_zero_value) {
    char str[] = "Hello";

    void* s21 = s21_memchr(str, 0, 5);
    void* original = memchr(str, 0, 5);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_space_char) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, ' ', 11);
    void* original = memchr(str, ' ', 11);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_case_sensitive) {
    char str[] = "Hello World";

    void* s21 = s21_memchr(str, 'h', 11);
    void* original = memchr(str, 'h', 11);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_double_array) {
    double arr[] = {1.1, 2.2, 3.3, 4.4};
    unsigned char search_byte = 0x66;  // Часть представления double

    void* s21 = s21_memchr(arr, search_byte, 4 * sizeof(double));
    void* original = memchr(arr, search_byte, 4 * sizeof(double));
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_mixed_data) {
    char data[] = {0x01, 'A', 0x02, 'B', 0x03, 'C', 0x00};

    void* s21 = s21_memchr(data, 'B', 7);
    void* original = memchr(data, 'B', 7);
    ck_assert_ptr_eq(s21, original);
}
END_TEST

START_TEST(test_memchr_alignment_test) {
    char buffer[64];

    // Заполняем паттерном
    for (int i = 0; i < 64; i++) {
        buffer[i] = i % 16;
    }

    // Ищем с разными выравниваниями
    for (int offset = 0; offset < 8; offset++) {
        void* s21 = s21_memchr(buffer + offset, 7, 32);
        void* original = memchr(buffer + offset, 7, 32);
        ck_assert_ptr_eq(s21, original);
    }
}
END_TEST

START_TEST(test_memchr_large_buffer) {
    char* buffer = malloc(1000);

    for (int i = 0; i < 1000; i++) {
        buffer[i] = i % 256;
    }

    // Ищем значение в конце буфера
    buffer[999] = 0xFF;

    void* s21 = s21_memchr(buffer, 0xFF, 1000);
    void* original = memchr(buffer, 0xFF, 1000);
    ck_assert_ptr_eq(s21, original);

    free(buffer);
}
END_TEST

Suite* memchr_suites(void) {
    Suite* memchr_suite = suite_create("memchr_tests");

    TCase* all_memchr = tcase_create("memchr");
    tcase_add_test(all_memchr, test_memchr_basic_found);
    tcase_add_test(all_memchr, test_memchr_basic_not_found);
    tcase_add_test(all_memchr, test_memchr_first_char);
    tcase_add_test(all_memchr, test_memchr_last_char_in_range);
    tcase_add_test(all_memchr, test_memchr_char_after_range);
    tcase_add_test(all_memchr, test_memchr_zero_bytes);
    tcase_add_test(all_memchr, test_memchr_null_byte_search);
    tcase_add_test(all_memchr, test_memchr_middle_null);
    tcase_add_test(all_memchr, test_memchr_negative_char);
    tcase_add_test(all_memchr, test_memchr_large_char);
    tcase_add_test(all_memchr, test_memchr_int_array);
    tcase_add_test(all_memchr, test_memchr_struct);
    tcase_add_test(all_memchr, test_memchr_unsigned_chars);
    tcase_add_test(all_memchr, test_memchr_signed_chars);
    tcase_add_test(all_memchr, test_memchr_byte_pattern);
    tcase_add_test(all_memchr, test_memchr_partial_search);
    tcase_add_test(all_memchr, test_memchr_not_in_range);
    tcase_add_test(all_memchr, test_memchr_repeated_char);
    tcase_add_test(all_memchr, test_memchr_exact_size);
    tcase_add_test(all_memchr, test_memchr_larger_than_size);
    tcase_add_test(all_memchr, test_memchr_zero_value);
    tcase_add_test(all_memchr, test_memchr_space_char);
    tcase_add_test(all_memchr, test_memchr_case_sensitive);
    tcase_add_test(all_memchr, test_memchr_double_array);
    tcase_add_test(all_memchr, test_memchr_mixed_data);
    tcase_add_test(all_memchr, test_memchr_alignment_test);
    tcase_add_test(all_memchr, test_memchr_large_buffer);

    suite_add_tcase(memchr_suite, all_memchr);

    return memchr_suite;
}