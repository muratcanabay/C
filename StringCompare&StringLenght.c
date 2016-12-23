#include <stdio.h>
#include <stdlib.h>
/*       Murat Can Abay       */
/*Istanbul Commerce University*/

int main()
{
	char array1[] = "kivi";				//A is greater than B according to ASCII.	
	char array2[] = "ananas";
	int lenght1 = 0, lenght2 = 0;
	int a = 0, b = 0, c = 0;
	
	while(array1[lenght1] != '\0')			//Gets lenght of array1 
	{
		lenght1++;
	}
	
	while(array2[lenght2] != '\0')			//Gets lenght of array2
	{
		lenght2++;
	}
	printf("\nLength of array1[] = %d\n", lenght1);
	printf("\nLenght of array2[] = %d\n", lenght2);
		
	if(lenght1 >= lenght2)
	{
		while(array1[c] == array2[c])		//Compares if they are equal
		{
			c++;
	
			if(c == lenght2 - 1)		//Also checking the lenght
				{
					printf("\nThey are equal.\n");	
					break;
				}
		}	

		if(array1[c] > array2[c])
			printf("\n%s is greater than %s.\n", array1, array2);
		else if (array1[c] < array2[c])
			printf("\n%s is greater than %s.\n", array2, array1);
	}
	
	int d = 0;
	
	if(lenght2 > lenght1)
	{
		while(array1[d] == array2[d])
		{	
			d++;
			
			if(d == lenght1 - 1)		
				{
					printf("\nThey are equal.\n");	
					break;
				}	
		}

		if(array1[d] > array2[d])
			printf("\n%s is greater than %s.\n", array1, array2);
		else if (array1[d] < array2[d])
			printf("\n%s is greater than %s.\n", array2, array1);
	}

}
