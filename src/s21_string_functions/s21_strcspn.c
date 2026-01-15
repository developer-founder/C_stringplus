#include "../s21_string.h"
#include "string.h"

s21_size_t s21_strcspn(const char* str1, const char* str2) {
    return (strcspn(str1, str2));
}
