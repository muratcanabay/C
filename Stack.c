#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
/*       Murat Can Abay       */
/*Istanbul Commerce University*/

int array[SIZE];
int top = 0;

int pop()
{
	return array[--top];			//Shows last element added into the stack.
}

void push(int data)
{
	if(top >= SIZE)
	{
		printf("STACK IS ALREADY FULL\n");	
	}else
	{
		array[top++] = data;		//Push into the stack and increase top by one.
	}
}

void printStack()
{
	int i = 0;
	printf("\n");

	for(i;i<top;i++)
		printf("%d ",array[i]);		//Prints all elements of stack.
	
	printf("\n");
}


int main()
{
	push(1);
	push(2);
	push(3);
	push(5);
	push(9);
	push(-3);
	push(22);
	printStack();	
	printf("\nPop = %d",pop());
	printf("\nPop = %d",pop());
	printf("\n");
}
