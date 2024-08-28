#include "s21_string.h"

char *s21_strchr(const char *str, int ch) {
  while (*str++) {
    if (*str == ch) {
      return (char *)str;
    }
  }
  return 0;
}
