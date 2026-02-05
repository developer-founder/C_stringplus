#include "s21_sprintf.h"

int s21_sprintf(char *str, const char* format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    parse_format(&args, format, str, &result);
    va_end(args);
    str[result] = '\0';
    return result;
}

void parse_format(va_list* args, const char* format, char* str, int* result) {
    int j = 0;
    for (int i = 0; format[i] != '\0'; ++i) {
        if (format[i] != '%') {
            str[j] = format[i];
            j++;
            (*result)++;
        } else {
                process_specifier(args, format[i+1], &str[j], result);
                // str[j] = '%';
                j++;
                i++;
                // (*result)++;
        }
    }
}

void process_specifier(va_list* args, char specifier, char* str, int* result) {
    if (specifier == 'c') {
        char c = (char)va_arg(*args, int);
        *str = c;
        (*result)++;
    } else if (specifier == 's') {
        char *s = va_arg(*args, char*);
        while (*s) {
            *str = *s;
            str++;
            s++;
            (*result)++;
        }
    } else if (specifier == '%') {
        char c = '%';
        *str = c;
        (*result)++;
    }
}