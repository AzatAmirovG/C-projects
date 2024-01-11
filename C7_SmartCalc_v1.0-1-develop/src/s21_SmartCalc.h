#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102
#define INCORRECT_INPUT 000

typedef struct token {
  int value;
  int priority;
  int unary_binary;
  struct token *next;
} Token_input;

typedef struct token_n {
  double value;
  struct token_n *next;
} Token_output;

typedef struct token_t {
  double num_value;
  int priority;
  int unary;
  int type;
} Token_total;

typedef enum {
  OPENED,
  DEFAULT,
  PLUS_MINUS,
  MUL_DIV,
  POW_MOD,
  TRIGO,
  UNARY
} priority;

typedef enum {
  NUMBER,
  PLUS,
  MINUS,
  MUL,
  DIV,
  POW,
  MOD,
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG,
  OPEN_BRACKET,
  CLOSE_BRACKET,
  UN_PLUS,
  UN_MINUS,
  VAR
} type;

void s21_push(Token_input **top, Token_total *operators, int unary);
char s21_pop(Token_input **top);
void s21_push_number(Token_output **top, double number);
double s21_pop_number(Token_output **top);
void s21_move_from_stack(Token_total *line, Token_input **top, int i);

int s21_inflix_to_struct(char *input_line, Token_total *line, int *count);
int s21_from_struct_to_post(Token_total *input_line, Token_total *line,
                            int counter);
double s21_post_to_result(Token_total *line, int counter);

int s21_check_first_last(char symbol);
int s21_initialiase_operator(Token_total *line, char operators, int i,
                             int un_bi);
int s21_initialiase_trigo_operator(Token_total *line, char *input_line,
                                   int input_counter, int output_counter,
                                   int *leap);
int s21_initialise_number(Token_total *line, char *input_line,
                          int input_counter, int output_counter, int *leap);

double s21_operators1(double first, int operators);
double s21_operators2(double second, double first, int operators);

int calculation(char *input_line, double *res);
double s21_calculation_graph(Token_total *line, int count, double x);
