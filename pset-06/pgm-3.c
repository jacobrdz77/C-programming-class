#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int userGuess;
  int numOfGuesses;
  srand(time(NULL));
  int randomNumber = (rand() % 100) + 1;
  printf("Random num: %d", randomNumber);
  printf("Generating number between 1-100...\n");

  do {
    if (userGuess) {
      if (userGuess > randomNumber)
        printf("Too high\n");
      if (userGuess < randomNumber)
        printf("Too low\n");
    }
    printf("Guess a number:");
    scanf("%d", &userGuess);
    numOfGuesses += 1;
  } while (userGuess != randomNumber);

  printf("It took you %d guesses for the correct answer (%d)", numOfGuesses,
         randomNumber);

  return 0;
}
