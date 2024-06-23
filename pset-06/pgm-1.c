#include <stdio.h>

int getNumberOfElements() {
  int num;
  printf("Enter number of elements:");
  scanf("%d", &num);
  return num;
}

int main() {
  int numberOfElements = getNumberOfElements();

  if (numberOfElements < 1) {
    printf("Must be greater than 1. Exiting...");
    return 1;
  }

  int numbers[numberOfElements];
  int sum;
  int minNumber;
  int maxNumber;

  for (int i = 0; i < numberOfElements; i++) {
    printf("enter the next number:");
    scanf("%d", &numbers[i]);
    if (numbers[i] > maxNumber) {
      maxNumber = numbers[i];
    }
    if (numbers[i] < minNumber) {
      minNumber = numbers[i];
    }

    sum += numbers[i];
  }

  double average = (double)sum / numberOfElements;

  printf("    The sum is:%8d\n", sum);
  printf("The average is:%8.2lf\n", average);
  printf("      Smallest:%8d\n", minNumber);
  printf("       Largest:%8d\n", maxNumber);

  return 0;
}
