#include "../s21_string.h"
#include <string.h>
#include <stdio.h>

int main() {
    const char *test_string = "Hello, \0World!";
    
    size_t my_length = s21_strlen(test_string);
    
    size_t std_length = strlen(test_string);
    
    printf("Тестовая строка: \"%s\"\n", test_string);
    printf("Длина по my_strlen: %zu\n", my_length);
    printf("Длина по strlen:    %zu\n", std_length);
    printf("Результаты %s\n", my_length == std_length ? "СОВПАДАЮТ ✓" : "НЕ СОВПАДАЮТ ✗");
    
    const char *additional_tests[] = {
        "",
        "a",
        "123",
        "Длинная строка для тестирования         "
    };
    
    printf("\nДополнительные тесты:\n");
    printf("%-46s | %-12s | %-12s | %s\n", "Строка", "my_strlen", "strlen", "Статус");
    printf("-------------------------------------------------------------------------\n");
    
    for (int i = 0; i < 4; i++) {
        const char *str = additional_tests[i];
        size_t my_len = s21_strlen(str);
        size_t std_len = strlen(str);
        
        printf("%-40s | %-12zu | %-12zu | %s\n", str, my_len, std_len, my_len == std_len ? "OK" : "ERROR");
    }
    
    return 0;
}