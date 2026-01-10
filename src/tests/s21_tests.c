#include "s21_tests.h"

int main() {
      const char *text = "Hello, world!";
      char *ptr = s21_strchr(text, 'w'); // Поиск 'w'

      if (ptr != NULL) {
         printf("Найден символ 'w' по адресу: %p\n", (void*)ptr);
         printf("Оставшаяся часть строки: %s\n", ptr); // Выведет "world!"
      } else {
         printf("Символ 'w' не найден.\n");
      }
      return 0;
}
