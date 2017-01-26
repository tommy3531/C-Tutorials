#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/sorting/bubblesort.h"

int main(int argc, const char *argv[])
{
    int numOfArrayElements = 0;

	printf("This is from sorting.c\n");
    printf("Please enter the number of elements you would like to store in the array: ");
    scanf("%d", &numOfArrayElements);
    int arr[numOfArrayElements];
    for(int i = 0; i < numOfArrayElements; i++)
    {
        scanf("%d", &arr[i]);
    }

	printf("Array before bubblesort\n");
	printArray(arr, numOfArrayElements);
	printf("Performing bubblesort...\n");
	bubbleSortArray(arr, numOfArrayElements);
    printf("Sorted array: \n");
	printf("Array after bubblesort\n");
	printArray(arr, numOfArrayElements);

}
