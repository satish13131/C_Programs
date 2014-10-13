#include<stdio.h>
#include "../../../Constants/constants.c"
#include "../../../Util/checkutil.c"
#include "../../../Util/inpututil.c"
#include "../../../Util/copyutil.c"
#include "../../../Util/printutil.c"

int inputSize = 0;
int* numbers = NULL;

bool takeInput();
int* sortNumbers(int* numbers, int size);
int* merge(int* targetList, int* numberList1, int size1, int* numberList2, int size2);

int main()
{
	
	bool inputResult = false;
	int* sortedNumbers = NULL;
	int i = 0;	

	printf("MergeSort\n");

	inputResult = takeInput();
	
	if (inputResult == false)
	{
		return 0;
	}

	sortedNumbers = sortNumbers(numbers, inputSize);

	

	if (sortedNumbers == NULL)
	{
		return 0;
	}

	printf("The Ascending order is \n");
	for (i = 0;i < inputSize;i++)
	{
		printf("%d ", sortedNumbers[i]);
	}
	printf("\n");

	printf("The Descending order is \n");
	for (i = 0;i < inputSize;i++)
	{
		printf("%d ", sortedNumbers[inputSize - i - 1]);
	}
	printf("\n");

	return 0;
}


bool takeInput()
{
	char* inputString = NULL;
	char* extraCharString = NULL;
	char* tempString = NULL;
	int charStringSize = 0;
	const int MAX_LEN = 1024;
	bool tokenSizeCheck = false;

	extraCharString = (char *)calloc(MAX_LEN, sizeof(char));

	printf("Enter the count of numbers to sort\n");
	scanf("%d", &inputSize);
	scanf("%*c", extraCharString);
	memset(extraCharString, 0, MAX_LEN);

	if (inputSize <= 0)
	{
		printf("error - count of numbers is to be greater than zero\n");
		return false;
	}

	charStringSize = inputSize * 10;

	inputString = (char *)calloc(charStringSize, sizeof(char));
	tempString = (char *)calloc(charStringSize, sizeof(char));
	numbers = (int *)calloc(inputSize, sizeof(int));

	printf("Input numbers separated by space\n");

	scanf("%[^\n]%*c", inputString);
	strcpy(tempString, inputString);

	

	tokenSizeCheck = checkTokenSize(tempString, inputSize);

	

	if (tokenSizeCheck == false)
	{
		printf("error - Please check the count of numbers\n");
		return false;
	}	

	

	strcpy(tempString, inputString);

	

	

	copyInputAsNumbers(numbers, tempString);

	//free(extraCharString);
	//free(tempString);

	return true;
}

int* sortNumbers(int* numbers, int size)
{
	int* sortedNumbersTemp = NULL;
	sortedNumbersTemp = (int *)calloc(size, sizeof(int));
	copyNumbers(sortedNumbersTemp, numbers, size);
	if (size > 2)
	{
		
		int* firstHalfNumbers = NULL;
		int* secondHalfNumbers = NULL;
		int firstHalfStart = -1;
		int firstHalfEnd = -1;
		int secondHalfStart = -1;
		int secondHalfEnd = -1;
		int firstHalfSize = -1;
		int secondHalfSize = -1;
		
		if (size % 2 == 0)
		{
			firstHalfStart = 0;
			firstHalfEnd = (size / 2) - 1;
			secondHalfStart  = firstHalfEnd + 1;
			secondHalfEnd = size - 1;

			firstHalfNumbers = sortedNumbersTemp;
			secondHalfNumbers = &sortedNumbersTemp[secondHalfStart];

			firstHalfNumbers = sortNumbers(firstHalfNumbers, size / 2);
			secondHalfNumbers = sortNumbers(secondHalfNumbers, size / 2);

			merge(sortedNumbersTemp, firstHalfNumbers, size / 2, secondHalfNumbers, size / 2);
			
		}
		else
		{
			firstHalfSize = (size / 2) + 1;
			secondHalfSize = (size / 2);

			firstHalfStart = 0;
			firstHalfEnd = firstHalfSize - 1;
			secondHalfStart = firstHalfEnd + 1;
			secondHalfEnd = size - 1;

			

			firstHalfNumbers = sortedNumbersTemp;
			secondHalfNumbers = &sortedNumbersTemp[secondHalfStart];

			firstHalfNumbers = sortNumbers(firstHalfNumbers, firstHalfSize);
			secondHalfNumbers = sortNumbers(secondHalfNumbers, secondHalfSize);

			

			merge(sortedNumbersTemp, firstHalfNumbers, firstHalfSize, secondHalfNumbers, secondHalfSize);
			
		}

		//free(firstHalfNumbers);
		//free(secondHalfNumbers);
	}	
	else if (size == 2)
	{
		if (sortedNumbersTemp[0] > sortedNumbersTemp[1])
		{
			swap(&sortedNumbersTemp[0], &sortedNumbersTemp[1]);
		}
	}
	else if (size == 1)
	{
		
	}
	return sortedNumbersTemp;
}

int* merge(int* targetList, int* numberList1, int size1, int* numberList2, int size2)
{
	if (targetList == NULL)
	{
		return NULL;
	}
	if (numberList1 == NULL)
	{
		return NULL;
	}
	if (numberList2 == NULL)
	{
		return NULL;
	}
	if (size1 < 0)
	{
		return NULL;
	}
	if (size2 < 0)
	{
		return NULL;
	}
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < size1 && j < size2)
	{
		if (numberList1[i] < numberList2[j])
		{
			targetList[k] = numberList1[i];
			i++;
			k++;
		}
		else if (numberList1[i] > numberList2[j])
		{
			targetList[k] = numberList2[j];
			k++;
			j++;
		}
		else
		{
			targetList[k] = numberList1[i];
			k++;
			i++;
			targetList[k] = numberList2[j];
			k++;
			j++;
		}
	}	

	
	if (i < (size1))
	{
		copyNumbers(&targetList[k], &numberList1[i], size1 - i);
	}
	else if (j < size2)
	{
		copyNumbers(&targetList[k], &numberList2[j], size2 - j);
	}	

	return targetList;
}

