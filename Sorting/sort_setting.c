#include <stdio.h>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* CreateArr(int size, int range)
{
	int * newArr = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		newArr[i] = rand() % range;
	return newArr;
}

void PrintArr(int size, int*arr)
{
	for (int i = 0; i < size; i++)
	{
		printf("&d ", arr[i]);
	}
}