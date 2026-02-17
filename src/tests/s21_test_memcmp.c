#include "s21_tests.h"

START_TEST(test_memcmp_basic_equal) {
    char str1[] = "Hello World";
    char str2[] = "Hello World";

    ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

START_TEST(test_memcmp_basic_not_equal) {
    char str1[] = "Hello World";
    char str2[] = "Hello There";

    ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

START_TEST(test_memcmp_partial_equal) {
    char str1[] = "Hello World";
    char str2[] = "Hello There";

    ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_memcmp_zero_bytes) {
    char str1[] = "Hello";
    char str2[] = "World";

    ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(test_memcmp_int_array_equal) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 5 * sizeof(int)), memcmp(arr1, arr2, 5 * sizeof(int)));
}
END_TEST

START_TEST(test_memcmp_int_array_not_equal) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 9, 5};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 5 * sizeof(int)), memcmp(arr1, arr2, 5 * sizeof(int)));
}
END_TEST

START_TEST(test_memcmp_struct_equal) {
    struct test_struct {
        int a;
        double b;
        char c[10];
    } s1 = {42, 3.14, "Hello"};
    struct test_struct s2 = {42, 3.14, "Hello"};

    ck_assert_int_eq(s21_memcmp(&s1, &s2, sizeof(struct test_struct)),
                     memcmp(&s1, &s2, sizeof(struct test_struct)));
}
END_TEST

START_TEST(test_memcmp_struct_not_equal) {
    struct test_struct {
        int a;
        double b;
        char c[10];
    } s1 = {42, 3.14, "Hello"};
    struct test_struct s2 = {42, 3.14, "World"};

    ck_assert_int_eq(s21_memcmp(&s1, &s2, sizeof(struct test_struct)),
                     memcmp(&s1, &s2, sizeof(struct test_struct)));
}
END_TEST

START_TEST(test_memcmp_negative_result) {
    char str1[] = "Apple";
    char str2[] = "Banana";

    int result1 = s21_memcmp(str1, str2, 1);
    int result2 = memcmp(str1, str2, 1);

    ck_assert_int_eq((result1 < 0), (result2 < 0));
}
END_TEST

START_TEST(test_memcmp_positive_result) {
    char str1[] = "Banana";
    char str2[] = "Apple";

    int result1 = s21_memcmp(str1, str2, 1);
    int result2 = memcmp(str1, str2, 1);

    ck_assert_int_eq((result1 > 0), (result2 > 0));
}
END_TEST

START_TEST(test_memcmp_difference_in_middle) {
    char str1[] = "ABCDEFG";
    char str2[] = "ABCxEFG";

    ck_assert_int_eq(s21_memcmp(str1, str2, 7), memcmp(str1, str2, 7));
}
END_TEST

START_TEST(test_memcmp_difference_at_start) {
    char str1[] = "Hello";
    char str2[] = "Jello";

    ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_memcmp_difference_at_end) {
    char str1[] = "Hello";
    char str2[] = "Hellp";

    ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_memcmp_signed_chars) {
    signed char arr1[] = {-128, -1, 0, 1, 127};
    signed char arr2[] = {-128, -1, 0, 1, 127};
    signed char arr3[] = {-128, -1, 0, 1, 126};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 5), memcmp(arr1, arr2, 5));

    ck_assert_int_eq(s21_memcmp(arr1, arr3, 5), memcmp(arr1, arr3, 5));
}
END_TEST

START_TEST(test_memcmp_unsigned_chars) {
    unsigned char arr1[] = {0, 128, 255};
    unsigned char arr2[] = {0, 128, 255};
    unsigned char arr3[] = {0, 128, 254};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 3), memcmp(arr1, arr2, 3));

    ck_assert_int_eq(s21_memcmp(arr1, arr3, 3), memcmp(arr1, arr3, 3));
}
END_TEST

START_TEST(test_memcmp_null_chars_in_middle) {
    char arr1[] = {'A', 'B', '\0', 'D', 'E'};
    char arr2[] = {'A', 'B', '\0', 'D', 'E'};
    char arr3[] = {'A', 'B', 'C', 'D', 'E'};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 5), memcmp(arr1, arr2, 5));
    ck_assert_int_eq(s21_memcmp(arr1, arr3, 5), memcmp(arr1, arr3, 5));
}
END_TEST

START_TEST(test_memcmp_same_pointers) {
    char str[] = "Hello World";

    ck_assert_int_eq(s21_memcmp(str, str, 11), memcmp(str, str, 11));
}
END_TEST

START_TEST(test_memcmp_double_array) {
    double arr1[] = {1.1, 2.2, 3.3};
    double arr2[] = {1.1, 2.2, 3.3};
    double arr3[] = {1.1, 2.2, 3.4};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 3 * sizeof(double)), memcmp(arr1, arr2, 3 * sizeof(double)));

    ck_assert_int_eq(s21_memcmp(arr1, arr3, 3 * sizeof(double)), memcmp(arr1, arr3, 3 * sizeof(double)));
}
END_TEST

