#include "complex.h"
#include <stdio.h>

int main() {

  Complex ca[] = {
      {.real = 0, .imaginary = 0},   {.real = 1, .imaginary = 0},
      {.real = -1, .imaginary = 0},  {.real = 0, .imaginary = 3},
      {.real = 0, .imaginary = -4},  {.real = 2, .imaginary = 3},
      {.real = 2, .imaginary = -4},  {.real = -5, .imaginary = 3},
      {.real = -5, .imaginary = -4},
  };

  int length = sizeof(ca) / sizeof(ca[0]);

  for (int i = 0; i < length; i++) {
    printf("ca[%d]=", i);
    writeComplex(&ca[i], stdout);
  }

  Complex c1, c2;
  printf("Enter complex # in the form A+-Bi:");
  c1 = getComplex(stdin);
  printf("Enter complex # in the form A+-Bi:");
  c2 = getComplex(stdin);

  printf("1st Complex:");
  writeComplex(&c1, stdout);
  printf("2st Complex:");
  writeComplex(&c2, stdout);

  Complex addResult;
  addResult = Add(&c1, &c2);
  printf("\tAddition:");
  writeComplex(&addResult, stdout);

  Complex multResult;
  printf("\tMultiplication:");
  multResult = Multiply(&c1, &c2);
  writeComplex(&multResult, stdout);

  printf("Copying...\n");
  Copy(&c1, &c2);

  printf("1st Complex:");
  writeComplex(&c1, stdout);
  printf("2st Complex:");
  writeComplex(&c2, stdout);

  return 0;
}
