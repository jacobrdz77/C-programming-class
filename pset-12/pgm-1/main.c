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

/*
Program #1
Complex Number Library
A complex number is one that contains a real and imaginary component of the
form:

A + Bi

Create a library called complex.h in your code.  It should include the type
declaration for a complex number data type named Complex.  It should also
declare the following functions:

Complex getComplex(FILE* fp); // reads a complex number from a file pointer,
including stdin void writeComplex(const Complex* const this, FILE* fp); //
writes a complex number to a file pointer, including stdout Complex Add(const
Complex* const p, const Complex* const q); // adds two complex numbers Complex
Multiply(const Complex* const p, const Complex* const q); // multiplies two
complex numbers void Copy(Complex* const this, const Complex* const value); //
copies value into this


Implementation of these functions should be in a separate source file:
complex.c.  Your solution must also include a main.c file, which impelments only
the main() function.

Your program must:

#include the complex.h header file
Implement the functions in complex.h in a separate file, complex.c
Compile main.c and complex.c into a single executable
Output all elements in the ca array to output:
 Complex ca[] = {
        { .real = 0, .imaginary = 0 },
        { .real = 1, .imaginary = 0 },
        { .real = -1, .imaginary = 0 },
        { .real = 0, .imaginary = 3 },
        { .real = 0, .imaginary = -4 },
        { .real = 2, .imaginary = 3 },
        { .real = 2, .imaginary = -4 },
        { .real = -5, .imaginary = 3 },
        { .real = -5, .imaginary = -4 },
    };
Get two complex numbers and output each to stdout
Add the two complex numbers, output the result to stdout
Multiply the two complex numbers, output the result to stdout
Copy the second complex number to the first, output them both stdout
Note: Examples of valid complex numbers are as follows:

3.2 + 4.2i; 3.7 - 5.9i; 6; 8.4i; 0

Sample output:

ca[0]=0.00
ca[1]=1.00
ca[2]=-1.00
ca[3]=3.00i
ca[4]=-4.00i
ca[5]=2.00+3.00i
ca[6]=2.00-4.00i
ca[7]=-5.00+3.00i
ca[8]=-5.00-4.00i
Enter complex # in the form A±Bi:1+2i
Enter complex # in the form A±Bi:3-4i
1st Complex:1.00+2.00i
2nd Complex:3.00-4.00i
     Addition:4.00-2.00i
Multiplcation:11.00+2.00i
Copying....
1st Complex:3.00-4.00i
2nd Complex:3.00-4.00i
*/