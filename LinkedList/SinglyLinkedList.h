#ifndef LinkedList
#define LinkedList

typedef struct node
{

	int data;
	struct node *next;

}node;

void printList(node *head);
void addEnd(node *head, int data);
int delete(node *head, int key);

#endif
