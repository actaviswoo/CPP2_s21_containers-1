CC = gcc
CFLAGS = -Wextra -Werror -Wall
CPPFLAGS = -lstdc++ -std=c++17
TESTLIBS= -lgtest

all: clean test

clean:
	rm -rf main *.dSYM test *.o *.a *.gcda *.gcno *.info *.out *.txt report .clang_format report.html gcov_report

test: clean
	$(CC) $(CFLAGS) -g $(TESTLIBS) $(CPPFLAGS) tests/* -o test --pedantic
	./test

style:
	cp ../materials/linters/.clang-format ./
	clang-format -n tests/*.cc headers/*.h
	rm .clang-format

leaks: test
	leaks -atExit -- ./test

gcov_report:
	$(CC) $(CFLAGS) -g  --coverage tests/* -o gcov_report $(TESTLIBS) $(CPPFLAGS) -lpthread -lm --pedantic
	./gcov_report
	lcov -t "covered" -o s21_test.info -c -d ./ --no-external
	genhtml -o report s21_test.info
	open ./report/index.html

.PHONY: all clean test style leaks gcov_report