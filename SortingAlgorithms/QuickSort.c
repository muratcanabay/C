#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

void displayArray(int array[], int size);
int partition(int array[], int first, int last);
void quicksort(int array[], int first, int last);

int main()
{

	int array[SIZE] = {24, 11, 13, 96, 99, -12, 75, 0, 3, 31};

	printf("\n\nUnsorted Array is: ");

	displayArray(array, SIZE);
	quicksort(array, 0, SIZE - 1);

	printf("\n\nSorted Array is: ");
	displayArray(array, 10);

	return 0;
}

void displayArray(int array[], int size)
{

	int i = 0;

	for (i; i < size; i++)
	{
		printf(" %d", array[i]);
	}

	printf("\n");
}

void quicksort(int array[], int first, int last)
{
	int part;

	if (first < last)
	{
		part = partition(array, first, last);
		quicksort(array, first, part - 1);
		quicksort(array, part, last);
	}
}

int partition(int array[], int first, int last)
{

	int i, pivot, j, temp;

	pivot = array[last]; //Pivot is selected as the last element.
	j = first;

	for (i = first; i < last; i++)
	{
		if (array[i] <= pivot) //Stop condition for recursion.
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			j++;
		}
	}

	temp = array[j];
	array[j] = array[last];
	array[last] = temp;

	return j;
}