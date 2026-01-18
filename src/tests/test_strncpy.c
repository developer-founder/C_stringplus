#include "s21_tests.h"

START_TEST(test_strncpy_basic) {
    char dest[20];
    const char* src = "Hello World";

    char* result = s21_strncpy(dest, src, 12);

    ck_assert_ptr_eq(result, dest);
    ck_assert_str_eq(dest, "Hello World");
    ck_assert_int_eq(dest[11], '\0');  // Нуль-терминатор
}
END_TEST

START_TEST(test_strncpy_exact_length) {
    char dest[10];
    const char* src = "123456789";

    s21_strncpy(dest, src, 10);

    // Все 9 символов + нуль-терминатор
    ck_assert_str_eq(dest, "123456789");
}
END_TEST

START_TEST(test_strncpy_zero_count) {
    char dest[10] = "abcdefghij";
    const char* src = "Hello";
    char original[10];
    memcpy(original, dest, 10);

    char* result = s21_strncpy(dest, src, 0);

    ck_assert_ptr_eq(result, dest);
    // dest не должен измениться при n = 0
    ck_assert_mem_eq(dest, original, 10);
}
END_TEST

START_TEST(test_strncpy_empty_source) {
    char dest[10] = "abcdefghij";
    const char* src = "";

    s21_strncpy(dest, src, 5);

    // Первый символ должен быть '\0', остальные заполнены нулями до n
    ck_assert_int_eq(dest[0], '\0');
    ck_assert_int_eq(dest[1], '\0');
    ck_assert_int_eq(dest[2], '\0');
    ck_assert_int_eq(dest[3], '\0');
    ck_assert_int_eq(dest[4], '\0');
    // dest[5] и дальше не должны измениться
    ck_assert_int_eq(dest[5], 'f');
}
END_TEST

START_TEST(test_strncpy_buffer_exact_size) {
    char dest[6];
    const char* src = "Hello";

    // Правильное использование: n = sizeof(dest)
    s21_strncpy(dest, src, sizeof(dest));

    // dest теперь гарантированно нуль-терминирован
    ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_strncpy_dest_equals_src) {
    char buffer[20] = "Test";

    // Копирование в себя - технически разрешено если нет перекрытия
    strncpy(buffer, buffer, 5);

    ck_assert_str_eq(buffer, "Test");
}
END_TEST

START_TEST(test_strncpy_partial_overwrite) {
    char dest[20] = "Initial value";
    const char* src = "New";

    strncpy(dest, src, 3);

    // Только первые 3 символа изменены
    ck_assert_mem_eq(dest, "Newial value", 12);
}
END_TEST

Suite* strncpy_suites(void) {
    Suite* strncpy_suite = suite_create("strncpy_tests");

    TCase* all_strncpy = tcase_create("strncpy");
    tcase_add_test(all_strncpy, test_strncpy_basic);
    tcase_add_test(all_strncpy, test_strncpy_exact_length);
    tcase_add_test(all_strncpy, test_strncpy_zero_count);
    tcase_add_test(all_strncpy, test_strncpy_empty_source);
    tcase_add_test(all_strncpy, test_strncpy_buffer_exact_size);
    tcase_add_test(all_strncpy, test_strncpy_dest_equals_src);
    tcase_add_test(all_strncpy, test_strncpy_partial_overwrite);

    suite_add_tcase(strncpy_suite, all_strncpy);

    return strncpy_suite;
}