#include <stdio.h>
#include <stdlib.h>
/* Murat Can Abay */
/* Istanbul Commerce University*/

int selectionSort(int array[],int num)
{
	int i=0,j,minimum,temp;	
		for(i;i<num-1;i++)
		{
			minimum=i;
				for(j=i;j<num;j++)			//For next loop,it stars from 1 (i=0) at the beginning-
				{	
					if(array[j]<array[minimum])
					{
						minimum=j;		
					}
				}
			temp=array[i];
			array[i]=array[minimum];
			array[minimum]=temp;		

		}
}

void printArray(int array[],int num)
{
	int i=0;
	
	printf("\nSorted Array : ");
		for(i;i<num;i++)
		{
			printf("%d ",array[i]);
		}
	printf("\n\n");
}

void unsortedArray(int array[],int num)
{
	int i=0;
	
	printf("\nArray Before Sorting : ");
		for(i;i<num;i++)
		{
			printf("%d ",array[i]);
		}
	printf("\n\n");
}

int main()
{
	int array[]={24,11,13,66,97,28,1,32,14,99};
	int num=sizeof(array)/sizeof(array[0]);
	
	unsortedArray(array,num);
	selectionSort(array,num);
	printArray(array,num);	

	return 0;
}