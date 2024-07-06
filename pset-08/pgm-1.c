#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int ATTRIBUTES_COUNT = 6;
const int DICE_SIDES_COUNT = 6;

int comparator(const void *a, const void *b);
void generateCharacterAttributes(int *arr, int size_arr);

int main()
{
  int attributes[ATTRIBUTES_COUNT];

  srand(time(NULL));

  int num = 18;

  generateCharacterAttributes(attributes, ATTRIBUTES_COUNT);

  return 0;
}

int comparator(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

void generateCharacterAttributes(int *arr, int size_arr)
{
  if (arr == NULL || size_arr <= 0)
  {
    printf("Invalid array or size\n");
    return;
  }

  printf("Generating Character's Attributes...\n\n");
  for (int i = 0; i < size_arr; i++)
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

    *(arr + i) = sum;

    printf("Attribute #%d: %2d\n", i + 1, *(arr + i));
  }
}
