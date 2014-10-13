#include<stdio.h>

void swap(int* num1, int* num2)
{
	if (num1 == NULL)
	{
		return;
	}
	if (num2 == NULL)
	{
		return;
	}
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}

void copyNumbers(int* numberList1, int* numberList2, int size)
{
	if (numberList1 == NULL)
	{
		return;
	}
	if (numberList2 == NULL)
	{
		return;
	}
	if (size <= 0)
	{
		return;
	}
	int i = 0;
	for (i = 0;i < size;i++)
	{
		numberList1[i] = numberList2[i];
	}	
	return;	
}
