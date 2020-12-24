#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

int main()
{
	node *root; //First pointer of the list

	root = (node *)malloc(sizeof(node));
	root->data = 24;

	addEnd(root, 11);
	addEnd(root, 13);
	addEnd(root, 96);
	addEnd(root, 99);
	printList(root);
	delete (root, 96);
	printf("\nAfter deleting 96\n");
	printList(root);

	return 0;
}

void printList(node *head)
{
	//If list is empty
	if (head == NULL)
	{
		return;
	}
	else
		printf("\n%d\n", head->data);
	printList(head->next); //Recursive
}

void addEnd(node *head, int data)
{
	//Go end of the list
	while (head->next != NULL)
	{
		head = head->next;
	}

	//Allocate new node for the new data
	head->next = (node *)malloc(sizeof(node));
	head = head->next;
	head->data = data;
	//Do new data's pointer NULL
	head->next = NULL;
}

int delete (node *head, int key)
{
	struct node *temp, *previous;
	temp = head;

	while (temp != NULL)
	{
		if (temp->data == key)
		{
			//If key value is root
			if (temp == head)
			{
				head = temp->next;
				free(temp);
				return 1;
			}
			else
			{
				previous->next = temp->next;
				free(temp);
				return 1;
			}
		}
		else
		{
			previous = temp;
			temp = temp->next;
		}
	}
	return 0;
}
