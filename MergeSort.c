#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
/*	Murat Can Abay     */
/*Istanbul Commerce University*/

void displayArray(int array[], int size);
void mergeSort(int array[] ,int num1 ,int num2);
void concatArray(int array[], int first, int mid, int mid2, int last);

int main()
{
	int array[SIZE]={24, 11, 13, 67, -8, 65, -65, 101, 96, 99};
	
	printf("\n\nArray Before Sorting: ");
	
	displayArray(array, SIZE);
	mergeSort(array, 0, 9);
	
	printf("Array After Sorting: ");
	displayArray(array ,SIZE);

	return 0;
}

void displayArray(int array[], int size)
{
	int i = 0;
		
	for(i;i < size;i++)
	{

		printf(" %d ", array[i]);	
	
	}
	
	printf("\n\n");
}

void mergeSort(int array[], int first, int last)
{
	if(first < last)						//Stopping condition for recursion
	{
		int middle = (first + last) / 2;			//Array is divided into 2 parts
		
		mergeSort(array, first, middle);			//First divided array
		mergeSort(array, middle+1, last);			//Second divided array
		concatArray(array, first, middle, middle+1, last);	//Divided arrays sending to get concatinated
	}
}

void concatArray(int array[], int first, int mid, int mid2, int last)
{
	int i,j,k = 0; 	//K sorted array index
	int concat_array[10];
	
	i = first;	//First element of first array
	j = mid2;	//First element of second array
	
	while(i <= mid && j <= last)
	{
			if(array[i] < array[j])
				concat_array[k++] = array[i++];
			else
				concat_array[k++] = array[j++];
	}

	while(i <= mid)				 //If there are some elements left
		concat_array[k++] = array[i++];	
	
	while(j <= last)
		concat_array[k++] = array[j++];

	for(i = first, j=0; i <= last; i++, j++)
		array[i]=concat_array[j];
	
}