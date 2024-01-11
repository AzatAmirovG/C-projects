#include "../s21_SmartCalc.h"

int s21_initialiase_operator(Token_total *line, char operators, int i,
                             int un_bi) {
  int check = 0;
  if (i != 0 && (line[i - 1].type >= 1 && line[i - 1].type <= 6)) {
    return check = 1;
  }
  switch (operators) {
    case '+':
      line[i].type = PLUS;
      break;
    case '-':
      if (un_bi) {
        line[i].type = UN_MINUS;
      } else {
        line[i].type = MINUS;
      }
      break;
    case '*':
      line[i].type = MUL;
      break;
    case '/':
      line[i].type = DIV;
      break;
    case '%':
      line[i].type = MOD;
      break;
    case '^':
      line[i].type = POW;
      break;
  }
  if (line[i].type <= 2) {
    line[i].priority = PLUS_MINUS;
  } else if (line[i].type <= 4) {
    line[i].priority = MUL_DIV;
  } else if (line[i].type <= 6) {
    line[i].priority = POW_MOD;
  } else if (line[i].type == UN_MINUS) {
    line[i].priority = MUL_DIV;
  }
  line[i].unary = un_bi;

  return check;
}

int s21_initialiase_trigo_operator(Token_total *line, char *input_line,
                                   int input_counter, int output_counter,
                                   int *leap) {
  int check = 0;
  if (output_counter > 0 && (line[output_counter - 1].type == 0 ||
                             line[output_counter - 1].type == 20)) {
    return check = 1;
  }
  int i = input_counter;
  char tmp[6] = "";
  for (int j = 0; j < 5; j++) {
    tmp[j] = input_line[i];
    if (input_line[i] == '(') {
      *leap = j - 1;
    }
    i++;
  }
  tmp[5] = '\0';
  switch (input_line[input_counter]) {
    case 'a':
      if (!strncmp("acos(", tmp, 5)) {
        line[output_counter].type = ACOS;
      } else if (!strncmp("asin(", tmp, 5)) {
        line[output_counter].type = ASIN;
      } else if (!strncmp("atan(", tmp, 5)) {
        line[output_counter].type = ATAN;
      } else {
        check = 1;
      }
      break;
    case 'c':
      if (!strncmp("cos(", tmp, 4)) {
        line[output_counter].type = COS;
      } else {
        check = 1;
      }
      break;
    case 's':
      if (!strncmp("sin(", tmp, 4)) {
        line[output_counter].type = SIN;
      } else if (!strncmp("sqrt(", tmp, 5)) {
        line[output_counter].type = SQRT;
      } else {
        check = 1;
      }
      break;
    case 'l':
      if (!strncmp("log(", tmp, 4)) {
        line[output_counter].type = LOG;
      } else if (!strncmp("ln(", tmp, 3)) {
        line[output_counter].type = LN;
      } else {
        check = 1;
      }
      break;
    case 't':
      if (!strncmp("tan(", tmp, 4)) {
        line[output_counter].type = TAN;
      } else {
        check = 1;
      }
      break;
  }
  line[output_counter].priority = TRIGO;
  line[output_counter].unary = 1;
  return check;
}

int s21_initialise_number(Token_total *line, char *input_line,
                          int input_counter, int output_counter, int *leap) {
  int check = 0;
  int i = input_counter;
  int point = 0;
  char tmp[255] = "";
  char tmp2[2];
  tmp2[1] = '\0';
  while (strchr("0123456789.", input_line[i]) != NULL) {
    tmp2[0] = input_line[i];
    strcat(tmp, tmp2);
    if (input_line[i] == '.') {
      point = 1;
    }
    i++;
    *leap = *leap + 1;
    if (input_line[i] == '.' && point == 1) {
      check = 1;
    }
  }
  *leap = *leap - 1;
  line[output_counter].num_value = atof(tmp);
  line[output_counter].type = NUMBER;
  return check;
}

int s21_check_first_last(char symbol) {
  int check = 0;
  if (strchr("*/^\%", symbol)) {
    check = 1;
  }
  return check;
}
