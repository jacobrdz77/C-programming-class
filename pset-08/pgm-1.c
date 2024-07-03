#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int ATTRIBUTES_COUNT = 6;
const int DICE_SIDES_COUNT = 6;

int comparator(const void *a, const void *b);
int generateCharacterAttributes(int *arr);

int main()
{
  // For each attribute (for loop)
  // Generate a number between 1-6, 4 times
  // Add the largest 3 numbers; Set to attribute[i]
  // Print out attributes
  srand(time(NULL));

  int attributes[ATTRIBUTES_COUNT];

  printf("Generating Character's Attributes...\n\n");
  for (int i = 0; i < ATTRIBUTES_COUNT; i++)
  {
    int randNums[4];

    for (int k = 0; k < 4; k++)
    {
      int numGenerated = (rand() % DICE_SIDES_COUNT) + 1;
      randNums[k] = numGenerated;
    }

    qsort(randNums, 4, sizeof(int), comparator);
    int sum = 0;

    for (int n = 1; n < 4; n++)
    {
      sum += randNums[n];
    }

    attributes[i] = sum;

    printf("Attribute #%d: %2d\n", i + 1, attributes[i]);
  }

  return 0;
}

int comparator(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int generateCharacterAttributes(int *arr)
{
}
