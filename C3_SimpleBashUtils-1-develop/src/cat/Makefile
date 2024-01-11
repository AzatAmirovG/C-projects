ALL =gcc -Wall -Wextra -Werror
FLAGS =-Wall -Wextra -Werror
c = gcc

all: s21_cat clean

s21_cat:
	$(ALL) -c s21_cat.c
	$(c) *.o -o s21_cat
	rm *.o

clean:
	rm s21_cat

tests:
	sh tests.sh