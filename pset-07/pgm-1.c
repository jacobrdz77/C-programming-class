#include <stdio.h>

int main()
{

	do
	{
	  int value;
		printf("Enter a value: ");
		scanf("%d", &value);
	  int *pValue = &value;
		printf("value %d located at %p\n", value, pValue);
		printf("value %d located at %p\n", (*pValue * 2), pValue);
	} while (1);

	return 0;
}
