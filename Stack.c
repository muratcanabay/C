#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int array[SIZE];
int top = 0;

int pop()
{
	//Shows last element added into the stack.
	return array[--top];
}

void push(int data)
{
	if (top >= SIZE)
	{
		printf("STACK IS ALREADY FULL\n");
	}
	else
	{
		//Pushes into the stack and increases top by one.
		array[top++] = data;
	}
}

void printStack()
{
	int i = 0;
	printf("\n");

	for (i; i < top; i++)
		printf("%d ", array[i]);

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
	printf("\nPop = %d", pop());
	printf("\nPop = %d", pop());
	printf("\n");
}
