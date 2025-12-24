#include "s21_string.h"

#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello-";
    int result;
    int myresult;

    result = memcmp(str2, str1, 13);
    myresult = s21_memcmp(str2, str1, 13);
    printfln("%d", result);
    printfln("%d", myresult);

    return 0;
}
