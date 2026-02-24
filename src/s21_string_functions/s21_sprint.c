// #include "s21_sprintf.h"

// int s21_sprintf(char* str, const char* format, ...) {
//     int result = 0;
//     va_list args;
//     va_start(args, format);
//     parser(&args, format, str, &result);
//     va_end(args);
//     str[result] = '\0';
//     return result;
// }

// void parser(va_list* args, const char* format, char* str, int* result) {
//     for (int i = 0; format[i]; ++i) {
//         Specifiers specs = {0};
//         if (format[i] != '%') {
//             str[(*result)++] = format[i];
//         } else {
//             i++;
//             process_specifier(args, format, &i, str, result, &specs);
//         }
//     }
// }

// void process_specifier(va_list* args, const char* format, int* i, char* str,
// int* result, Specifiers* specs) {
//     switch (format[*i]) {
//         case 'c':
//             specs->c = (char)va_arg(*args, int);
//             char_to_str(specs->c, str, result);
//             break;
//         case 's':
//             specs->s = va_arg(*args, char*);
//             str_to_str(specs->s, str, result);
//             break;
//         case '%':
//             char_to_str(format[*i], str, result);
//             break;
//         case 'i':
//         case 'd':
//             specs->d = va_arg(*args, int);
//             int_to_str(specs->d, str, result);
//             break;
//         case 'f':
//             specs->f = va_arg(*args, double);
//             double_to_str(specs->f, str, result);
//             break;
//         case 'u':
//             specs->u = va_arg(*args, unsigned int);
//             uint_to_str(specs->u, str, result);
//             break;
//     }
// }

// void int_to_str(long long num, char* str, int* result) {
//     int len = 0;
//     char tempStr[100];
//     int is_negative = 0;

//     if (num == 0) {
//         tempStr[0] = '0';
//         tempStr[1] = '\0';
//         logic_for_to_string(tempStr, str, result);
//         return;
//     }

//     if (num < 0) {
//         is_negative = 1;
//         num = -num;
//     }

//     long long tmp = num;
//     while (tmp > 0) {
//         tempStr[len] = (tmp % 10) + '0';
//         tmp /= 10;
//         len++;
//     }

//     if (is_negative) {
//         tempStr[len] = '-';
//         len++;
//     }

//     for (int i = 0; i < len / 2; i++) {
//         char c = tempStr[i];
//         tempStr[i] = tempStr[len - 1 - i];
//         tempStr[len - 1 - i] = c;
//     }

//     tempStr[len] = '\0';
//     logic_for_to_string(tempStr, str, result);
// }

// void uint_to_str(unsigned int num, char* str, int* result) {
//     int len = 0;
//     unsigned int tmp = num;
//     char tempStr[100];

//     if (num == 0) {
//         tempStr[0] = '0';
//         tempStr[1] = '\0';
//         logic_for_to_string(tempStr, str, result);
//         return;
//     }

//     while (tmp > 0) {
//         tmp /= 10;
//         len++;
//     }

//     for (int i = len - 1; i >= 0; i--) {
//         tempStr[i] = (tmp % 10) + '0';
//         tmp /= 10;
//     }

//     tempStr[len] = '\0';
//     logic_for_to_string(tempStr, str, result);
// }

// void double_to_str(double num, char* str, int* result) {
//     long long int_part = (long long)num;
//     char tempStr[100];

//     if (num == 0) {
//         tempStr[0] = '0';
//         tempStr[1] = '\0';
//         logic_for_to_string(tempStr, str, result);
//         return;
//     }

//     // доделать
// }

// void str_to_str(char* s, char* str, int* result) {
//     for (int i = 0; s[i]; ++i) {
//         str[(*result)++] = s[i];
//     }
// }

// void char_to_str(char c, char* str, int* result) { str[(*result)++] = c; }

// // void calculate_width() {

// // }

// // void make_width() {

// // }

// void logic_for_to_string(char* tempStr, char* str, int* result) {
//     int tempStrLen = s21_strlen(tempStr);
//     for (int i = 0; i < tempStrLen; i++) {
//         str[(*result)++] = tempStr[i];
//     }
// }