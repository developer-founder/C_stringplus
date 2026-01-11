#include "s21_tests.h"

int main() {
    //const char *text = "Hello, world!";
    const char* text = "Hello,\0 world!";
    //const char *text = "Hello, world!\0\0\0\0";

    char dest[16];
    char* ptr = s21_strncpy(dest, text, 15);

    printf("Оставшаяся часть строки: %s\n", ptr);
    return 0;
}
