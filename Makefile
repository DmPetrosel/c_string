CFLAGS=-Wall -Wextra -Werror
all: main

main: main.o
	gcc -o a.out $?

main.o: main.c 
	gcc $(CFLAGS) -c $<

rebuild: clean all

execute: clean all
	./a.out

clean:
	rm -rf *.out *.o
