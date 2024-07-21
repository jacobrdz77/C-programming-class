#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

typedef struct {
  double real;
  double imaginary;
} Complex;

Complex getComplex(FILE *fp);
void writeComplex(const Complex *const this, FILE *fp);
Complex Add(const Complex *const p, const Complex *const q);
Complex Multiply(const Complex *const p, const Complex *const q);
void Copy(Complex *const this, const Complex *const value);

#endif