
#include <check.h>
#include <string.h>
#include "../s21_string.h"
#include "../s21_sprintf.h"
#include <stdio.h>

START_TEST(test_sprintf_1) {
  char str_s21[2000];
  char str_orig[2000];
  s21_sprintf(str_s21, "Hello World!123");
  sprintf(str_orig, "Hello World!123");
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_2) {
  char str_s21[2000];
  char str_orig[2000];
  int num7 = 42949677;
  s21_sprintf(str_s21, "s211 o %.20ho", num7);
  sprintf(str_orig, "s211 o %.20ho", num7);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_3) {
  char str_s21[2000];
  char str_orig[2000];
  s21_sprintf(str_s21, " X X x %.25lX %.6hX %.7x", 0x122342433F, -776, 4911);
  sprintf(str_orig, " X X x %.25lX %.6hX %.7x", 0x122342433F, -776, 4911);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_4) {
  char str_s21[2000];
  char str_orig[2000];
  char a = ' ', b = 'a', c = 'F';
  s21_sprintf(str_s21, "Char s211: Symbol %-7c %7c %-7c", a, b, c);
  sprintf(str_orig, "Char s211: Symbol %-7c %7c %-7c", a, b, c);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_5) {
  char str_s21[2000];
  char str_orig[2000];
  char *str5 = "Hello Wor30ld";
  s21_sprintf(str_s21, "s21 String: %25s %s", str5, str5);
  sprintf(str_orig, "s21 String: %25s %s", str5, str5);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_6) {
  char str_s21[2000];
  char str_orig[2000];
  int num = 7;
  void *pointer = &num;
  int result_s21 =
      s21_sprintf(str_s21, "s21 - Pointer: %-17p %p", pointer, pointer);
  int result_orig =
      sprintf(str_orig, "s21 - Pointer: %-17p %p", pointer, pointer);
  ck_assert_str_eq(str_s21, str_orig);
  ck_assert_int_eq(result_s21, result_orig);
}
END_TEST

START_TEST(test_sprintf_7) {
  char str_s21[2000];
  char str_orig[2000];
  int len = 0;
  int len2 = 0;
  s21_sprintf(str_s21, "s21_%n len: %n", &len, &len2);
  sprintf(str_orig, "s21_%n len: %n", &len, &len2);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_8) {
  char str_s21[2000];
  char str_orig[2000];
  unsigned int my_uint = 4294967295;
  s21_sprintf(str_s21, "s21 String: %u", my_uint);
  sprintf(str_orig, "s21 String: %u", my_uint);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_9) {
  char str_s21[2000];
  char str_orig[2000];
  long int sig_int = -1432442000000;
  long int sig_int2 = 1432442000000;
  s21_sprintf(str_s21, "Signed integer: s21_ %li String: %li", sig_int,
              sig_int2);
  sprintf(str_orig, "Signed integer: s21_ %li String: %li", sig_int, sig_int2);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_10) {
  char str_s21[2000];
  char str_orig[2000];
  short int sig_int = -1420;
  short int sig_int2 = 1420;
  s21_sprintf(str_s21, "Signed integer d: s21_ %hd String: %hd", sig_int,
              sig_int2);
  sprintf(str_orig, "Signed integer d: s21_ %hd String: %hd", sig_int,
          sig_int2);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_11) {
  char str_s21[2000];
  char str_orig[2000];
  long double num1 = -12345.678;
  s21_sprintf(str_s21, "%.7Le", num1);
  sprintf(str_orig, "%.7Le", num1);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_12) {
  char str_s21[2000];
  char str_orig[2000];
  long double num1 = -12345.678;
  s21_sprintf(str_s21, "%.6LE", num1);
  sprintf(str_orig, "%.6LE", num1);
  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_13) {
  char str_s21[200];
  char str_orig[200];
  int lenS21 = 0;
  int len = 0;

  s21_sprintf(str_s21,
              "Octal:%n %o, Hex: %X %x, Char: %c, String: %s, Pointer: %p "
              "Unsigned: %u Signed i: %i Signed d:%d",
              &lenS21, 779, 0x123F, -776, 'b', "str5", (void *)0x7ffe,
              4294967295u, -14244000, 14244000);
  sprintf(str_orig,
          "Octal:%n %o, Hex: %X %x, Char: %c, String: %s, Pointer: %p "
          "Unsigned: %u Signed i: %i Signed d:%d",
          &len, 779, 0x123F, -776, 'b', "str5", (void *)0x7ffe, 4294967295u,
          -14244000, 14244000);

  ck_assert_str_eq(str_s21, str_orig);
  ck_assert_int_eq(len, lenS21);
}
END_TEST

