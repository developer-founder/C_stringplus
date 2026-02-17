#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite* s21_memchr_suites(void);
Suite* s21_memcmp_suites(void);
Suite* s21_memcpy_suites(void);
Suite* s21_memset_suites(void);
Suite* s21_strncat_suites(void);
Suite* s21_strchr_suites(void);
Suite* s21_strncmp_suites(void);
Suite* s21_strncpy_suites(void);
Suite* s21_strcspn_suites(void);
Suite* s21_strerror_suites(void);
Suite* s21_strlen_suites(void);
Suite* s21_strpbrk_suites(void);
Suite* s21_strrchr_suites(void);
Suite* s21_strstr_suites(void);
Suite* s21_strtok_suites(void);
Suite* s21_sprintf_suites(void);

#endif
