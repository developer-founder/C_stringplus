#include "../s21_string.h"

void* s21_memchr(const void* str, int c, s21_size_t n) {
  int result = 0;
  s21_size_t i = 0;
  while (i < n && !result) {
    if (((unsigned char*)str)[i] == (unsigned char)c) {
      result = 1;
      str = &((char*)str)[i];
    }
    i++;
  }

  return result ? (void*)str : S21_NULL;
}
