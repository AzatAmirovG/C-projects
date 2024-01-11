#include "s21_grep.h"

grep_struct options_parser(int argc, char *argv[], char *reg_value,
                           int *cur_argv_position, int *reg_0) {
  grep_struct sample = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int i, e_counter = 0;
  struct option long_options[] = {{NULL, 0, NULL, 0}};
  while ((i = getopt_long(argc, argv, "e:ivclnhsf:o", long_options, NULL)) !=
         -1) {
    switch (i) {
      case 'e':
        sample.template = true;
        if (e_counter > 0) {
          strcat(reg_value, "|");
          strcat(reg_value, optarg);
        } else {
          strcpy(reg_value, optarg);
        }
        e_counter++;
        break;
      case 'i':
        sample.ignore_case = true;
        break;
      case 'v':
        sample.invert = true;
        break;
      case 'c':
        sample.quantity = true;
        break;
      case 'l':
        sample.show_match_files = true;
        break;
      case 'n':
        sample.line_number = true;
        break;
      case 'h':
        sample.match_wo_name = true;
        break;
      case 's':
        sample.no_errors = true;
        opterr = 0;
        break;
      case 'f':
        sample.deus_file = true;
        FILE *fp;
        char ch[1], prev_ch[1];
        prev_ch[0] = 0;
        if ((fp = fopen(optarg, "r")) == NULL) {
          printf("Cannot open file.\n");
          exit(1);
        }
        if (e_counter > 0) {
          strcat(reg_value, "|");
        }
        while ((*ch = fgetc(fp)) != EOF) {
          if (prev_ch[0] == ch[0]) {
            *reg_0 = 1;
          }
          if (*ch == '\n') {
            strcat(reg_value, "|");
          } else {
            strcat(reg_value, ch);
          }
          prev_ch[0] = ch[0];
        }
        fclose(fp);
        break;
      case 'o':
        sample.print_fragments = true;
        break;
    }
  }
  if (sample.template == false && sample.deus_file == false) {
    strcpy(reg_value, argv[optind]);
    *cur_argv_position = optind + 1;
  } else {
    *cur_argv_position = optind;
  }
  return sample;
}

void printer(int argc, char *argv[], grep_struct result, char line[],
             const char *expression, int reg_state, int cur_argv_position,
             int reg) {
  for (int i = cur_argv_position; i < argc; i++) {
    regex_t reg_buffer;
    regmatch_t matches;
    if (result.ignore_case == true) {
      reg = regcomp(&reg_buffer, expression, REG_ICASE | REG_EXTENDED);
    } else {
      reg = regcomp(&reg_buffer, expression, REG_EXTENDED);
    }
    int lines_counter = 1;
    int match_lines_counter = 0;
    FILE *fp;
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      if (result.no_errors == false) {
        fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
        regfree(&reg_buffer);
      }
      continue;
    }
    while (fgets(line, 1000, fp) != NULL) {
      reg = regexec(&reg_buffer, line, 1, &matches, 0);
      if (reg_state == 1) {
        reg = 0;
      }
      if (reg == 0) {
        match_lines_counter++;
      }
      if (((result.invert == true && reg != 0) ||
           (result.invert == false && reg == 0)) &&
          result.quantity != true && result.show_match_files != true) {
        if (result.match_wo_name == false && argc - cur_argv_position > 1) {
          printf("%s:", argv[i]);
        }
        if (result.line_number == true) {
          printf("%d:", lines_counter);
        }
        if (result.print_fragments == true && result.invert == false) {
          for (int i = matches.rm_so; i < matches.rm_eo; i++) {
            printf("%c", line[i]);
          }
          printf("\n");
          int incr = 0;
          while (reg == 0) {
            char buff[strlen(line) - matches.rm_eo + incr];
            int y = 0;
            for (long unsigned int i = matches.rm_eo + incr + 1;
                 i < strlen(line); i++) {
              buff[y] = line[i];
              y++;
            }
            incr = incr + matches.rm_eo;
            reg = regexec(&reg_buffer, buff, 1, &matches, 0);
            if (reg == 0) {
              for (int i = matches.rm_so; i < matches.rm_eo; i++) {
                printf("%c", buff[i]);
              }
              printf("\n");
            }
          }
        } else {
          printf("%s", line);
          if (strchr(line, '\n') == NULL) {
            printf("\n");
          }
        }
      }
      lines_counter++;
    }
    if (result.show_match_files == true) {
      if (match_lines_counter > 0) {
        if (result.quantity == true) {
          if (argc - cur_argv_position > 1 && result.match_wo_name == false) {
            printf("%s:", argv[i]);
          }
          printf("1\n");
        }
        printf("%s\n", argv[i]);
      } else {
        if (result.quantity == true) {
          printf("%s:", argv[i]);
          printf("0\n");
        }
      }
    }
    if (result.quantity == true && result.show_match_files != true) {
      if (argc - cur_argv_position > 1 && result.match_wo_name == false) {
        printf("%s:", argv[i]);
      };
      if (result.invert == true) {
        printf("%d\n", lines_counter - match_lines_counter - 1);
      } else {
        printf("%d\n", match_lines_counter);
      }
    }
    fclose(fp);
    lines_counter = 1;
    match_lines_counter = 0;
    regfree(&reg_buffer);
  }
}

int main(int argc, char *argv[]) {
  int cur_argv_position = 0;
  int reg_state = 0;
  char line[1000];
  char reg_value[1000];
  grep_struct result =
      options_parser(argc, argv, reg_value, &cur_argv_position, &reg_state);
  int reg = 0;
  const char *expression = reg_value;
  printer(argc, argv, result, line, expression, reg_state, cur_argv_position,
          reg);
  return 0;
}