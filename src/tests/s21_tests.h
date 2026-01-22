#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite* memchr_suites(void);
Suite* memcmp_suites(void);
Suite* memcpy_suites(void);
Suite* memset_suites(void);
Suite* strncat_suites(void);
Suite* strchr_suites(void);
Suite* strncmp_suites(void);
Suite* strncpy_suites(void);
Suite* strcspn_suites(void);
Suite* strerror_suites(void);
Suite* strlen_suites(void);
Suite* strpbrk_suites(void);
Suite* strrchr_suites(void);
Suite* strstr_suites(void);
// Suite* strtok_suites(void);

#endif
