#include "../s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  char* result = S21_NULL;

  if (*needle == '\0') {
    result = (char*)haystack;
  } else {
    const char* h = haystack;

    while (*h && !result) {
      const char* h_temp = h;
      const char* n = needle;

      while (*h_temp && *n && *h_temp == *n) {
        h_temp++;
        n++;
      }

      if (*n == '\0') {
        result = (char*)h;
      }

      h++;
    }
  }

  return result;
}