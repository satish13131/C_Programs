#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* inputString = NULL;
	char* unconsumedString = NULL;
	int MAX_LEN = 1024;
	inputString = (char *)calloc(MAX_LEN, sizeof(char));	
	unconsumedString = (char *)calloc(MAX_LEN, sizeof(char));

	printf("scan set character demo\n**************************\n");

	printf("Enter the input with spaces. Now the input is read until new line character is encountered with scan set character. The last character is not consumed\n");

	scanf("%[^\n]", inputString);
	scanf("*c", unconsumedString);
	printf("Input string is %s\n", inputString);

	memset(inputString, 0, MAX_LEN);
	memset(unconsumedString, 0 , MAX_LEN);

	printf("\n************************\nEnter the input with spaces. Now the input is read using %%s\n");
	scanf("%s", inputString);
	printf("Input string is %s\n", inputString);

	return 0;
}
