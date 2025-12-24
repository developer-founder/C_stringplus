#include "s21_string.h"

#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "atoms\0\0\0\0";
    const char *str2 = "atoms\0abc";
    const char *str3 = "atomsaaa";

    int result;
    int myresult;

    result = s21_strncmp(str1, str2, 8);
    myresult = s21_memcmp(str1, str2, 8);
    printf("%d\n", result);
    printf("%d\n", myresult);

    return 0;
}
