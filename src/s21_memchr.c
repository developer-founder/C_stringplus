#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    int result = 0;
    int i = 0;
    while (i++ < n && !result) {
        if (*(char *)str == c) {
            result = 1;
        }
        str = (char *)str + 1;
    }
    str = (char *)str - 1;

    return result ? (void *)str : S21_NULL;
}