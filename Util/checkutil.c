#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../Constants/constants.c"


extern bool checkTokenSize(char* inputString, int size)
{

	if (size < 0)
	{
		return false;
	}
	if (inputString == NULL)
	{
		return false;
	}
	
	char* inputToken = NULL;
	inputToken = strtok(inputString, " ");
	int currentInputSize = 0;
	while (inputToken != NULL)
	{
		currentInputSize++;
		inputToken = strtok(NULL, " ");
	}
	if (size == currentInputSize)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
