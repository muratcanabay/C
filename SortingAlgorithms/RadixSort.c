#include <stdio.h>
#include <stdlib.h>

int findMax(int array[], int number_of_elements)
{

	int max = array[0];
	int i = 1;
	for (i; i < number_of_elements; i++)
	{
		//Comparing each array elements.
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

void countingSort(int array[], int number_of_elements, int divide)
{

	//Sorted Array
	int sorted_array[number_of_elements];
	int i = 0, m = 1;
	int count[10] = {0}; //Respresents 10 Digits 0-9 || Initializing array elements to 0.

	for (i; i < number_of_elements; i++)
	{
		count[(array[i] / divide) % 10]++;
	}
	for (m; m < 10; m++)
	{ //Changing positions

		count[m] += count[m - 1];
	}
	for (i = number_of_elements - 1; i >= 0; i--)
	{
		sorted_array[count[(array[i] / divide) % 10] - 1] = array[i];
		count[(array[i] / divide) % 10]--;
	}
	for (i; i < number_of_elements; i++)
	{
		array[i] = sorted_array[i];
	}
}

void radix_sort(int array[], int number_of_elements)
{

	int get_max = findMax(array, number_of_elements);
	int divide = 1;
	for (divide; (get_max / divide) > 0; divide *= 10)
	{													 //Finds how many digits array has(Kaç haneli bir dizi olduğunu bulmak için)
		countingSort(array, number_of_elements, divide); //Örneğin en büyük sayı 6000-->4 haneli olacak.	//Bu diziye göre divide=1-10-100 3 döngü
	}
}

void display_sorted_array(int array[])
{

	int i = 0;
	printf("Array After Radix Sorting:  ");
	for (i; i < 12; i++)
	{ //Sorted array is displayed.
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{

	int array[] = {24, 11, 13, 55, 1, 45, 35, 87, 33, 38, 48, 110}; //12
	int number_of_elements = sizeof(array) / sizeof(array[0]);		//Finding number of elements (If element number is known, you can equal it to n_o_e)

	int i = 0;
	printf("Array Before Radix Sorting: ");
	for (i; i < 12; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	radix_sort(array, number_of_elements);
	display_sorted_array(array);

	return 0;
}