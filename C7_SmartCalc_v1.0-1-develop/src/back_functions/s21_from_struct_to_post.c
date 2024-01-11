#include "../s21_SmartCalc.h"

int s21_from_struct_to_post(Token_total *input_line, Token_total *line,
                            int counter) {
  int output_counter = 0;
  int count_of_stack = 0;
  Token_input *head = NULL;
  int i = 0;
  while (i < counter) {
    if (input_line[i].type == NUMBER || input_line[i].type == VAR) {
      line[output_counter] = input_line[i];
      output_counter++;
    } else if ((input_line[i].type >= 1 && input_line[i].type <= 15) ||
               input_line[i].type == 19) {
      if (count_of_stack > 0 &&
          !(input_line[i].type == POW && head->value == POW)) {
        while ((count_of_stack > 0) &&
               (head->priority >= input_line[i].priority) &&
               head->value != OPEN_BRACKET) {
          s21_move_from_stack(line, &head, output_counter);
          s21_pop(&head);
          count_of_stack--;
          output_counter++;
        }
      }
      s21_push(&head, &input_line[i], input_line[i].unary);
      count_of_stack++;
    } else if (input_line[i].type == OPEN_BRACKET) {
      s21_push(&head, &input_line[i], 0);
      count_of_stack++;
    } else if (input_line[i].type == CLOSE_BRACKET) {
      while (head->value != OPEN_BRACKET) {
        s21_move_from_stack(line, &head, output_counter);
        s21_pop(&head);
        count_of_stack--;
        output_counter++;
      }
      s21_pop(&head);
      count_of_stack--;
    } else if (input_line[i].priority == UNARY) {
      s21_push(&head, &input_line[i], 1);
      count_of_stack++;
    }
    i++;
  }
  while (count_of_stack > 0) {
    s21_move_from_stack(line, &head, output_counter);
    s21_pop(&head);
    count_of_stack--;
    output_counter++;
  }
  return output_counter;
}
