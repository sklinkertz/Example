/********************************************************************************************************************************
Author: Simon Klinkertz
Date:   23.10.2015
********************************************************************************************************************************/

#include <stdio.h>

int main(void) {
  int a, b;
  char operation;

  // get the numbers from the console
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);

  
  printf("Enter a operation: ");
  scanf(" %c", &operation);

  int erg;
  float ergfloat;

  switch (operation) {
    case '+':
      // Addition
      erg = a + b;
      printf("The sum of both numbers is %d.\n", erg);
      break;
    case '-':
      // Subtraction
      erg = a - b;
      printf("The difference of both numbers is %d.\n", erg);
      break;
    case '*':
      // Multiplication
      erg = a * b;
      printf("The product of both numbers is %d.\n", erg);
      break;
    case '/':
      // Division   -> (float) var casts a variable from int to float (temporarily)
      ergfloat = (float) a / (float) b;
      printf("The quotient of both numbers is %f.\n", ergfloat);
      break;
    case '%':
      // Modulo
      erg = a % b;
      printf("%d mod %d is %d.\n", a, b, erg);
      break;
    default:
      // Default Case
      printf("You entered a wrong operation!\n");
      break;
  }
  return 0;
}