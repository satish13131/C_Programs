#include<stdio.h>
#include<stdlib.h>
#include "../../../Constants/constants.c"
#include "../../../Util/inpututil.c"
#include "../../../Util/checkutil.c"

void sortNumbersInAsc(int* numbers, int size);

int main()
{

	const int MAX_LEN = 1024;
	int* numbers;
	int size = 10;
	int inputSize = 100;
	int i = 0;
	char *inputString = NULL;
	char *tempString = NULL;
	char *extraCharString = NULL;
	bool tokenSizeCheck = false;

	extraCharString = (char *)calloc(MAX_LEN, sizeof(char));

	printf("Input count of numbers to be entered - ");
	
	scanf("%d", &size);
	scanf("%*c", extraCharString);
	memset(extraCharString, 0, MAX_LEN);

	//printf("size is %d\n", size);

	if (size <= 0)
	{
		printf("error - count of numbers is to be greater than zero\n");
		return 0;
	}

	numbers = (int *)calloc(size, sizeof(int));

	inputSize = size * 10;

	inputString = (char *)calloc(inputSize, sizeof(char));
	tempString = (char *)calloc(inputSize, sizeof(char));
	
	printf("Input numbers separated by space\n");
	
	scanf("%[^\n]%*c", inputString);

	strcpy(tempString, inputString);	
	
	tokenSizeCheck = checkTokenSize(tempString, size);

	if (!tokenSizeCheck)
	{
		printf("error - Please check the count of numbers\n");
		return 0;
	}

	strcpy(tempString, inputString);	

	copyInputAsNumbers(numbers, tempString);

	sortNumbersInAsc(numbers, size);	

	printf("Ascending order is \n");

	for (i = 0;i < size;i++)
	{
	     printf("%d ", numbers[i]);
	}

	printf("\n");

	printf("Descending order is \n");
	
	for (i = 0;i < size;i++)
	{
		printf("%d ", numbers[size - i - 1]);
	}
	
	printf("\n");

	return 0;


}

void sortNumbersInAsc(int* numbers, int size)
{
	if (numbers == NULL)
	{
		return;
	}
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0;i < size;i++)
        {
        	for (j = i;j < size;j++)
  		{
			if (numbers[i] > numbers[j])
			{
				temp = numbers[i];
				numbers[i] = numbers[j];
         			numbers[j] = temp;
			}
		}
        }

}