START_TEST(test_sprintf_14) {
  char str_s21[100];
  char str_orig[100];

  s21_sprintf(str_s21, "%.f", 12335432.01344);
  sprintf(str_orig, "%.f", 12335432.01344);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_15) {
  char str_s21[100];
  char str_orig[100];

  s21_sprintf(str_s21, "test peecent %%");
  sprintf(str_orig, "test peecent %%");

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_16) {
  char str_s21[100];
  char str_orig[100];
  int num3 = 123;

  s21_sprintf(str_s21, "d %.5d", num3);
  sprintf(str_orig, "d %.5d", num3);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_17) {
  char str_s21[100];
  char str_orig[100];
  double num4 = 12343543.0123;

  s21_sprintf(str_s21, "spec %g", num4);
  sprintf(str_orig, "spec %g", num4);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_18) {
  char str_s21[100];
  char str_orig[100];
  double num5 = 121.5126;

  s21_sprintf(str_s21, "g spec %g", num5);
  sprintf(str_orig, "g spec %g", num5);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_19) {
  char str_s21[100];
  char str_orig[100];
  int num6 = -234124.0;

  s21_sprintf(str_s21, "%+20d", num6);
  sprintf(str_orig, "%+20d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_20) {
  char str_s21[100];
  char str_orig[100];
  long double num6 = -234124.0;

  s21_sprintf(str_s21, "%+20Le", num6);
  sprintf(str_orig, "%+20Le", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_21) {
  char str_s21[100];
  char str_orig[100];
  int num6 = -234124;

  s21_sprintf(str_s21, "% 015d", num6);
  sprintf(str_orig, "% 015d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_22) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "% 15d", num6);
  sprintf(str_orig, "% 15d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_23) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "% d", num6);
  sprintf(str_orig, "% d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_24) {
  char str_s21[100];
  char str_orig[100];
  int num6 = -234124;

  s21_sprintf(str_s21, "% d", num6);
  sprintf(str_orig, "% d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_25) {
  char str_s21[100];
  char str_orig[100];
  int num6 = -234124;

  s21_sprintf(str_s21, "% i", num6);
  sprintf(str_orig, "% i", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_26) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "% i", num6);
  sprintf(str_orig, "% i", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_27) {
  char str_s21[100];
  char str_orig[100];
  int num6 = -234124;

  s21_sprintf(str_s21, "% 05d", num6);
  sprintf(str_orig, "% 05d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_28) {
  char str_s21[100];
  char str_orig[100];
  int num6 = -234124;

  s21_sprintf(str_s21, "% 15d", num6);
  sprintf(str_orig, "% 15d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_29) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "% 15d", num6);
  sprintf(str_orig, "% 15d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_30) {
  char str_s21[100];
  char str_orig[100];
  int num6 = -234124;

  s21_sprintf(str_s21, "% 15i", num6);
  sprintf(str_orig, "% 15i", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_31) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "% 15i", num6);
  sprintf(str_orig, "% 15i", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_32) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "%15o", num6);
  sprintf(str_orig, "%15o", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_33) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "%15x", num6);
  sprintf(str_orig, "%15x", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_34) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "%#15X", num6);
  sprintf(str_orig, "%#15X", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_35) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "%- d", num6);
  sprintf(str_orig, "%- d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_36) {
  char str_s21[100];
  char str_orig[100];
  int num6 = 234124;

  s21_sprintf(str_s21, "% -d", num6);
  sprintf(str_orig, "% -d", num6);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_37) {
  char str_s21[100];
  char str_orig[100];
  double num = 1.0;

  s21_sprintf(str_s21, "test g spec %.g", num);
  sprintf(str_orig, "test g spec %.g", num);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_38) {
  char str_s21[100];
  char str_orig[100];
  double num = 111.01;

  s21_sprintf(str_s21, "test g spec %.7g", num);
  sprintf(str_orig, "test g spec %.7g", num);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_39) {
  char str_s21[100];
  char str_orig[100];
  double num = 1123123123.0123123;

  s21_sprintf(str_s21, "test g spec %.g", num);
  sprintf(str_orig, "test g spec %.g", num);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_40) {
  char str_s21[100];
  char str_orig[100];
  double num = 1123123123.0123123;

  s21_sprintf(str_s21, "test g spec %.7g", num);
  sprintf(str_orig, "test g spec %.7g", num);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST

START_TEST(test_sprintf_41) {
  char str_s21[100];
  char str_orig[100];
  double num = -112.01;

  s21_sprintf(str_s21, "test g spec %.7g", num);
  sprintf(str_orig, "test g spec %.7g", num);

  ck_assert_str_eq(str_s21, str_orig);
}
END_TEST