#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float standardDeviation(const unsigned short scores[], const float mean,
                        const unsigned short count);
int main() {
  srand(time(NULL));
  int numRolls;
  int numDice;
  int maxSize = numDice * 6;
  int *tally = (int *)calloc(maxSize, sizeof(int));

  do {
    printf("Enter a number of iterations(N): ");
    scanf("%d", &numRolls);
    if (numRolls <= 0) {
      printf("**Invalid input, select a value > 0\n");
    }
  } while (numRolls <= 0);

  do {
    printf("Number of d6 on each roll (D): ");
    scanf("%d", &numDice);
    if (numDice <= 0) {
      printf("**Invalid input, select a value > 0\n");
    }
  } while (numDice <= 0);

  printf("Generating %d rolls...\n", numRolls);
  for (int i = 0; i < numRolls; i++) {
    int sum = 0;
    for (int j = 0; j < numDice; j++) {
      sum += (rand() % 6) + 1;
    }
    tally[sum - 2]++;
  }

  printf("=================================\n");

  // iterates through the tally array and prints the histogram
  for (int i = 0; i < maxSize; i++) {
    float percentage = ((float)tally[i] / numRolls) * 100;
    printf("%02d -- %3d (%5.2f%%):", i + 2, tally[i], percentage);
    for (int j = 0; j < (int)percentage; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

float standardDeviation(const unsigned short scores[], const float mean,
                        const unsigned short count) {
  float summation = 0.0;

  for (int i = 0; i < count; i++) {
    float absoluteValue = abs(scores[i] - mean);
    summation += powf(absoluteValue, 2);
  }

  return sqrtf(summation / 2);
}
/*
Program #1
Histograms, Part II
Refer back to the code you wrote or solutions to PSET-08 Programs #2 and #3.
Write a program that queries the user for two inputs:

N - the number of iterations to be run
D - the number of 6-sided dice to roll on each iteration

Record a tally for the value of each roll in a dynamically allocated array.  The
size of the array will vary based on the maximum possible value for a given
roll. e.g., if we roll 2 dice, the maximum possible index is 12, for five, it is
30: the basic formula for the maximum possible index is

D * 6

Recall, however, that arrays are 0-indexed, so adjust your allocation
accordingly.

Your output should include a histogram, with total count, percentage, and a
horizontal bar based on percentage.

Your output should also include the Standard Deviation for the set of values.

standard deviation formula: sd = sqrt(sum-of-squares/N)

Sample output:

Enter number of iterations (N):150
Number of d6 on each roll (D):3
==========================
03 --   0 ( 0.00%) :
04 --   3 ( 2.00%) :**
05 --   3 ( 2.00%) :**
06 --   6 ( 4.00%) :****
07 --  11 ( 7.33%) :*******
08 --  21 (14.00%) :**************
09 --  15 (10.00%) :**********
10 --  16 (10.67%) :***********
11 --  22 (14.67%) :***************
12 --  17 (11.33%) :***********
13 --  11 ( 7.33%) :*******
14 --   9 ( 6.00%) :******
15 --   8 ( 5.33%) :*****
16 --   7 ( 4.67%) :*****
17 --   1 ( 0.67%) :*
18 --   0 ( 0.00%) :
==========================
Mean: 10.45 Standard deviation: 2.92
*/