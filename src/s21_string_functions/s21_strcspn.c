#include "../s21_string.h"
#include <string.h>

s21_size_t s21_strcspn(const char* str1, const char* str2) {
    s21_size_t result = 0;

    if (str1) {
        while (str1[result] != '\0' && str1[result] != str2[result]) {
            result++;
        }
    }

    return result; 

//    return strcspn(str1, str2);
}