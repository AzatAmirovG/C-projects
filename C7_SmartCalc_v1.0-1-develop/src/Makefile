FLAGS = gcc -Wall -Werror -Wextra -std=c11
LIB=-lcheck
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

FUNCTIONS_FOLDER=back_functions/
TEST_FILE = s21_test_calc.c

LIB_NAME = s21_calc.a

UNIT_TEST=-o unit_test
GCOV_TEST=-o gcov_test

ifeq ($(shell uname), Linux)
 LIB +=-lpthread -lrt -lsubunit -lm
endif

all: clean ${LIB_NAME}

${LIB_NAME}:
	${FLAGS} -c ${wildcard ${FUNCTIONS_FOLDER}*.c}
	ar rc ${LIB_NAME} *.o
	ranlib ${LIB_NAME}
	rm *.o

clean:
	rm -rf report a.out unit_test gcov_test *.gcda *.gcno *.info ${LIB_NAME} *.o

test: ${LIB_NAME}
	${FLAGS} ${UNIT_TEST} ${TEST_FILE} ${LIB_NAME} ${LIB}
	./unit_test
	rm ${LIB_NAME}
	rm unit_test

valgrind_test: ${LIB_NAME}
	${FLAGS} ${UNIT_TEST} ${TEST_FILE} ${LIB_NAME} ${LIB}
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --leak-check=full --track-origins=yes --log-file=valgrind-out.txt --show-leak-kinds=all ./unit_test
	rm ${LIB_NAME}
	rm unit_test

gcov_report: 
	 ${FLAGS} ${GCOV_FLAGS} --coverage ${wildcard ${FUNCTIONS_FOLDER}*.c} ${GCOV_TEST} ${TEST_FILE} ${LIB}
	./gcov_test
	lcov -t "stest" -o s21_test.info -c -d . -no-external
	genhtml -o report s21_test.info
	open ./report/index.html
	rm gcov_test

dist: clean uninstall
	mkdir ../dist
	cp -r ../src ../dist
	cp ../README.md ../dist
	cd ../dist && tar -czvf dist.tar.gz ./src
	rm -rf ../dist/src

dvi:
	doxygen calcconfig 
	open html/index.html

uninstall:
	rm -rf Calc/build $(HOME)/Desktop/Calculator.app

install:
	mkdir build
	mkdir $(HOME)/Desktop/Calculator
	cd build && cmake ../Calculator/CMakeLists.txt && make
	cp -rf build/Calculator.app $(HOME)/Desktop/Calculator/Calculator.app


check_clang_format:
	mv ../materials/linters/.clang-format .
	clang-format -n functions/*.c
	clang-format -n tests/*.c
	clang-format -n tests/*.h
	clang-format -n s21_matrix.h
	mv .clang-format ../materials/linters/

fix_clang_format:
	mv ../materials/linters/.clang-format .
	clang-format -i back_functions/*.c
	clang-format -i s21_test_calc.c
	clang-format -i s21_SmartCalc.h
	clang-format -i Calculator/*.cpp
	clang-format -i Calculator/*.h
	mv .clang-format ../materials/linters/
