#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef S21_GREP_H
#define S21_CAT_H

typedef struct {
  bool template;
  bool ignore_case;
  bool invert;
  bool quantity;
  bool show_match_files;
  bool line_number;
  bool match_wo_name;
  bool no_errors;
  bool deus_file;
  bool print_fragments;
} grep_struct;

grep_struct options_parser(int argc, char *argv[], char *reg_value,
                           int *cur_argv_position, int *reg_0);

void printer(int argc, char *argv[], grep_struct result, char line[],
             const char *expression, int reg_state, int cur_argv_position,
             int reg);

#endif