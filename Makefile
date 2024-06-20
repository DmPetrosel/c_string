CFLAGS=-Wall -Wextra -Werror
all: main

main: main.o s21_strchr.o s21_strerror.o s21_strlen.o s21_strncmp.o s21_strncpy.o s21_strpbrk.o s21_strrchr.o s21_strscpn.o
	gcc -o a.out $?

main.o: main.c s21_string.h
	gcc $(CFLAGS) -c $<

s21_strchr.o: s21_strchr.c s21_string.h 
	gcc $(CFLAGS) -c $<

s21_strerror.o: s21_strerror.c s21_string.h 
	gcc $(CFLAGS) -c $<

s21_strlen.o: s21_strlen.c s21_string.h 
	gcc $(CFLAGS) -c $<

s21_strncmp.o: s21_strncmp.c s21_string.h 
	gcc $(CFLAGS) -c $<

s21_strncpy.o: s21_strncpy.c s21_string.h 
	gcc $(CFLAGS) -c $<

s21_strpbrk.o: s21_strpbrk.c s21_string.h 
	gcc $(CFLAGS) -c $<

s21_strrchr.o: s21_strrchr.c s21_string.h 
	gcc $(CFLAGS) -c $<
	
s21_strscpn.o: s21_strscpn.c s21_string.h 
	gcc $(CFLAGS) -c $<

rebuild: clean all

execute: clean all
	./a.out

clean:
	rm -rf *.out *.o
