#include <string.h>

#include "../s21_SmartCalc.h"

double s21_post_to_result(Token_total *line, int counter) {
  Token_output *head = NULL;
  int i = 0;
  while (i < counter) {
    if (line[i].type == 0 || line[i].type == 20) {
      s21_push_number(&head, line[i].num_value);
    } else {
      double two = s21_pop_number(&head);
      double res = 0.0;
      if (line[i].type > 6) {
        res = s21_operators1(two, line[i].type);
      } else {
        double one = s21_pop_number(&head);
        res = s21_operators2(two, one, line[i].type);
      }
      s21_push_number(&head, res);
    }
    i++;
  }
  return s21_pop_number(&head);
}

// int main(){
//     //char str1[255] = "342343*(35645-(231-343^2)+435)*(234+342)=";
//     //char str1[255] = "35645-(231%3-343^2)+435=";
//     int i = 0;
//     //char str1[255] = "10-20+5=";
//     char str1[255] = "4+(3-4)*(10%2-5^2)+10=";
//     Token_total line[255] = {};
//     i = s21_RPN(str1, line);
//     printf("%d\n", i);
//     //printf("values are %f %f %d\n", line[0].num_value, line[1].num_value,
//     line[2].type); double res = s21_post_to_result2(line, i); printf("%f",
//     res);
// }
