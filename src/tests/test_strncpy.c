#include "s21_tests.h"

START_TEST(test_strncpy_basic) {
    char src[] = "Hello";
    char s21[20];
    char original[20];

    s21_strncpy(s21, src, 5);
    strncpy(original, src, 5);
    s21[5] = '\0';
    original[5] = '\0';
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncpy_empty) {
    char src[] = "";
    char s21[20];
    char original[20];

    s21_strncpy(s21, src, 5);
    strncpy(original, src, 5);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncpy_long) {
    char src[] = "This is a longer test string";
    char s21[50];
    char original[50];

    s21_strncpy(s21, src, 10);
    strncpy(original, src, 10);
    s21[10] = '\0';
    original[10] = '\0';
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncpy_special_chars) {
    char src[] = "Test\n\t\r";
    char s21[20];
    char original[20];

    s21_strncpy(s21, src, 7);
    strncpy(original, src, 7);
    s21[7] = '\0';
    original[7] = '\0';
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_strncpy_overwrite) {
    char src[] = "New";
    char s21[20] = "OldString";
    char original[20] = "OldString";

    s21_strncpy(s21, src, 3);
    strncpy(original, src, 3);
    /* strncpy не добавляет автоматически нуль-терминатор, если n <= strlen(src) */
    ck_assert_mem_eq(s21, original, 3);
    /* Проверяем, что остальная часть строки не изменилась */
    ck_assert_str_eq(s21 + 3, "String");
}
END_TEST

START_TEST(test_strncpy_empty_source) {
    char s21[10] = "abcdefghij";
    const char* src = "";
    char original[10] = "abcdefghij";

    s21_strncpy(s21, src, 5);
    strncpy(original, src, 5);

    // Первые 5 символов должны быть '\0'
    for (int i = 0; i < 5; i++) {
        ck_assert_int_eq(s21[i], '\0');
        ck_assert_int_eq(original[i], '\0');
    }
    // s21[5] и дальше не должны измениться
    ck_assert_int_eq(s21[5], 'f');
    ck_assert_int_eq(original[5], 'f');
}
END_TEST

START_TEST(test_strncpy_buffer_exact_size) {
    char s21[6];
    char original[6];
    const char* src = "Hello";

    s21_strncpy(s21, src, sizeof(s21));
    strncpy(original, src, sizeof(original));

    // Обе функции должны заполнить весь буфер, включая нуль-терминаторы
    ck_assert_mem_eq(s21, original, sizeof(s21));
    // s21[5] должен быть '\0' (последний элемент массива)
    ck_assert_int_eq(s21[5], '\0');
}
END_TEST

START_TEST(test_strncpy_s21_equals_src) {
    char buffer[20] = "Test";
    char buffer2[20] = "Test";

    s21_strncpy(buffer, buffer, 5);
    strncpy(buffer2, buffer2, 5);

    ck_assert_mem_eq(buffer, buffer2, 5);
}
END_TEST

START_TEST(test_strncpy_partial_overwrite) {
    char s21[20] = "Initial value";
    char original[20] = "Initial value";
    const char* src = "New";

    s21_strncpy(s21, src, 3);
    strncpy(original, src, 3);

    // Только первые 3 символа изменены
    ck_assert_mem_eq(s21, original, 20);
    ck_assert_mem_eq(s21, "Newial value", 11);
}
END_TEST

START_TEST(test_strncpy_zero_count) {
    char src[] = "Hello";
    char s21[20] = "Test";
    char original[20] = "Test";

    s21_strncpy(s21, src, 0);
    strncpy(original, src, 0);

    // s21 не должен измениться
    ck_assert_str_eq(s21, "Test");
    ck_assert_str_eq(original, "Test");
}
END_TEST

START_TEST(test_strncpy_count_greater_than_src) {
    char src[] = "Hello";
    char s21[20];
    char original[20];

    memset(s21, 'X', sizeof(s21));
    memset(original, 'X', sizeof(original));

    s21_strncpy(s21, src, 10);
    strncpy(original, src, 10);

    // Первые 5 символов - "Hello", остальные 5 - '\0'
    ck_assert_mem_eq(s21, original, 10);
    ck_assert_mem_eq(s21, "Hello", 5);
    for (int i = 5; i < 10; i++) {
        ck_assert_int_eq(s21[i], '\0');
    }
}
END_TEST

START_TEST(test_strncpy_exact_fit) {
    char src[] = "ABCD";
    char s21[5];
    char original[5];

    memset(s21, 'X', sizeof(s21));
    memset(original, 'X', sizeof(original));

    s21_strncpy(s21, src, 4);
    strncpy(original, src, 4);

    // s21[4] должен остаться 'X', так как n=4 не включает нуль-терминатор
    ck_assert_mem_eq(s21, original, 5);
    ck_assert_mem_eq(s21, "ABCD", 4);
    ck_assert_int_eq(s21[4], 'X');
}
END_TEST

START_TEST(test_strncpy_zero_length_with_null) {
    char src[] = {'\0', 'A', 'B', 'C'};
    char s21[10] = {0};
    char original[10] = {0};

    s21_strncpy(s21, src, 5);
    strncpy(original, src, 5);

    ck_assert_mem_eq(s21, original, 10);
    ck_assert_int_eq(s21[0], '\0');
    // Остальные 4 символа должны быть '\0'
    for (int i = 1; i < 5; i++) {
        ck_assert_int_eq(s21[i], '\0');
    }
}
END_TEST

START_TEST(test_strncpy_padding_zeros) {
    char src[] = "Hi";
    char s21[10];
    char original[10];

    memset(s21, 'A', sizeof(s21));
    memset(original, 'A', sizeof(original));

    s21_strncpy(s21, src, 5);
    strncpy(original, src, 5);

    // Проверяем что оставшиеся 3 байта заполнены нулями
    ck_assert_mem_eq(s21, original, 10);
    ck_assert_mem_eq(s21, "Hi", 2);
    for (int i = 2; i < 5; i++) {
        ck_assert_int_eq(s21[i], '\0');
    }
    // Позиции 5-9 должны остаться 'A'
    for (int i = 5; i < 10; i++) {
        ck_assert_int_eq(s21[i], 'A');
    }
}
END_TEST

Suite* strncpy_suites(void) {
    Suite* strncpy_suite = suite_create("strncpy_tests");

    TCase* all_strncpy = tcase_create("strncpy");
    tcase_add_test(all_strncpy, test_strncpy_basic);
    tcase_add_test(all_strncpy, test_strncpy_empty);
    tcase_add_test(all_strncpy, test_strncpy_long);
    tcase_add_test(all_strncpy, test_strncpy_special_chars);
    tcase_add_test(all_strncpy, test_strncpy_overwrite);
    tcase_add_test(all_strncpy, test_strncpy_empty_source);
    tcase_add_test(all_strncpy, test_strncpy_buffer_exact_size);
    tcase_add_test(all_strncpy, test_strncpy_s21_equals_src);
    tcase_add_test(all_strncpy, test_strncpy_partial_overwrite);
    tcase_add_test(all_strncpy, test_strncpy_zero_count);
    tcase_add_test(all_strncpy, test_strncpy_count_greater_than_src);
    tcase_add_test(all_strncpy, test_strncpy_exact_fit);
    tcase_add_test(all_strncpy, test_strncpy_zero_length_with_null);
    tcase_add_test(all_strncpy, test_strncpy_padding_zeros);

    suite_add_tcase(strncpy_suite, all_strncpy);

    return strncpy_suite;
}