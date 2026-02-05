#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "../s21_string.h"
#include <stdarg.h>

void parse_format(va_list* args, const char* format, char* str, int* result);
void process_specifier(va_list* args, char specifier, char* str, int* result);

#endif