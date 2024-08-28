#ifndef S21_STRING_H_
#define S21_STRING_H_

#define s21_NULL ((void *)0)
#define s21_size_t unsigned long

#define true 1
#define false 0

// Temporary libs for s21_strerror TODO: rewrite str_error and then delete this
// -------
#include <errno.h>
// #include <stdio.h>

// #include "s21_sprintf.h"
// ---------------------

// owynwend functions ---------------
char *s21_strerror(int s21_errno);

char *s21_strchr(const char *str, int ch);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int ch);

// Aragornc functions -------

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *str1, const void *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *str1, const char *str2, s21_size_t n);
char *s21_strstr(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *deliminator);

// --------------------------

// ---C# func
void *s21_to_upper(const char *str);

void *s21_to_lower(const char *str);

void *s21_insert(const char *src, char *str, s21_size_t start_index);

void *s21_trim(char *src, const char *trim_chars);

// -------------------------

#endif  // S21_STRING_H_