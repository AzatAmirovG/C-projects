ALL =gcc -Wall -Wextra -Werror
FLAGS =-Wall -Wextra -Werror
c = gcc

all: s21_grep clean

s21_grep:
	$(ALL) -c s21_grep.c
	$(c) *.o -o s21_grep
	rm *.o

clean:
	rm s21_grep

tests:
	sh tests.sh