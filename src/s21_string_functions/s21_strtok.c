#include "../s21_string.h"

int is_delim(char symbol, const char* delim);

char* s21_strtok(char* str, const char* delim) {
  static char* saved_p = S21_NULL;
  char* result = S21_NULL;
  char* current_p;

  if (str != S21_NULL) {
    saved_p = str;
  }

  if (saved_p != S21_NULL) {
    current_p = saved_p;

    while (*current_p != '\0' && is_delim(*current_p, delim)) {
      current_p++;
    }

    if (*current_p != '\0') {
      result = current_p;

      while (*current_p != '\0' && !is_delim(*current_p, delim)) {
        current_p++;
      }

      if (*current_p == '\0') {
        saved_p = S21_NULL;
      } else {
        *current_p = '\0';
        saved_p = current_p + 1;
      }
    } else {
      saved_p = S21_NULL;
    }
  }

  return result;
}

int is_delim(char symbol, const char* delim) {
  int result = 0;
  while (*delim != '\0') {
    if (symbol == *delim) {
      result = 1;
      break;
    }
    delim++;
  }
  return result;
}