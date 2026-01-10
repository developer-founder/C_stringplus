#include "../s21_string.h"

char* s21_strchr(const char* str, int c) {
    int i = 0;
    char *result;
    while (str[i] && str[i] != c) ++i;
    if (c == str[i]) {
        result = (char*)str + i;
    } else {
        result = S21_NULL;
    }

    return result;
}
