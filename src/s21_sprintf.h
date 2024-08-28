#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define longdouble long double
#define shortint short int
#define shortuint short unsigned
#define longint long int
#define longuint long unsigned
#define uint unsigned int

typedef struct flags {
  int width_by_zero;

  int flag_minus;

  int dot;

  int precision;

  int precision_by_argument;

  int minus;

  int flag_plus;

  int signed_num;

  int gFlagCall;

  int flag_h;

  int flag_l;

  int flag_L;

  int flag_space;

  int isNan;

  int flag_sharp;

  int width;

  int float_num;

  int usign_num;

  int width_by_argument;
} flags;

int s21_sprintf(char *str, const char *format, ...);
char *octal(char *oct_num, long unsigned int num, flags *param);
void write_to_str(char *str, int *count, const char *num_str);
char *hexadecimal(char *hex, long unsigned int num, flags *param);
char *pointer_to_string(char *str, void *pointer);
int len_of_string_to_arg(int count, va_list arg);
void inverse_string(char *str, int quantity);
char *unsig_decim(char *dec, unsigned int num);
char *signed_integer(char *dec, long int num);
char *mantissa_to_string_double(char *str, long double num, int precision,
                                flags *parametr_flags);
char *float_to_string(char *str, long double num, int precision,
                      flags *parametr_flags);
char *print_width(char *str, int width, flags *parametr_flags);
char *char_to_string(char *str, va_list arg);
void process(flags *parametr_flags, char *str, int *count, char *width_str,
             char *num_str);
void *checkGSpecificator(char *str, double num, int precision,
                         flags *parametr_flags);
int count_digits(int num);
int count_digits_float(double num, int precision);
int parser_flags(const char **pointer, flags *param);
char *precision_by_zero(char *str, flags *param);
void get_precision_from_argument(flags *param, va_list arg);

#endif  // S21_SPRINTF_H_