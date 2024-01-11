#include <stdlib.h>

#include "../s21_SmartCalc.h"

void s21_push(Token_input **top, Token_total *operators, int unary) {
  Token_input *tmp = malloc(sizeof(Token_input));
  if (tmp == NULL) {
    exit(STACK_OVERFLOW);
  }
  tmp->priority = operators->priority;
  tmp->next = *top;
  tmp->value = operators->type;
  tmp->unary_binary = unary;
  *top = tmp;
}

char s21_pop(Token_input **top) {
  if (*top == NULL) {
    exit(STACK_UNDERFLOW);
  }
  Token_input *last = *top;
  char operator= last->value;
  *top = (*top)->next;
  free(last);
  return operator;
}

void s21_move_from_stack(Token_total *line, Token_input **top, int i) {
  line[i].type = (*top)->value;
  line[i].priority = (*top)->priority;
  line[i].unary = (*top)->unary_binary;
}

void s21_push_number(Token_output **top, double number) {
  Token_output *tmp = malloc(sizeof(Token_output));
  if (tmp == NULL) {
    exit(STACK_OVERFLOW);
  }
  tmp->next = *top;
  tmp->value = number;
  *top = tmp;
}

double s21_pop_number(Token_output **top) {
  if (*top == NULL) {
    exit(STACK_UNDERFLOW);
  }
  Token_output *last = *top;
  double number = last->value;
  *top = (*top)->next;
  free(last);
  return number;
}