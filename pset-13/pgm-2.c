#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int number;
  char name[15];
  char symbol[4];
  char class[50];
  double weight;
  int shells[7];

} element_t;

void printElements(const element_t e[], const int count, FILE *outfile);

void writeElements(const element_t e[], const int count,
                   const char *const filename, const bool binary);

int main() {
  srand(time(NULL));
  element_t randElements[10];

  for (int i = 0; i < 10; i++) {
    int randNum1 = (rand() % 118) + 1;
    int randNum2 = (rand() % 10) + 1;
    int randElectrons = (rand() % 7) + 1;
    randElements[i].number = randNum1;
    sprintf(randElements[i].name, "Element %d", randNum1);
    sprintf(randElements[i].symbol, "E%d", randNum2);
    sprintf(randElements[i].class, "class", randNum1);
    randElements[i].weight = 10.0 + randNum1;
    for (int j = 0; j < 7; j++) {
      randElements[i].shells[j] = randElectrons;
    }
  }

  writeElements(randElements, 10, "elements.txt", false);
  writeElements(randElements, 10, "elements.bin", true);

  return 0;
}

void printElements(const element_t e[], const int count, FILE *outfile) {
  if (outfile == NULL) {
    perror("error file is null");
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(outfile,
            "#%d %s:\n\t\twt: %.2lf, symbol: %s, class:%s\n\t\tshells: ",
            e[i].number, e[i].name, e[i].weight, e[i].symbol, e[i].class);
    for (int j = 0; j < 7; j++) {
      fprintf(outfile, "%d  ", e[i].shells[j]);
    }
    fprintf(outfile, "\n");
  }
}

void writeElements(const element_t e[], const int count,
                   const char *const filename, const bool binary) {
  FILE *file = fopen(filename, binary ? "wb" : "w");
  if (file == NULL) {
    fprintf(stdout, "error opening file\n");
    return;
  }

  //* Writes to binary file
  if (binary) {
    for (int i = 0; i < count; i++) {
      size_t size = fwrite(&e[i], sizeof(e[i]), 1, file);
      if (size < 1) {
        fprintf(stdout, "error writing to binary file\n");
        fclose(file);
        return;
      }
    }
    fclose(file);
    return;
  }

  //* Writes to text file
  for (int i = 0; i < count; i++) {
    fprintf(file,
            "#%d %s:\nwt:%.2lf, symbol:%s, class:%s\n\t\tshells: ", e[i].number,
            e[i].name, e[i].weight, e[i].symbol, e[i].class);
    for (int j = 0; j < 7; j++) {
      fprintf(file, "%d ", e[i].shells[j]);
    }
    fprintf(file, "\n");
  }
  fclose(file);
}

/*
Program #2
Elemental, Part II
Using the structure type element_t from PSET-11, populate an array of 10
elements with information.  This can be done by data entry, a combination of
some manual entry and random generation, or by hard-coding values in your
program.

Sample data can be found here:

First 10 ElementsLinks to an external site.

Output all 10 elements into two different files:

elements.txt, which is a text file, and should have human-readable values
elements.bin, which is a binary file
A recommended function declaration for writing these files is:

void writeElements(
    const element_t e[],
    const int count,
    const char* const filename,
    const bool binary);
Your program may use this, or similar means to process the data.

A handy function declaration to output elements is provided here:

void printElements(
    const element_t e[],
    const int count,
    FILE* outfile);
The printElements function could be used for outputting human-readable ASCII to
the console (stdout) or to a text file.
*/