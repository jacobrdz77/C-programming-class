#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int numRolls;
	do
	{

		printf("Enter the number of rolls: ");
		scanf("%d", &numRolls);
		if (numRolls <= 0)
		{
			printf("**Invalid input, select a value > 0\n");
		}
	} while (numRolls <= 0);

	int scoreArr[11] = {0};
	printf("Generating %d rolls...\n", numRolls);
	for (int i = 0; i < numRolls; i++)
	{
		int numOne = (rand() % 6) + 1;
		int numTwo = (rand() % 6) + 1;
		int numSum = numOne + numTwo;
		if (numSum >= 2 && numSum <= 12)
		{
			scoreArr[numSum - 2]++;
		}
	}

	printf("=================================\n");
	for (int i = 0; i < 11; i++)
	{
		float percentage = ((float)scoreArr[i] / numRolls) * 100;
		printf("%02d (%5.2f%%):", i + 2, percentage);
		for (int j = 0; j < (int)percentage; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}