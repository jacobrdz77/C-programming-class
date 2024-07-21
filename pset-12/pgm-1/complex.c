#include <stdio.h>
#include <stdlib.h>

#include "complex.h"
Complex getComplex(FILE *fp) {
  Complex c;

  fscanf(fp, "%lf%lfi", &c.real, &c.imaginary);

  return c;
}

// writes a complex number to a file pointer, including stdout
void writeComplex(const Complex *const this, FILE *fp) {
  if (this->real == 0 && this->imaginary == 0) {
    fprintf(fp, "%.2lf\n", this->real);
    return;
  }
  if (this->real == 0) {
    fprintf(fp, "%.2lfi\n", this->imaginary);
    return;
  }
  if (this->imaginary == 0) {
    fprintf(fp, "%.2lf\n", this->real);
    return;
  }

  if (this->imaginary >= 0) {
    fprintf(fp, "%.2lf+%.2lfi\n", this->real, this->imaginary);
  } else {
    fprintf(fp, "%.2lf%.2lfi\n", this->real, this->imaginary);
  }
}

// adds two complex numbers
Complex Add(const Complex *const p, const Complex *const q) {

  Complex result;
  result.real = p->real + q->real;
  result.imaginary = p->imaginary + q->imaginary;
  return result;
}

// multiplies two complex numbers
Complex Multiply(const Complex *const p, const Complex *const q) {
  Complex result;
  result.real = p->real * q->real - p->imaginary * p->imaginary;
  result.imaginary = p->real * q->imaginary - p->imaginary * q->real;
  return result;
}

// copies value into this
void Copy(Complex *const this, const Complex *const value) {
  this->imaginary = value->imaginary;
  this->real = value->real;
}