START_TEST(test_memcmp_one_byte) {
    char a = 'A';
    char b = 'B';
    char c = 'A';

    ck_assert_int_eq(s21_memcmp(&a, &b, 1), memcmp(&a, &b, 1));
    ck_assert_int_eq(s21_memcmp(&a, &c, 1), memcmp(&a, &c, 1));
}
END_TEST

START_TEST(test_memcmp_large_memory) {
    char* arr1 = malloc(1000);
    char* arr2 = malloc(1000);

    for (int i = 0; i < 1000; i++) {
        arr1[i] = i % 256;
        arr2[i] = i % 256;
    }

    arr2[500] = arr1[500] + 1;

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 1000), memcmp(arr1, arr2, 1000));

    free(arr1);
    free(arr2);
}
END_TEST

START_TEST(test_memcmp_bit_difference) {
    unsigned char arr1[] = {0x00, 0xFF, 0x55, 0xAA};
    unsigned char arr2[] = {0x00, 0xFF, 0x55, 0xAB};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 4), memcmp(arr1, arr2, 4));
}
END_TEST

START_TEST(test_memcmp_misaligned_pointers) {
    char buffer[100];

    for (int i = 0; i < 100; i++) {
        buffer[i] = i;
    }

    ck_assert_int_eq(s21_memcmp(buffer + 3, buffer + 10, 20), memcmp(buffer + 3, buffer + 10, 20));
}
END_TEST

START_TEST(test_memcmp_sign_extension) {
    signed char a = -1;
    unsigned char b = 255;

    ck_assert_int_eq(s21_memcmp(&a, &b, 1), memcmp(&a, &b, 1));
}
END_TEST

START_TEST(test_memcmp_pattern) {
    char pattern[] = {0x00, 0x01, 0x02, 0x03};
    char buffer1[100];
    char buffer2[100];

    for (int i = 0; i < 100; i++) {
        buffer1[i] = pattern[i % 4];
        buffer2[i] = pattern[i % 4];
    }

    buffer2[50] = 0x04;

    ck_assert_int_eq(s21_memcmp(buffer1, buffer2, 100), memcmp(buffer1, buffer2, 100));
}
END_TEST

START_TEST(test_memcmp_reverse_order) {
    char str1[] = "ABCD";
    char str2[] = "ABCE";

    int result1 = s21_memcmp(str1, str2, 4);
    int result2 = s21_memcmp(str2, str1, 4);

    ck_assert_int_eq((result1 > 0 && result2 < 0) || (result1 < 0 && result2 > 0), 1);
}
END_TEST

START_TEST(test_memcmp_empty_arrays) {
    char arr1[10] = {0};
    char arr2[10] = {0};

    ck_assert_int_eq(s21_memcmp(arr1, arr2, 10), memcmp(arr1, arr2, 10));
}
END_TEST

Suite* s21_memcmp_suites(void) {
    Suite* memcmp_suite = suite_create("memcmp_tests");

    TCase* all_memcmp = tcase_create("memcmp");
    tcase_add_test(all_memcmp, test_memcmp_basic_equal);
    tcase_add_test(all_memcmp, test_memcmp_basic_not_equal);
    tcase_add_test(all_memcmp, test_memcmp_partial_equal);
    tcase_add_test(all_memcmp, test_memcmp_zero_bytes);
    tcase_add_test(all_memcmp, test_memcmp_int_array_equal);
    tcase_add_test(all_memcmp, test_memcmp_int_array_not_equal);
    tcase_add_test(all_memcmp, test_memcmp_struct_equal);
    tcase_add_test(all_memcmp, test_memcmp_struct_not_equal);
    tcase_add_test(all_memcmp, test_memcmp_negative_result);
    tcase_add_test(all_memcmp, test_memcmp_positive_result);
    tcase_add_test(all_memcmp, test_memcmp_difference_in_middle);
    tcase_add_test(all_memcmp, test_memcmp_difference_at_start);
    tcase_add_test(all_memcmp, test_memcmp_difference_at_end);
    tcase_add_test(all_memcmp, test_memcmp_signed_chars);
    tcase_add_test(all_memcmp, test_memcmp_unsigned_chars);
    tcase_add_test(all_memcmp, test_memcmp_null_chars_in_middle);
    tcase_add_test(all_memcmp, test_memcmp_same_pointers);
    tcase_add_test(all_memcmp, test_memcmp_double_array);
    tcase_add_test(all_memcmp, test_memcmp_one_byte);
    tcase_add_test(all_memcmp, test_memcmp_large_memory);
    tcase_add_test(all_memcmp, test_memcmp_bit_difference);
    tcase_add_test(all_memcmp, test_memcmp_misaligned_pointers);
    tcase_add_test(all_memcmp, test_memcmp_sign_extension);
    tcase_add_test(all_memcmp, test_memcmp_pattern);
    tcase_add_test(all_memcmp, test_memcmp_reverse_order);
    tcase_add_test(all_memcmp, test_memcmp_empty_arrays);

    suite_add_tcase(memcmp_suite, all_memcmp);

    return memcmp_suite;
}