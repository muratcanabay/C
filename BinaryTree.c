#include <stdlib.h>
#include <stdio.h>

typedef struct binarytree
{

	int data;
	struct binarytree *right;
	struct binarytree *left;

} binarytree;

binarytree *findMax(binarytree *node)
{
	if (node == NULL)
	{ //Binary Tree is empty.
		return NULL;
	}
	if (node->right)
	{ //Go right constantly, until you find deepest right element.
		findMax(node->right);
	}
	else
		return node;
}

binarytree *findMin(binarytree *node)
{
	if (node == NULL)
	{ //Binary Tree is empty
		return NULL;
	}
	if (node->left)
	{
		findMin(node->left); //Go left constantly, until you find deepest left element.
	}
	else
		return node;
}

binarytree *insert(binarytree *node, int data)
{
	if (node == NULL)
	{
		binarytree *temp = (binarytree *)malloc(sizeof(binarytree));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if (data > (node->data))
	{
		node->right = insert(node->right, data); //If an element comes greater than data inside
	}
	else if (data < (node->data))
	{
		node->left = insert(node->left, data);
	}
	else
		return node;
}

void printInorder(binarytree *node)
{ //LDR

	if (node == NULL)
	{ //isEmpty check?
		return;
	}
	printInorder(node->left);
	printf(" %d ", node->data);
	printInorder(node->right);
}

void printPreorder(binarytree *node)
{ //DLR

	if (node == NULL)
	{ //isEmpty check?
		return;
	}
	printf(" %d ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

void printPostorder(binarytree *node)
{ //LRD

	if (node == NULL)
	{ //isEmpty check?
		return;
	}
	printPostorder(node->left);
	printPostorder(node->right);
	printf(" %d ", node->data);
}

binarytree *search(binarytree *node, int data)
{
	if (node == NULL)
	{
		return NULL; //If element is not found.
	}
	if (data < (node->data))
	{
		return search(node->left, data); //If element smaller than data,search in left subtree.
	}
	else if (data > (node->data))
	{
		return search(node->right, data); //If element greater than data,search in right subtree.
	}
	else
		return node; //Returns node when wanted element isn't found.
}

binarytree *delete (binarytree *node, int data)
{
	binarytree *interchange; //Created a node to cut link between deleted node.

	if (node == NULL)
	{ //Element is not found.
		return NULL;
	}
	else if (data > node->data)
	{ //Searches to find element's place
		return node->right = delete (node->right, data);
	}
	else if (data < node->data)
	{ //Searches to find element's place
		return node->left = delete (node->left, data);
	}
	else
	{ //Element is found.
		if (node->right && node->left)
		{
			interchange = findMin(node->right);					   //Minimum value in the right subtree is successor. (Eğer findMin yerine findMax ve node->right yapsaydık predecessoru bulurduk.)
			node->data = interchange->data;						   //We are finding successor.
			node->right = delete (node->right, interchange->data); //The link deleted from data's node and it is connected with successor's node.
		}
		else
		{ //If there is no child or only 1 child, we can directly link children to the parent.
			interchange = node;
			if (node->right == NULL)
				node = node->right;
			else if (node->left == NULL)
				node = node->left;
			free(interchange); //If we do more than 1 deletion,it is has to be made free.
		}
	}
	return node;
}

int main()
{

	binarytree *root = NULL; //Initializing root NULL.
	binarytree *find;
	int num;

	//Inserting tree.. 24 11 13 -67 112 8 34 36
	root = insert(root, 24);
	root = insert(root, 11);
	root = insert(root, 13);
	root = insert(root, -67);
	root = insert(root, 112);
	root = insert(root, 8);
	root = insert(root, 34);
	root = insert(root, 36);

	printf("Inorder:"); //LDR
	printInorder(root);
	printf("\n\nPreorder:"); //DLR
	printPreorder(root);
	printf("\n\nPostorder:"); //LRD
	printPostorder(root);

	printf("\n\nWhich number do you want to find:");
	scanf("%d", &num);

	find = search(root, num);

	if (find == NULL)
	{
		printf("Element %d is not found.\n", num);
	}
	else
	{
		printf("Element %d is found!\n", num);
	}

	find = findMin(root);
	printf("\nThe smallest number is:%d", find->data);

	find = findMax(root);
	printf("\nThe greatest number is:%d", find->data);

	return 0;
}