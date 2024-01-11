#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef S21_CAT_H
#define S21_CAT_H

typedef struct {
  bool flag_b;
  bool flag_v;
  bool flag_dollar;
  bool flag_n;
  bool flag_s;
  bool tabs;
} Options;

Options Parser(int argc, char *argv[], int *find_flag, int *cur_argv_position);

void print_char(char line[], Options result);

void total_func(int argc, char *argv[], int cur_argv_position, Options result);

#endif