#include "s21_tests.h"

START_TEST(test_memcpy_basic) {
    char src[] = "Hello World";
    char s21[20] = {0};
    char original[20] = {0};

    s21_memcpy(s21, src, 12);
    memcpy(original, src, 12);
    ck_assert_mem_eq(s21, original, 20);
}
END_TEST

START_TEST(test_memcpy_partial_copy) {
    char src[] = "Hello World";
    char s21[20] = {0};
    char original[20] = {0};

    s21_memcpy(s21, src, 5);
    memcpy(original, src, 5);
    ck_assert_mem_eq(s21, original, 20);
}
END_TEST

START_TEST(test_memcpy_zero_bytes) {
    char src[] = "Hello World";
    char s21[20] = "Test";
    char original[20] = "Test";

    s21_memcpy(s21, src, 0);
    memcpy(original, src, 0);
    ck_assert_str_eq(s21, "Test");
    ck_assert_str_eq(original, "Test");
}
END_TEST

START_TEST(test_memcpy_int_array) {
    int src[] = {1, 2, 3, 4, 5};
    int s21[5];
    int original[5];

    s21_memcpy(s21, src, 5 * sizeof(int));
    memcpy(original, src, 5 * sizeof(int));
    ck_assert_mem_eq(s21, original, 5 * sizeof(int));
}
END_TEST

START_TEST(test_memcpy_struct) {
    struct test_struct {
        int a;
        double b;
        char c[10];
    } src = {42, 3.14, "Hello"};

    struct test_struct s21;
    struct test_struct original;

    s21_memcpy(&s21, &src, sizeof(struct test_struct));
    memcpy(&original, &src, sizeof(struct test_struct));
    ck_assert_mem_eq(&s21, &original, sizeof(struct test_struct));
}
END_TEST

START_TEST(test_memcpy_overlap_dest_before_src) {
    char buffer[] = "1234567890";
    char buffer2[] = "1234567890";

    /* Копирование со смещением назад */
    s21_memcpy(buffer, buffer + 3, 5);
    memcpy(buffer2, buffer2 + 3, 5);
    ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_memcpy_exact_buffer) {
    char src[] = "12345";
    char s21[6];
    char original[6];

    s21_memcpy(s21, src, 6);
    memcpy(original, src, 6);
    ck_assert_mem_eq(s21, original, 6);
}
END_TEST

START_TEST(test_memcpy_large_buffer) {
    char src[1024];
    char s21[1024];
    char original[1024];

    /* Заполняем паттерном */
    for (int i = 0; i < 1024; i++) {
        src[i] = i % 256;
    }

    s21_memcpy(s21, src, 1024);
    memcpy(original, src, 1024);
    ck_assert_mem_eq(s21, original, 1024);
}
END_TEST

START_TEST(test_memcpy_one_byte) {
    char src[] = "Hello";
    char s21[10] = "World";
    char original[10] = "World";

    s21_memcpy(s21, src, 1);
    memcpy(original, src, 1);
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_memcpy_aligned_data) {
    /* Тест с выровненными данными */
    int src[16];
    int s21[16];
    int original[16];

    for (int i = 0; i < 16; i++) {
        src[i] = i * i;
    }

    s21_memcpy(s21, src, 16 * sizeof(int));
    memcpy(original, src, 16 * sizeof(int));
    ck_assert_mem_eq(s21, original, 16 * sizeof(int));
}
END_TEST

START_TEST(test_memcpy_unaligned_data) {
    /* Тест с невыровненными данными */
    char data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }

    char s21[100];
    char original[100];

    /* Копируем с невыровненного адреса */
    s21_memcpy(s21, data + 3, 50);
    memcpy(original, data + 3, 50);
    ck_assert_mem_eq(s21, original, 50);
}
END_TEST

START_TEST(test_memcpy_same_pointers) {
    char buffer[] = "Test String";

    /* Копирование в себя */
    s21_memcpy(buffer, buffer, 11);
    ck_assert_str_eq(buffer, "Test String");
}
END_TEST

START_TEST(test_memcpy_double_array) {
    double src[10];
    double s21[10];
    double original[10];

    for (int i = 0; i < 10; i++) {
        src[i] = i * 1.5;
    }

    s21_memcpy(s21, src, 10 * sizeof(double));
    memcpy(original, src, 10 * sizeof(double));
    ck_assert_mem_eq(s21, original, 10 * sizeof(double));
}
END_TEST

