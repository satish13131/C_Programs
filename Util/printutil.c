#include<stdio.h>

void printNumbers(int* numbers, int size)
{		
	if (numbers == NULL)
	{
		return;
	}
	int i = 0;
	for (i = 0;i < size;i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
}
