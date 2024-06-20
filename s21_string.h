#ifndef S21_STRING_H_
#define S21_STRING_H_

#define s21_NULL ((void*)0)
#define s21_size_t unsigned long

// Temporary libs, TODO: Delete them
#include <errno.h>
#include <stdio.h>
#include <string.h>
// ---------------------
char * s21_strerror(int s21_errno);

char * s21_strchr(const char * str, int ch);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char * s21_strpbrk( const char * str1, const char * str2);
char * s21_strrchr(const char * str, int ch);


#endif // S21_STRING_H_