START_TEST(test_memcpy_pointer_array) {
    int a = 1, b = 2, c = 3;
    int* src[] = {&a, &b, &c};
    int* s21[3];
    int* original[3];

    s21_memcpy(s21, src, 3 * sizeof(int*));
    memcpy(original, src, 3 * sizeof(int*));
    ck_assert_mem_eq(s21, original, 3 * sizeof(int*));
}
END_TEST

START_TEST(test_memcpy_bit_field) {
    /* Тест с битовыми полями */
    struct bitfield {
        unsigned int a : 4;
        unsigned int b : 4;
        unsigned int c : 8;
    } src = {5, 10, 255};

    struct bitfield s21;
    struct bitfield original;

    s21_memcpy(&s21, &src, sizeof(struct bitfield));
    memcpy(&original, &src, sizeof(struct bitfield));
    ck_assert_int_eq(s21.a, original.a);
    ck_assert_int_eq(s21.b, original.b);
    ck_assert_int_eq(s21.c, original.c);
}
END_TEST

START_TEST(test_memcpy_mixed_types) {
    /* Тест со смешанными типами в одном буфере */
    char buffer1[50];
    char buffer2[50];

    int int_val = 0x12345678;
    double double_val = 3.14159;
    char str[] = "Hello";

    /* Заполняем буфер смешанными данными */
    memcpy(buffer1, &int_val, sizeof(int));
    memcpy(buffer1 + sizeof(int), &double_val, sizeof(double));
    memcpy(buffer1 + sizeof(int) + sizeof(double), str, 6);

    s21_memcpy(buffer2, buffer1, 50);
    ck_assert_mem_eq(buffer1, buffer2, 50);
}
END_TEST

START_TEST(test_memcpy_boundary) {
    /* Тест граничных условий */
    char src[] = "ABCDEFGHIJ";
    char s21[15];
    char original[15];

    /* Копируем все кроме нуль-терминатора */
    s21_memcpy(s21, src, 10);
    memcpy(original, src, 10);
    ck_assert_mem_eq(s21, original, 10);

    /* Добавляем нуль-терминатор */
    s21[10] = '\0';
    original[10] = '\0';
    ck_assert_str_eq(s21, original);
}
END_TEST

START_TEST(test_memcpy_performance_pattern) {
    /* Паттерн для проверки производительности */
    char pattern[] = {0x00, 0xFF, 0x55, 0xAA};
    char src[256];
    char s21[256];
    char original[256];

    /* Заполняем повторяющимся паттерном */
    for (int i = 0; i < 256; i++) {
        src[i] = pattern[i % 4];
    }

    s21_memcpy(s21, src, 256);
    memcpy(original, src, 256);
    ck_assert_mem_eq(s21, original, 256);
}
END_TEST

Suite* memcpy_suites(void) {
    Suite* memcpy_suite = suite_create("memcpy_tests");

    TCase* all_memcpy = tcase_create("memcpy");
    tcase_add_test(all_memcpy, test_memcpy_basic);
    tcase_add_test(all_memcpy, test_memcpy_partial_copy);
    tcase_add_test(all_memcpy, test_memcpy_zero_bytes);
    tcase_add_test(all_memcpy, test_memcpy_int_array);
    tcase_add_test(all_memcpy, test_memcpy_struct);
    tcase_add_test(all_memcpy, test_memcpy_overlap_dest_before_src);
    tcase_add_test(all_memcpy, test_memcpy_exact_buffer);
    tcase_add_test(all_memcpy, test_memcpy_large_buffer);
    tcase_add_test(all_memcpy, test_memcpy_one_byte);
    tcase_add_test(all_memcpy, test_memcpy_aligned_data);
    tcase_add_test(all_memcpy, test_memcpy_unaligned_data);
    tcase_add_test(all_memcpy, test_memcpy_same_pointers);
    tcase_add_test(all_memcpy, test_memcpy_double_array);
    tcase_add_test(all_memcpy, test_memcpy_pointer_array);
    tcase_add_test(all_memcpy, test_memcpy_bit_field);
    tcase_add_test(all_memcpy, test_memcpy_mixed_types);
    tcase_add_test(all_memcpy, test_memcpy_boundary);
    tcase_add_test(all_memcpy, test_memcpy_performance_pattern);

    suite_add_tcase(memcpy_suite, all_memcpy);

    return memcpy_suite;
}