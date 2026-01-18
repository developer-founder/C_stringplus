#include "../s21_string.h"

char* s21_strrchr(const char* str, int c) {
    int i = s21_strlen(str) - 1;
    char* result = S21_NULL;
    while (str[i] && str[i] != c) --i;
    if (c == str[i]) {
        result = (char*)str + i;
    }

    return result;
}
