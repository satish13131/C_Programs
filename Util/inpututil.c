#include<string.h>
#include<stdio.h>
#include<stdlib.h>

extern void copyInputAsNumbers(int* numbers, char* inputString);

void copyInputAsNumbers(int* numbers, char* inputString)
{
	if (numbers == NULL)
	{
		return;
	}
	if (inputString == NULL)
	{
		return;
	}
	char* numberString = NULL;
	int i = 0;
	numberString = strtok(inputString, " "); 
	while (numberString != NULL)
	{
		numbers[i] = atoi(numberString);
		i++;
		numberString = strtok(NULL, " "); 
	}
}
