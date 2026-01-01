#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t result = 0;
    s21_size_t i = 0;
    while (((const char *)str[i]) != '\0') {
        result += 1;
        i++;
    }
    return result;
}