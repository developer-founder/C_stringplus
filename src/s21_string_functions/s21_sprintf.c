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
            int old_result = *result;
            process_specifier(args, format[i+1], &str[j], result);
            int written = *result - old_result;
            j += written;
            i++;
        }
    }
}

void process_specifier(va_list* args, char specifier, char* str, int* result) {
    if (specifier == 'c') {
        char c = (char)va_arg(*args, int);
        char_to_str(c, str, result);
    } else if (specifier == 's') {
        char *s = va_arg(*args, char*);
        str_to_str(s, str, result);
    } else if (specifier == 'd') {
        int num = va_arg(*args, int);
        int_to_str(num, str, result);
    } else if (specifier == 'f') {
        double num = va_arg(*args, double);
        double_to_str(num, str, result);
    } else if (specifier == '%') {
        char c = '%';
        *str = c;
        (*result)++;
    }
}

void int_to_str(int num, char* str, int* result) {
    if (num == 0) {
        *str = '0';
        (*result)++;
        return;
    } 
    if (num < 0) {
        *str = '-';
        str++;
        (*result)++;
        num = -num;
    }
    int tmp = num;
    s21_size_t len = 0;
    while(tmp > 0) {
        tmp /= 10;
        len++;
    }

    for (; len > 0; --len) {
        str[len-1] = num % 10 + '0';
        num /= 10;
        (*result)++;
    }
}

void str_to_str(char* s, char* str, int* result) {
    while (*s) {
        *str = *s;
        str++;
        s++;
        (*result)++;
    } 
}

void double_to_str(double num, char* str, int* result) {
    int old_result = *result;
    long long int_part = (long long)num;
    double frac = num - int_part;
    int_to_str(int_part, str, result);
    str += (*result - old_result);
    *str = '.';
    str++;
    (*result)++;
    for (int i = 0; i < 6; ++i) {
        frac *= 10;
        int digit = (int)frac;
        *str = digit + '0';
        frac -= digit;
        str++;
        (*result)++;
    }
}

void char_to_str(char c, char* str, int* result) {
    *str = c;
    (*result)++;
}