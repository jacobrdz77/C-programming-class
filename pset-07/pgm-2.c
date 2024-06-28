#include <stdio.h>

void swap(int *const x, int *const y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

int main()
{

	int num1, num2;

	printf("Enter two numbers:");
	scanf("%d %d", &num1, &num2);

	printf("Original values: %d, %d\n", num1, num2);
	swap(&num1, &num2);
	printf("Swapped values: %d, %d\n", num1, num2);

	return 0;
}
