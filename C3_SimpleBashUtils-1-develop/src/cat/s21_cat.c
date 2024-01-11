#include "s21_cat.h"

Options Parser(int argc, char *argv[], int *find_flag, int *cur_argv_position) {
  Options sample = {
      false, false, false, false, false, false,
  };
  int spisok_flags = 0;
  struct option long_opt[] = {{"number-nonblank", 0, NULL, 'b'},
                              {"number", 0, NULL, 'n'},
                              {"squeeze-blank", 0, NULL, 's'},
                              {NULL, 0, NULL, 0}};
  spisok_flags = getopt_long(argc, argv, "benstvET", long_opt, NULL);
  for (; spisok_flags != -1;
       spisok_flags = getopt_long(argc, argv, "benstvET", long_opt, NULL)) {
    switch (spisok_flags) {
      case 'b':
        sample.flag_b = true;
        *find_flag = 1;
        break;
      case 'e':
        sample.flag_v = true;
        sample.flag_dollar = true;
        *find_flag = 1;
        break;
      case 'v':
        sample.flag_v = true;
        *find_flag = 1;
        break;
      case 'n':
        sample.flag_n = true;
        *find_flag = 1;
        break;
      case 's':
        sample.flag_s = true;
        *find_flag = 1;
        break;
      case 't':
        sample.flag_v = true;
        sample.tabs = true;
        *find_flag = 1;
        break;
      case 'E':
        sample.flag_dollar = true;
        *find_flag = 1;
        break;
      case 'T':
        sample.tabs = true;
        *find_flag = 1;
        break;
      default:
        *find_flag = 2;
    }
    *cur_argv_position = optind;
  }
  return sample;
}

void print_char(char line[], Options result) {
  for (unsigned int i = 0; i < strlen(line); i++) {
    unsigned char cur_ch = line[i];
    if ((cur_ch == 10) && (result.flag_dollar == true)) {
      printf("$\n");
    } else if ((cur_ch == 9) && (result.tabs == true)) {
      printf("^I");
    } else if (result.flag_v == true) {
      if (cur_ch <= 31 && cur_ch != 9 && cur_ch != 10) {
        printf("^%c", 64 + cur_ch);
      } else if ((cur_ch >= 128) && (cur_ch <= 159)) {
        printf("M-^%c", 64 + (cur_ch - 128));
      } else if (cur_ch >= 160 && cur_ch <= 254) {
        printf("M-%c", 32 + (cur_ch - 160));
      } else if (cur_ch == 127) {
        printf("^?");
      } else {
        printf("%c", cur_ch);
      }
    } else {
      printf("%c", cur_ch);
    }
  }
}

void total_func(int argc, char *argv[], int cur_argv_position, Options result) {
  char prev_line[1000];
  for (int i = cur_argv_position; i < argc; i++) {
    char line[1000];
    int printed_lines_counter = 1;
    int blank_line = 0;
    int permission_to_print = 1;
    FILE *fp;
    fp = fopen(argv[i], "r");

    while ((fgets(line, 1000, fp)) != NULL) {
      if (strcmp(line, "\n") == 0) {
        blank_line = 1;
      } else {
        blank_line = 0;
      }
      if ((result.flag_s) && (blank_line == 1) &&
          ((strcmp(line, prev_line)) == 0)) {
        permission_to_print = 0;
      } else {
        permission_to_print = 1;
      }
      if (permission_to_print == 1) {
        if (result.flag_n || (result.flag_b && blank_line == 0)) {
          printf("%6d\t", printed_lines_counter);
          printed_lines_counter++;
        }
        if (result.flag_dollar || result.flag_v || result.tabs) {
          print_char(line, result);
        } else {
          printf("%s", line);
        }
      }
      strcpy(prev_line, line);
    }
  }
}

int main(int argc, char **argv) {
  int find_flag = 0;
  int cur_argv_position;
  char cur_ch;
  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    Options result = Parser(argc, argv, &find_flag, &cur_argv_position);
    if (find_flag == 2) {
      printf("Illegal option %s", argv[cur_argv_position]);
      exit(1);
    } else {
      if (find_flag == 1) {
        if (result.flag_b == true) {
          result.flag_n = false;
        }
        total_func(argc, argv, cur_argv_position, result);
      } else if (find_flag == 0) {
        FILE *fp;
        fp = fopen(argv[cur_argv_position + 1], "r");
        while ((cur_ch = fgetc(fp)) != EOF) {
          printf("%c", cur_ch);
        }
        fclose(fp);
      }
    }
  } else {
    while ((cur_ch = fgetc(fp)) != EOF) {
      printf("%c", cur_ch);
    }
    fclose(fp);
    if (argc == 3) {
      fprintf(stderr, "cat: %s: No such file or directory\n", argv[2]);
    }
  }
  return 0;
}
