#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRINT_ARRAY(arr, size)                                                 \
  do {                                                                         \
    printf("array: ");                                                         \
    for (int i = 0; i < size; i++) {                                           \
      printf("%d ", arr[i]);                                                   \
    }                                                                          \
    printf("\n");                                                              \
  } while (0)

#define PRINT_MAX(arr, size)                                                   \
  do {                                                                         \
    int max = arr[0];                                                          \
    for (int i = 1; i < size; i++) {                                           \
      if (arr[i] > max) {                                                      \
        max = arr[i];                                                          \
      }                                                                        \
    }                                                                          \
    printf("max: %d\n", max);                                                  \
  } while (0)

#define PRINT_AVG(arr, size)                                                   \
  do {                                                                         \
    int sum = 0;                                                               \
    for (int i = 0; i < size; i++) {                                           \
      sum += arr[i];                                                           \
    }                                                                          \
    printf("avg: %.2f\n", (float)sum / size);                                  \
  } while (0)

int main() {
  srand(time(NULL));

  int nums[20];
  for (int i = 0; i < 20; i++) {
    int randomNumber = (rand() % 1000);
    nums[i] = randomNumber;
  }

  PRINT_ARRAY(nums, 20);
  PRINT_MAX(nums, 20);
  PRINT_AVG(nums, 20);

  return 0;
}