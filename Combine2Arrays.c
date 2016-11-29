#include <stdio.h>
#include <stdlib.h>

#define SIZE1 7
#define SIZE2 5
#define SIZE3 12
/*	Murat Can Abay	      */
/*Istanbul Commerce University*/

//This program combines 2 in ordered arrays.

void displayArray(int array1[], int array2[], int size1, int size2);
int combineArray(int array1[], int array2[], int size1, int size2);
int array3[SIZE3];

int main()
{

	int array1[SIZE1] = {1, 2, 5, 12, 24, 31, 65};	//Arrays are in ordered inside.
	int array2[SIZE2] = {4, 7, 76, 96, 105};
	
	printf("\n\nArray Before Combining \n");
	
	displayArray(array1, array2, SIZE1, SIZE2);
	
	printf("Array After Combining \n");	
		
	combineArray(array1, array2, SIZE1, SIZE2);	
	
	printf("\n\n");
		
	return 0;
}

void displayArray(int array1[], int array2[], int size1, int size2)
{
	int i = 0, j = 0;
	
	printf("Array1[%d]: ", SIZE1);
		
	for(i; i < size1; i++)
	{
	
		printf(" %d ", array1[i]);

	}
	
	printf("\nArray2[%d]: ", SIZE2);	

	for(j; j < size2; j++)
	{
	
		printf(" %d ", array2[j]);

	}
	
	printf("\n\n");
}

int combineArray(int array1[], int array2[], int size1, int size2)
{
	int i = 0, j = 0, k = 0, t = 0;
		
	while(i < size1 && j < size2) 	
	{	
		if(array1[i] < array2[j])
			array3[k++] = array1[i++];
		else if(array1[i] > array2[j])
			array3[k++] = array2[j++];
						
					   	     
	}

	if(i == size1)
	{
		for( ; j < size2; j++)			//Remaining elements are sending to array3[].
			array3[k++] = array2[j];
		
	}else
		for( ; i < size1; i++)
			array3[k++] = array1[i];
	
	printf("Array3[%d]:", SIZE3);
		
	for(t; t < SIZE3; t++)
	{
		printf(" %d ", array3[t]);
	}
	
	return array3[SIZE3];
	
}








