#include "s21_string.h"

#include <stdio.h>
#include <string.h>

int main() {
    int numbers[5];

    s21_memset(numbers, 0, sizeof(numbers));

    printf("Массив после memset(numbers, 0, sizeof(numbers)):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}