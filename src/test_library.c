#include "s21_string.h"

#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, world!";
    char *result;

    result = (char *)memchr(str, 'l', 10);
    if (result) {
        printf("Символ 'l' найден в: %s\n", result);
    } else {
        printf("%s", result);
    }

    return 0;
}
