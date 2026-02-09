#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "../s21_string.h"
#include <stdarg.h>

typedef struct specifiers {
    int d;
    // short int hd;
    // short unsigned int hu;
    // long unsigned int lu;
    // long int ld;
    // double e;
    char c;
    double f;
    char* s;
    unsigned int u;
} Specifiers;

void parser(va_list* args, const char* format, char* str, int* result);
void process_specifier(va_list* args, const char* format, int* i, char* str, int* result, Specifiers* specifiers);
void str_to_str(char* s, char* str, int* result);
void int_to_str(long long num, char* str, int* result);
// void uint_to_str(unsigned int num, char* str, int* result);
// void double_to_str(double num, char* str, int* result);
void char_to_str(char c, char* str, int* result);

#endif