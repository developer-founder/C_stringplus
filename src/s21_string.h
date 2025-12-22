#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int memcmp(const void *str1, const void *str2, s21_size_t n);
void *memcpy(void *dest, const void *src, s21_size_t n);
void *memset(void *str, int c, s21_size_t n);
char *strncat(char *dest, const char *src, s21_size_t n);
char *strchr(const char *str, int c);
int strncmp(const char *str1, const char *str2, s21_size_t n);
char *strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t strcspn(const char *str1, const char *str2);
char *strerror(int errnum);
s21_size_t strlen(const char *str);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);

#endif