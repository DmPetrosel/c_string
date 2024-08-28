.PHONY: s21_string.a test gcov_report clean clang

CFLAGS = -std=c11 
LDFLAGS = -lcheck -lcheck_pic -pthread -lm -lsubunit -lgcov -lrt
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

TESTS = s21_test/test.c

STRING_FUNCTIONS = *.c

all: test

# Static library
s21_string.a: $(STRING_FUNCTIONS)
	gcc -c $(STRING_FUNCTIONS) $(CFLAGS)
	ar rcs s21_string.a *.o

# tests
test: s21_string.a
	gcc -o s21_test.out $(TESTS) -L. -l:s21_string.a $(CFLAGS) $(LDFLAGS)
	./s21_test.out
	
	

valgrind_test: test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valgrind-out.txt ./s21_test
# gcov
gcov_report: test
	gcc -o s21_test.out $(TESTS) -L. -l:s21_string.a $(CFLAGS) $(LDFLAGS) -fprofile-arcs -ftest-coverage
	./s21_test.out || true
	lcov -c -d . -o lcov_test.info
	genhtml -o lcov_report_html --legend lcov_test.info
	rm -f *.gcda *.gcno

# Useful utilitites
clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov
	rm -rf lcov_report_html

clang:
	find . \( -name '*.c' -o -name '*.h' \) -exec clang-format -i {} \;

