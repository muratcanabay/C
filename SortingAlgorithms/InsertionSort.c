#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void display(int array[]);
void insertionSort(int array[], int size);

int main()
{
	int array[SIZE] = {24, 11, 13, 96, 99, -9, 118, 62, 26, 23};

	printf("\nBefore Sorting:\n");

	display(array);

	printf("\nAfter Insertion Sorting:\n");

	insertionSort(array, SIZE);

	display(array);
}

void insertionSort(int array[], int size)
{
	//Key is temp.
	int i, j, key;

	//Started from 1 to seperate 0. item to will be compared.
	for (i = 1; i < SIZE; i++)
	{
		key = array[i];
		j = i - 1;

		//If comparing 0. and 1. element at the first loop
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		//Elements has changed and at the comparison new key is gonna be overwrited element.
		array[j + 1] = key;
	}
}

void display(int array[])
{
	int i = 0;

	for (i; i < 10; i++)
	{
		printf("\n%d", array[i]);
	}

	printf("\n");
}