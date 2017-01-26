#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node* left;
	struct node* right;
};

struct node* newNode(int val)
{
	// Root struct
	struct node* root;

	// Memory for struct
	root = malloc(sizeof(struct node));
	
	// fill struct members
	root->value = val;
	root->left = NULL;
	root->right = NULL;

	// return the newly created node
	return root;
}

struct node* balancedBinaryTree(int arry[], int first, int last)
{
	// Middle value
	int mid;

	// Root struct
	struct node* root;

	if(first > last)
	{
		return NULL;
	}

	// find middle
	//  = (0 + 6)
	// mid = 6 / 2;
	// mid = 3;   
	mid = (first + last) / 2;

	// make middle root
	// root = newNode(arry[2])
	// root = newNode(30)
	// root = 30;
	// end of 1st pass
	root = newNode(arry[mid]);

	// Fill the left side of the tree
	// root-> = balanceBinaryTree(arry,  0,   , 2-1)
	// root->left = balancedBinaryTree(arry, 0, 1)
	root->left = balancedBinaryTree(arry, first, mid-1);

	// Fill the right side of the tree
	// Mid is starting pointer +1 to go right
	// root->right = balancedBinaryTree(arry, 2+1, 6)
	// root->right = balancedBinaryTree(arry, 3, 6);
	root->right = balancedBinaryTree(arry, mid+1, last);

	return root;
}

void preOrderBalancedBinaryTree(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d->", root->value);
	preOrderBalancedBinaryTree(root->left);
	preOrderBalancedBinaryTree(root->right);
	
}

void displayBalancedBinaryTree(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	displayBalancedBinaryTree(root->left);
	printf("%d ", root->value);
	displayBalancedBinaryTree(root->right);

}



void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%4d", arr[i]);
	}
	puts("");
}

int minValueBalancedBinaryTree(struct node* root)
{
	// Current points to root
	struct node* current = root;

	// Check left side until NULL 
	while(current->left != NULL)
	{
		current = current->left;
	}

	return(current->value);
}

int maxDepth(struct node* root)
{
	if(root == NULL)
	{
		return(0);
	}

	else
	{
		int leftSideDepth = maxDepth(root->left);
		int rightSideDepth = maxDepth(root->right);

		if(leftSideDepth > rightSideDepth)
		{
			return leftSideDepth+1;	
		}
		else
		{
			return rightSideDepth+1;
		}
	}
}



