#include "../s21_SmartCalc.h"

int s21_inflix_to_struct(char *input_line, Token_total *line, int *count) {
  int check = 0;
  int is_open = 0;
  int i = 0;
  int leap = 0;
  if (s21_check_first_last(input_line[i])) {
    check = 1;
  }
  while (input_line[i] != '=') {
    if (strchr("0123456789.", input_line[i])) {
      if (s21_initialise_number(line, input_line, i, *count, &leap)) {
        check = 1;
      }
      i = i + leap;
    } else if (input_line[i] == 'x') {
      line[*count].type = VAR;
    } else if ((input_line[i] == '-' || input_line[i] == '+') &&
               ((i != 0 && input_line[i - 1] == '(') || (i == 0))) {
      s21_initialiase_operator(line, input_line[i], *count, 1);
    } else if (strchr("-+*/^\%", input_line[i])) {
      if (s21_initialiase_operator(line, input_line[i], *count, 0)) {
        check = 1;
      }
    } else if (strchr("asctl", input_line[i])) {
      if (s21_initialiase_trigo_operator(line, input_line, i, *count, &leap)) {
        check = 1;
      }
      i = i + leap;
    } else if (input_line[i] == '(') {
      if (*count > 0 &&
          (line[*count - 1].type == 0 || line[*count - 1].type == 20)) {
        check = 1;
      }
      is_open++;
      line[*count].type = OPEN_BRACKET;
    } else if (strchr(")", input_line[i])) {
      if (is_open > 0) {
        line[*count].type = CLOSE_BRACKET;
        is_open--;
      } else {
        check = 1;
      }
    }
    *count = *count + 1;
    i++;
    leap = 0;
  }
  if (s21_check_first_last(input_line[i - 1]) || is_open > 0) {
    check = 1;
  }
  return check;
}