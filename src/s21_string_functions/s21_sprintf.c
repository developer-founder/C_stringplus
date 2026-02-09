#include "s21_sprintf.h"

int s21_sprintf(char *str, const char* format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    parser(&args, format, str, &result);
    va_end(args);
    str[result] = '\0';
    return result;
}

void parser(va_list* args, const char* format, char* str, int* result) {
    for (int i = 0; format[i]; ++i) {
        Specifiers specs = {0};
        if (format[i] != '%') {
            str[(*result)++] = format[i];
        } else {
            i++;
            process_specifier(args, format, &i, str, result, &specs);
        }
    }
}

void process_specifier(va_list* args, const char* format, int* i, char* str, int* result, Specifiers* specs) {
    switch (format[*i]) {
        case 'c':
            specs->c = (char)va_arg(*args, int);
            char_to_str(specs->c, str, result);
            break;
        case 's':
            specs->s = va_arg(*args, char*);
            str_to_str(specs->s, str, result);
            break;
        case '%':
            char_to_str(format[*i], str, result);
        case 'd':
            specs->d = va_arg(*args, int);
            int_to_str(specs->d, str, result);
        }
    // } else if (specifier == 'd') {
    //     // int num = va_arg(*args, int);
    //     // int_to_str(num, str, result);
    // } else if (specifier == 'f') {
    //     // double num = va_arg(*args, double);
    //     // double_to_str(num, str, result);
    // } else if (specifier == 'u') {
    //     // unsigned int num = va_arg(*args, unsigned int);
    //     // uint_to_str(num, str, result);
    // }
}

void int_to_str(long long num, char* str, int* result) {
    if (num == 0) {
        str[(*result)++] = '0';
        return;
    } 
    if (num < 0) {
        str[(*result)++] = '-';
        num = -num;
    }
    long long tmp = num;
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

// void uint_to_str(unsigned int num, char* str, int* result) {
//     if (num == 0) {
//         str[(*result)++] = '0';
//         // (*result)++;
//         return;
//     }
//     unsigned int tmp = num;
//     s21_size_t len = 0;
//     while(tmp > 0) {
//         tmp /= 10;
//         len++;
//     }

//     for (; len > 0; --len) {
//         str[len-1] = num % 10 + '0';
//         num /= 10;
//         (*result)++;
//     }
// }

void str_to_str(char* s, char* str, int* result) {
    for (int i = 0; s[i]; ++i) {
        str[(*result)++] = s[i];
    } 
}

// void double_to_str(double num, char* str, int* result) {
//     // int old_result = *result;
//     long long int_part = (long long)num;
//     double frac = (num - int_part) * 1000000 + 0.5;
//     int_to_str(int_part, str, result);
//     str[(*result)++] = '.';
//     // str++;
//     // (*result)++;
//     int_to_str(frac, str, result);
// }

void char_to_str(char c, char* str, int* result) {
    str[(*result)++] = c;
}

void logic_for_to_string() {

}