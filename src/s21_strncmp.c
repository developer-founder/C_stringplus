#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (((const char *)str1)[i] == ((const char *)str2)[i]) {
            continue;
        }
        if (((const char *)str1)[i] == '\0' && ((const char *)str2)[i] == '\0') {
            break;
        }
        result = ((const char *)str1)[i] - ((const char *)str2)[i];
        break;
    }
    return result;
}