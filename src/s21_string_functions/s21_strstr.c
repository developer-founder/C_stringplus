#include "../s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
    char* result = S21_NULL;
    s21_size_t haystack_len = s21_strlen(haystack);
    s21_size_t needle_len = s21_strlen(needle);

    for (s21_size_t i = 0; i <= haystack_len - needle_len && !result; ++i) {
        int is_result = 1;
        for (s21_size_t j = 0; j < needle_len; ++j) {
            if (haystack[i + j] != needle[j]) {
                is_result = 0;
            }
        }
        if (is_result) {
            result = (char*)&haystack[i];
        }
    }

    return result;
}
