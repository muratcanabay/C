#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void display(int array[]);
void insertionSort(int array[],int size);

int main()
{
	int array[SIZE]={24,11,13,96,99,-9,118,62,26,23};

	printf("\nBefore Sorting:\n");
	
	display(array);

	printf("\nAfter Insertion Sorting:\n");
	
	insertionSort(array,SIZE);

	display(array);
}

void insertionSort(int array[],int size)
{
	int i,j,key;				//Key is temp.
	
	for(i=1;i<SIZE;i++)   			//Started from 1 to seperate 0. item to will be compared.
	{
		key=array[i];
		j=i-1;

		while(j >= 0 && array[j]>key)	//If comparing 0. and 1. element at the first loop
		{				
			array[j+1]=array[j];
			j=j-1;
		}
		array[j+1]=key;		       //Elements has changed and at the comparison new key is gonna be overwrited element.
	}

}

void display(int array[])
{
	int i=0;
	
	for(i;i<10;i++)
	{
		printf("\n%d",array[i]);
	}
	
	printf("\n");
}