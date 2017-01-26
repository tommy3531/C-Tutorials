#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/binarySearchTree.h"

int main(int argc, const char *argv[])
{
	printf("This is from binarySearch.c\n");
	int arr[] = {10, 20, 30, 40, 60, 80};
	int n = sizeof(arr) / sizeof(int);
	struct node* root = balancedBinaryTree(arr, 0, n-1);
	printf("%d elements in array\n", n);
	printf("Array Before preOrder\n");
	displayBalancedBinaryTree(root);
	printf("\n");
	//printArray(arr, n);
	printf("Array after preOrder\n");
	preOrderBalancedBinaryTree(root);
	printf("\n");
	int maxTreeDepth = maxDepth(root);
	printf("The max depth is %d", maxTreeDepth);
	//int lowestValue = minValueBalancedBinaryTree(root);
	//printf("\n%d this is the lowest value\n", lowestValue);

	

}
