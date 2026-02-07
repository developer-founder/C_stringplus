#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "../s21_string.h"
#include <stdarg.h>

void parse_format(va_list* args, const char* format, char* str, int* result);
void process_specifier(va_list* args, char specifier, char* str, int* result);
void char_to_str(char c, char* str, int* result);
void str_to_str(char* s, char* str, int* result);
void int_to_str(long long num, char* str, int* result);
void uint_to_str(unsigned int num, char* str, int* result);
void double_to_str(double num, char* str, int* result);

#endif