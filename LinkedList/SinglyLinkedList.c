#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"
/*       Murat Can Abay       */
/*Istanbul Commerce University*/

int main()
{
	node *root;		//First pointer of the list
	
	root = (node*)malloc(sizeof(node));
	root -> data = 24;
	
	addEnd(root, 11);
	addEnd(root, 13);
	addEnd(root, 96);
	addEnd(root, 99);
	printList(root);
	delete(root,96);
	printf("\nAfter deletion 96\n");
	printList(root);
		
	return 0;
}

void printList(node *head)
{
	if(head == NULL)		//If list is empty
	{
		return ;
	}
	else	printf("\n%d\n", head -> data);
		printList(head -> next);	//Recursive
}

void addEnd(node *head, int data)
{	
	while(head -> next != NULL)	//Go end of the list
	{
		head = head -> next;
	}
	
	head -> next = (node*)malloc(sizeof(node));	//Allocate new node for the new data
	head = head -> next;
	head -> data = data;
	head -> next = NULL;						//Do new data's pointer NULL
}

int delete(node *head, int key)
{
	struct node *temp, *previous;
	temp = head;
	
	while(temp != NULL)
	{
		if(temp -> data == key)
		{
			if(temp == head)				//If key value is root
			{
				head = temp -> next;
				free(temp);
				return 1;
			}
			else
			{
				previous -> next = temp ->next;
				free(temp);
				return 1;
			}
		}
		else
		{
			previous = temp;
			temp = temp -> next;
		}
	}
	return 0;
}
