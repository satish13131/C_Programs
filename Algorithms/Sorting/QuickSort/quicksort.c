#include<stdio.h>
#include<stdlib.h>
#include "../../../Constants/constants.c"
#include "../../../Util/inpututil.c"
#include "../../../Util/checkutil.c"
#include "../../../Util/copyutil.c"
#include "../../../Util/printutil.c"

int inputSize = -1;
int* numbers = NULL;

bool takeInput();
void sortNumbersInAsc(int* numbers, int size);
void printResult();
int arrangeElements(int* numbers, int size, int pivot, int pivotCount);
int movePivotToBack(int* numbers, int size, int pivotIndex);
void movePivotToMiddle(int* numbers, int size, int pivotCount, int rightSideStart);

int main()
{

	bool inputResult = false;

	printf("QuickSort\n*********************************\n");
	
	inputResult = takeInput();
	if (inputResult == false)
	{
		return 0;
	}

	sortNumbersInAsc(numbers, inputSize);

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
	
	printf("input string is %s\n", inputString);

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

void sortNumbersInAsc(int* numbers, int size)
{
	if (numbers == NULL)
	{
		return;
	}
	if (size <= 0)
	{
		return;
	}
	if (size == 1)
	{
		return;
	}
	if (size == 2)
	{
		if (numbers[0] > numbers[1])
		{
			swap(&numbers[0], &numbers[1]);
		}
		return;
	}
	int pivotIndex = -1;
	int pivotCount = 0;
	int rightSideStart = -1;
	if ((size % 2) != 0)
	{
		pivotIndex = size / 2;		
	}
	int pivot = numbers[pivotIndex];
	
	printNumbers(numbers, size);
	
	printf("SortNumbersInAsc - move pivotToBack\n");
		
			
	pivotCount = movePivotToBack(numbers, size, pivotIndex);
	
	printNumbers(numbers, size);
	printf("SortNumbersInAsc - arrangeElements\n");
	

	rightSideStart = arrangeElements(numbers, size - pivotCount, pivot, pivotCount);
	
	printf("SortNumbersInAsc - rightSideStart is %d\n", rightSideStart);
	printNumbers(numbers, size);

	if (rightSideStart != -1)
	{
	
		printf("SortNumbersInAsc - left Part\n");
		
	
		sortNumbersInAsc(numbers, rightSideStart + 1);

		printNumbers(numbers, size);	
		printf("SortNumbersInAsc - right part\n");
	

		sortNumbersInAsc(&numbers[rightSideStart], size - pivotCount - (rightSideStart + 1));
		printNumbers(numbers, size);

	}
	else
	{
		sortNumbersInAsc(numbers, size - pivotCount);
	}

	
	printf("SortNumbersInAsc - size is %d \n", size);
	printf("SortNumbersInAsc - pivotCount is %d \n", pivotCount);
	printf("SortNumbersInAsc - rightSideStart is %d \n", rightSideStart);
	printf("SortNumbersInAsc - movePivotToMiddle\n");
	
	
	movePivotToMiddle(numbers, size, pivotCount, rightSideStart);

	printNumbers(numbers, size);
	printf("SortNumbersInAsc - after movePivotToMiddle\n");

	
}

int arrangeElements(int* numbers, int size, int pivot, int pivotCount)
{

	int rightSideStart = -1;
	if (numbers == NULL)
	{
		return rightSideStart;
	}
	if (size <= 0)
	{
		return rightSideStart;
	}
	

	int startPointerIndex = 0;
	int endPointerIndex = size - 1;	
	int i = 0;
	int swapCount = 0;
	

	while (startPointerIndex < endPointerIndex)
	{

		
		if (numbers[startPointerIndex] > pivot && numbers[endPointerIndex] < pivot)
		{			
			swap(&numbers[startPointerIndex], &numbers[endPointerIndex]);
			swapCount++;
		}
		if (numbers[startPointerIndex] < pivot)
		{
			startPointerIndex++;
		}
		if (numbers[endPointerIndex] > pivot)
		{
			endPointerIndex--;
		}
		

	}

	for (i = 0;i < size;i++)
	{
		if (numbers[i] > pivot)
		{
			rightSideStart = i;
			break;	
		}
	}
	
	return rightSideStart;

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

int movePivotToBack(int* numbers, int size, int pivotIndex)
{

	int pivotCount = 0;
	if (numbers == NULL)
	{
		return pivotCount;
	}
	if (size <= 0)
	{
		return pivotCount;
	}
	if (pivotIndex > (size - 1))
	{
		return pivotCount;
	}
	int pivot = numbers[pivotIndex];
	int endIndex = size - 1;
	int startIndex = 0;
	int i = 0;
	while (startIndex <= endIndex)
	{
		for (i = endIndex;i >= 0;i--)
		{
			if (numbers[i] != pivot)
			{
				break;
			}
			else
			{
				pivotCount++;
			}
		}
		if (endIndex < 0)
		{
			break;
		}
		endIndex = i;
		for (i = 0;i < size - 1;i++)
		{
			if (numbers[i] == pivot)
			{
				break;
			}
		}
		if (startIndex >= size)
		{
			break;
		}
		startIndex = i;
		if (startIndex < endIndex)
		{
			swap(&numbers[startIndex], &numbers[endIndex]);
		}
	}
	return pivotCount;
}

void movePivotToMiddle(int* numbers, int size, int pivotCount, int rightSideStart)
{
	if (numbers == NULL)
	{
		return;
	}
	if (size <= 0)
	{
		return;
	}
	if (pivotCount <= 0)
	{
		return;
	}
	if (rightSideStart < 0 || rightSideStart > (size - 1))
	{
		return;
	}
	int pivotStart = size - pivotCount;
	int i = 0;
	int j = 0;
	int pivot = numbers[size - 1];
	int greaterNumbers = size - (rightSideStart) - pivotCount;
	int count = 0;
	for (i = size - pivotCount - 1, j = 0;i >= rightSideStart;i--, j++)
	{
		numbers[size - 1 - j] = numbers[i];
	}
	for (i = rightSideStart;count < pivotCount;i++, count++)
	{
		numbers[i] = pivot;
	}
		
}

