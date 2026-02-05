#include "s21_sprintf.h"

int s21_sprintf(char *str, const char* format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    parser(format, str, &result);
    va_end(args);
    str[result] = '\0';
    return result;
}

void parser(const char* format, char* str, int* result) {
    int j = 0;
    for (int i = 0; format[i] != '\0'; ++i) {
        if (format[i] != '%') {
            str[j] = format[i];
            j++;
            (*result)++;
        } else {
            if (format[i + 1] == '%') {
                str[j] = '%';
                j++;
                (*result)++;
            }
        }
    }
}
