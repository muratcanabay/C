#include <stdio.h>
#include <stdlib.h>
/* Murat Can Abay */
/* Istanbul Commerce University */
void bubbleSort(int array[],int num)
{
	int temp,i=0,j;
		for(i;i<num;i++)		
		{
			for(j=num-1;j>i;j--)			//Works in reverse.
			{
				if(array[j-1]>array[j])		//Switches elements.
				{
					temp=array[j-1];
					array[j-1]=array[j];
					array[j]=temp;			
				}
			}
		}	
	
}

void display_array(int array[],int num)
{
	int i=0;
	
	printf("\nSorted Array: ");
		
		for(i;i<num;i++)
		{
			printf("%d ",array[i]);
		}
	printf("\n\n");
}

int main()
{

	int array[]={24,11,13,20,16,96,99,-14,0,3};
	int num=sizeof(array)/sizeof(array[0]); 		//Finds length of the array.
	
	bubbleSort(array,num);
	display_array(array,num);

	return 0;

}