#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void*)0)

typedef unsigned long s21_size_t;

void* s21_memchr(const void* str, int c, s21_size_t n);             // Не проверен тестами
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);   // Не проверен тестами
void* s21_memcpy(void* dest, const void* src, s21_size_t n);        // Не проверен тестами
void* s21_memset(void* str, int c, s21_size_t n);                   // Не проверен тестами
char* s21_strncat(char* dest, const char* src, s21_size_t n);       // Не проверен тестами
char* s21_strchr(const char* str, int c);                           // Не проверен тестами
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);  // Не проверен тестами
char* s21_strncpy(char* dest, const char* src, s21_size_t n);       // Не проверен тестами
s21_size_t s21_strcspn(const char* str1, const char* str2);         // Проверен тестами
char* s21_strerror(int errnum);                                     // Проверен тестами
s21_size_t s21_strlen(const char* str);                             // Не проверен тестами
char* s21_strpbrk(const char* str1, const char* str2);              // Проверен тестами
char* s21_strrchr(const char* str, int c);                          // Не проверен тестами
char* s21_strstr(const char* haystack, const char* needle);         // Не проверен тестами
// char *s21_strtok(char *str, const char *delim);
// void *to_upper(const char *str);
// void *to_lower(const char *str);
// void *insert(const char *src, const char *str, size_t start_index);
// void *trim(const char *src, const char *trim_chars);

#endif
