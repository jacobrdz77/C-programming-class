#include <stdbool.h>
#include <stdio.h>

typedef struct {
  int number;
  char name[15];
  char symbol[4];
  char class[50];
  double weight;
  int shells[7];

} element_t;
void readElements(element_t e[], const int count, const char *const filename,
                  const bool binary);

void printElements(const element_t e[], const int count, FILE *outfile);

int main() {
  const int count = 10;
  element_t elements[count];

  // Read elements from text file
  readElements(elements, count, "elements.txt", false);
  printf("======\nASCII Deserialization:\n========\n");
  printElements(elements, count, stdout);

  // Read elements from binary file
  readElements(elements, count, "elements.bin", true);
  printf("======\nBinary Deserialization:\n========\n");
  printElements(elements, count, stdout);

  return 0;
  return 0;
}

void readElements(element_t e[], const int count, const char *const filename,
                  const bool binary) {
  FILE *file = fopen(filename, binary ? "rb" : "r");
  if (file == NULL) {
    fprintf(stdout, "error opening file\n");
    return;
  }

  // deserialize binary
  if (binary) {
    for (int i = 0; i < count; i++) {
      size_t size = fread(&e[i], sizeof(e[i]), 1, file);
      if (size < 1) {
        fprintf(stdout, "error writing to binary file\n");
        fclose(file);
        return;
      }
    }
    fclose(file);
    return;
  }

  // deserialize text file
  for (int i = 0; i < count; i++) {
    fscanf(file, "#%d ", &e[i].number);
    fscanf(file, "%14s", e[i].name);
    fscanf(file, " wt:%lf", &e[i].weight);
    fscanf(file, " symbol:%3s", e[i].symbol);
    fscanf(file, " class:%49s", e[i].class);
    fscanf(file, " shells: %d %d %d %d %d %d %d \n", &e[i].shells[0],
           &e[i].shells[1], &e[i].shells[2], &e[i].shells[3], &e[i].shells[4],
           &e[i].shells[5], &e[i].shells[6]);
  }
  fclose(file);
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
/*
Program #3
Elemental, Part III (aka Eat Your Dogfood)
Well, yes, you knew this was coming: write a program that will read in all of
the element_t values from the files created in Program #2 and output them to
stdout.  There should be two separate loops, displaying the same set of values.
The first loop will read values from elements.txt and output them to stdout; the
second must read values from elements.bin and output them to stdout.

The code that reads from elements.txt must deserialize file contents into
entities of the element_t type and then print these to stdout.  The outputs
should be human-readable.

void readElements(
    element_t e[],
    const int count,
    const char* const filename,
    const bool binary);
The printElements funtion from Program 2 should be copy-pasted to get familiar
output to the console.

Sample output:

======
ASCII Deserialiation:
========
#1 Hydrogen:
        wt: 1.01, symbol: H, class:nonmetal
        shells:  1  0  0  0  0  0  0
#2 Helium:
        wt: 4.20, symbol: He, class:noble gas
        shells:  2  0  0  0  0  0  0
#3 Lithium:
        wt: 6.94, symbol: Li, class:alkali metal
        shells:  2  1  0  0  0  0  0
#4 Beryllium:
        wt: 9.01, symbol: Be, class:alkaline earth metal
        shells:  2  2  0  0  0  0  0
#5 Boron:
        wt: 10.81, symbol: B, class:nmetalloid
        shells:  2  3  0  0  0  0  0
#6 Carbon:
        wt: 12.01, symbol: C, class:nonmetal
        shells:  2  4  0  0  0  0  0
#7 Nitrogen:
        wt: 14.01, symbol: N, class:nonmetal
        shells:  2  5  0  0  0  0  0
#8 Oxygen:
        wt: 16.00, symbol: O, class:nonmetal
        shells:  2  6  0  0  0  0  0
#9 Fluorine:
        wt: 19.00, symbol: F, class:hallogen
        shells:  2  7  0  0  0  0  0
#10 Neon:
        wt: 1.01, symbol: Ne, class:noble gas
        shells:  2  8  0  0  0  0  0
======
Binary Deserialiation:
========
#1 Hydrogen:
        wt: 1.01, symbol: H, class:nonmetal
        shells:  1  0  0  0  0  0  0
#2 Helium:
        wt: 4.20, symbol: He, class:noble gas
        shells:  2  0  0  0  0  0  0
#3 Lithium:
        wt: 6.94, symbol: Li, class:alkali metal
        shells:  2  1  0  0  0  0  0
#4 Beryllium:
        wt: 9.01, symbol: Be, class:alkaline earth metal
        shells:  2  2  0  0  0  0  0
#5 Boron:
        wt: 10.81, symbol: B, class:nmetalloid
        shells:  2  3  0  0  0  0  0
#6 Carbon:
        wt: 12.01, symbol: C, class:nonmetal
        shells:  2  4  0  0  0  0  0
#7 Nitrogen:
        wt: 14.01, symbol: N, class:nonmetal
        shells:  2  5  0  0  0  0  0
#8 Oxygen:
        wt: 16.00, symbol: O, class:nonmetal
        shells:  2  6  0  0  0  0  0
#9 Fluorine:
        wt: 19.00, symbol: F, class:hallogen
        shells:  2  7  0  0  0  0  0
#10 Neon:
        wt: 1.01, symbol: Ne, class:noble gas
        shells:  2  8  0  0  0  0  0
*/