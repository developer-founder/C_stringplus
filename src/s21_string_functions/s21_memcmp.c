#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (((const char *)str1)[i] == ((const char *)str2)[i]) {
            continue;
        }
        result = ((const char *)str1)[i] - ((const char *)str2)[i];
        break;
    }
    return result;
}