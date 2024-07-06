#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int comparator(const void *a, const void *b);
void generateScores(unsigned short scores[], const unsigned short count);
void getStats(
	const unsigned short scores[],
	const unsigned short count,
	unsigned short *const min,
	unsigned short *const max,
	float *const mean,
	float *const median);
void printArray(
	const unsigned short scores[],
	const unsigned short count);
float standardDeviation(
	const unsigned short scores[],
	const float mean,
	const unsigned short count);

int main()
{
	srand(time(NULL));

	unsigned short scores[50];

	generateScores(scores, 50);
	printf("Unsorted:\n");
	printArray(scores, 50);
	qsort(scores, 50, sizeof(unsigned short), comparator);
	printf("Sorted:\n");
	printArray(scores, 50);
	unsigned short min = 0;
	unsigned short max = 0;
	float mean = 0.0;
	float median = 0.0;
	getStats(scores, 50, &min, &max, &mean, &median);
	float standardDev = standardDeviation(scores, mean, 50);

	printf("min:    %3hu        max:  %3hu\n", min, max);
	printf("mean:    %.2f   median:  %.2f\n", mean, median);
	printf("stdev:   %.2f", standardDev);
	return 0;
}

int comparator(const void *a, const void *b)
{
	return (*(unsigned short *)a - *(unsigned short *)b);
}

void generateScores(unsigned short *scores, const unsigned short count)
{
	if (scores == NULL || count <= 0)
	{
		printf("Invalid array or size\n");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		int numGenerated = (rand() % 100) + 1;
		*(scores + i) = numGenerated;
	}
}
void getStats(
	const unsigned short scores[],
	const unsigned short count,
	unsigned short *const min,
	unsigned short *const max,
	float *const mean,
	float *const median)
{
	if (scores == NULL || count <= 0)
	{
		printf("Invalid array or size\n");
		return;
	}
	unsigned short tempScores[count];

	for (int i = 0; i < count; i++)
	{
		tempScores[i] = scores[i];
	}

	float sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += tempScores[i];
	}

	*mean = sum / count;

	qsort(tempScores, count, sizeof(unsigned short), comparator);

	*min = tempScores[0];
	*max = tempScores[count - 1];

	if (count % 2 == 0)
	{
		unsigned short rightNum = tempScores[count / 2];
		unsigned short leftNum = tempScores[(count / 2) - 1];
		*median = (rightNum + leftNum) / 2;
	}
	else
	{
		// Get middle value
		*median = tempScores[count / 2];
	}
}

void printArray(
	const unsigned short scores[],
	const unsigned short count)
{
	if (scores == NULL || count <= 0)
	{
		printf("Invalid array or size\n");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n%5hu", scores[i]);
		}
		else
		{

			printf("%5hu", scores[i]);
		}
	}
	printf("\n\n");
}

float standardDeviation(
	const unsigned short scores[],
	const float mean,
	const unsigned short count)
{
	float summation = 0.0;

	for (int i = 0; i < count; i++)
	{
		float absoluteValue = abs(scores[i] - mean);
		summation += powf(absoluteValue, 2);
	}

	return sqrtf(summation / 2);
}