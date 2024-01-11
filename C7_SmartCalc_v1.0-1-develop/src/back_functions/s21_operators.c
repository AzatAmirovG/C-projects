#include "../s21_SmartCalc.h"

double s21_operators2(double second, double first, int operators) {
  double result = 0;
  switch (operators) {
    case 1:
      result = second + first;
      break;
    case 2:
      result = first - second;
      break;
    case 3:
      result = second * first;
      break;
    case 4:
      result = first / second;
      break;
    case 6:
      result = fmod(first, second);
      break;
    case 5:
      result = pow(first, second);
      break;
  }
  return result;
}

double s21_operators1(double first, int operators) {
  double result = 0;
  switch (operators) {
    case 7:
      result = cos(first);
      break;
    case 8:
      result = sin(first);
      break;
    case 9:
      result = tan(first);
      break;
    case 10:
      result = acos(first);
      break;
    case 11:
      result = asin(first);
      break;
    case 12:
      result = atan(first);
      break;
    case 13:
      result = sqrt(first);
      break;
    case 14:
      result = log(first);
      break;
    case 15:
      result = log10(first);
      break;
    case 19:
      result = first * (-1);
      break;
  }
  return result;
}
