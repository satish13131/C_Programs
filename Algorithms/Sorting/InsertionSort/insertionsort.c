#include<stdio.h>
#include<stdlib.h>
#include "../../../Constants/constants.c"
#include "../../../Util/inpututil.c"
#include "../../../Util/checkutil.c"

int inputSize = -1;
int* numbers = NULL;

bool takeInput();
void sortNumbersInAsc();
void printResult();

int main()
{

	bool inputResult = false;

	printf("Insertion Sort\n*******************\n");
	

	inputResult = takeInput();
	if (inputResult == false)
	{
		return 0;
	}

	sortNumbersInAsc();

	printResult();

	return 0;
}

bool takeInput()
{
	char ignoreChar = '\0';
	char* inputString = NULL;
	char* inputStringCopy = NULL;
	bool tokenSizeCheckResult = false;
		

	printf("Enter the count of input numbers to take\n");
	scanf("%d", &inputSize);
	scanf("%*c");

	if (inputSize <= 0)
	{
		printf("The count of input numbers need to be greater than zero\n");
		return false;
	}

	inputString = (char*)calloc(inputSize * 10, sizeof(char));
	inputStringCopy = (char*)calloc(inputSize * 10, sizeof(char));
	numbers = (int*)calloc(inputSize, sizeof(int));	

	printf("Enter the input numbers separated by space\n");
	scanf("%[^\n]%*c", inputString);
	
	//printf("input string is %s\n", inputString);

	strcpy(inputStringCopy, inputString);

	tokenSizeCheckResult = checkTokenSize(inputStringCopy, inputSize);

	if (tokenSizeCheckResult == false)
	{
		printf("Please check the count of numbers entered\n");
		return false;
	}

	strcpy(inputStringCopy, inputString);
	
	copyInputAsNumbers(numbers, inputStringCopy);

	return true;	

}

void sortNumbersInAsc()
{
	int i = 0;
	int j = 0;
	int currentNo = -1;	
	for (i = 1;i < inputSize;i++)
	{
		currentNo = numbers[i];
		for (j = i - 1; j >= 0 && currentNo < numbers[j];j--)
		{
			numbers[j + 1] = numbers[j];
		}
		numbers[j + 1] = currentNo;
	}
	
}

void printResult()
{
	int i = 0;
	printf("The Ascending Order is \n");
	for (i = 0;i < inputSize;i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");

	printf("The Descending Order is \n");
	for (i = 0;i < inputSize;i++)
	{
		printf("%d ", numbers[inputSize - 1 - i]);
	}
	printf("\n");
}
