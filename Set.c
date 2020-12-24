#include <stdio.h>
#include <stdlib.h>

void displaySets(int set1[], int element1, int set2[], int element2);
void sortSets(int set1[], int element1, int set2[], int element2);
void intersection(int set1[], int element1, int set2[], int element2);
int unionSets(int set1[], int element1, int set2[], int element2);

int main()
{
	int element1, element2;

	printf("\nHow many elements do you want to insert into set1{ } = ");
	scanf("%d", &element1);

	int set1[element1];
	int t = 0, h = 0;

	for (t; t < element1; t++) //Gets elements of set1[]
	{
		printf("\nInsert %d. = ", t + 1);
		scanf("\n%d", &set1[t]);
	}

	printf("\nHow many elements do you want to insert into set2{ } = "); //Gets elements of set2[]
	scanf("%d", &element2);

	int set2[element2];

	for (h; h < element2; h++)
	{
		printf("\nInsert %d. = ", h + 1);
		scanf("%d", &set2[h]);
	}

	printf("\n");

	/*   					Checking if there are same elements		      			   */
	/*-----------------------------------------------------------------------------------------------------------------*/
	int i = 0, isUnique, j, k;

	for (i; i < element1; i++) //Checks if set1 has same elements
	{
		isUnique = 1;

		for (j = i + 1; j < element1; j++)
		{
			if (set1[i] == set1[j])
			{
				for (k = j; k < element1 - 1; k++) //Deleting the same elements
				{
					set1[k] = set1[k + 1];
				}

				element1--;
				j--;
				isUnique = 0;
			}
		}
	}

	int x = 0, isUnique1, y, z;

	for (x; x < element2; x++) //The same process for set2
	{
		isUnique1 = 1;

		for (y = x + 1; y < element2; y++)
		{
			if (set2[x] == set2[y])
			{
				for (z = y; z < element2 - 1; z++)
				{
					set2[z] = set2[z + 1];
				}

				element2--;
				y--;
				isUnique1 = 0;
			}
		}
	}
	/*----------------------------------------------------------------------------------------------------------*/

	displaySets(set1, element1, set2, element2);
	sortSets(set1, element1, set2, element2);
	displaySets(set1, element1, set2, element2);
	intersection(set1, element1, set2, element2);
	unionSets(set1, element1, set2, element2);
}

void displaySets(int set1[], int element1, int set2[], int element2)
{
	int i = 0, j = 0;

	printf("set1{ } = ");

	for (i; i < element1; i++)
	{
		printf("%d ", set1[i]);
	}

	printf("\nset2{ } = ");

	for (j; j < element2; j++)
	{
		printf("%d ", set2[j]);
	}

	printf("\n");
}

void intersection(int set1[], int element1, int set2[], int element2)
{
	int i = 0, j = 0;

	printf("\nIntersection of Sets\n");
	printf("set1{ } \u2229 set2{ } = set3{ }\n");
	printf("set3 = {");

	while (i < element1 && j < element2)
	{
		if (set1[i] > set2[j])
		{
			j++;
		}
		else if (set1[i] < set2[j])
		{
			i++;
		}
		else if (set1[i] == set2[j])
		{
			printf(" %d, ", set2[j++]);
			i++;
		}
	}

	printf("}");
	printf("\n");
}

int unionSets(int set1[], int element1, int set2[], int element2)
{
	int i = 0, j = 0, z = 0;
	int element3 = element1 + element2;
	int set3[element3]; //Combines sets in 1 set

	while (i < element1 && j < element2)
	{
		if (set1[i] <= set2[j])
			set3[z++] = set1[i++];
		else if (set1[i] > set2[j])
			set3[z++] = set2[j++];
	}

	if (i == element1)
	{
		for (; j < element2; j++) //Remaining elements are sending to set3[].
			set3[z++] = set2[j];
	}
	else
		for (; i < element1; i++)
			set3[z++] = set1[i];
	/*		Checks for same elements in set3		*/
	/*--------------------------------------------------------------*/
	int t = 0, isUnique, d, k;

	for (t; t < element3; t++)
	{

		isUnique = 1;

		for (d = t + 1; d < element3; d++)
		{
			if (set3[t] == set3[d])
			{
				for (k = d; k < element3 - 1; k++) //Deleting the same elements
				{
					set3[k] = set3[k + 1];
				}

				element3--;
				d--;
				isUnique = 0;
			}
		}
	}
	/*--------------------------------------------------------------*/

	int x = 0;

	printf("\nUnion of Sets\nset1{ } \u222A set2{ } = set3{ }"); // /u222A Union symbol in ASCII
	printf("\nset3 = { ");

	for (x; x < element3; x++)
	{
		printf("%d, ", set3[x]);
	}

	printf("}");
	printf("\n");

	return set3[element3];
}

void sortSets(int set1[], int element1, int set2[], int element2)
{
	int i, j, key; //Sorting (Insertion Sort) for set1 and set2

	for (i = 1; i < element1; i++) //For set1
	{
		key = set1[i];
		j = i - 1;

		while (j >= 0 && set1[j] > key)
		{
			set1[j + 1] = set1[j];
			j = j - 1;
		}
		set1[j + 1] = key;
	}

	int x, y, key2;

	for (x = 1; x < element2; x++) //For set2
	{
		key2 = set2[x];
		y = x - 1;

		while (y >= 0 && set2[y] > key2)
		{
			set2[y + 1] = set2[y];
			y = y - 1;
		}
		set2[y + 1] = key2;
	}

	printf("\n");
}
