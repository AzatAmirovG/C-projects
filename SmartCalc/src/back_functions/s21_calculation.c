#include <string.h>

#include "../s21_SmartCalc.h"

double s21_calculation_graph(Token_total *line, int count, double x) {
  int lexems_count = count;
  int i = 0;
  double res = 0.0;
  Token_total line2[255] = {};
  for (int i = 0; i < lexems_count; i++) {
    if (line[i].type == 20) {
      line[i].num_value = x;
    }
  }
  i = s21_from_struct_to_post(line, line2, lexems_count);
  res = s21_post_to_result(line2, i);
  return res;
}

int calculation(char *input_line, double *res) {
  int lexems_count = 0;
  int check = 0;
  int i = 0;
  Token_total line[255] = {};
  Token_total line2[255] = {};
  check = s21_inflix_to_struct(input_line, line, &lexems_count);
  if (!check) {
    i = s21_from_struct_to_post(line, line2, lexems_count);
    *res = s21_post_to_result(line2, i);
  }
  return check;
}

// int main(){
//   //char *str =
//   "(-sin(0.5)+cos(0.5)+tan(0.5)+atan(0.5)+acos(0.5)+asin(0.5)*5)/0.3^2+sqrt(9)-7%3-5+ln(3)-log(2)=";
//       //int lexems_count = 0;
// //char *str = "-0.456+4*2*sin(45)/2*(4+8)-ln(45)=";
//  char *str = "25+3=";
//  double solve = 0.0;
//   calculation(str, &solve);
// printf("%f", solve);
// //   int check = 0;
// //     //int i = 0;
// //     //double res = 0.0;
// //     Token_total line[255] = {};
// //     //Token_total line2[255] = {};
// //     check  = s21_inflix_to_struct(str, line, &lexems_count);
// //        printf("%d", check);
// }
