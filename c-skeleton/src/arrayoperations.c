#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "../include/arrayoperations.h"
#define ARRAYMAX 10

void printRow(int *array, int low, int mid, int high);
int getArraySize(int array[], int limit);

int main(int argc, const char *argv[])
{
	void printIntArray(int array[], int size);
	//int getArraySize(int array[], int limit);

	
	//int numbers[] = {1, 2, 3, 4, 5};
	//int arraySize = getArraySize(numbers, ARRAYMAX);
	//printf("The size of the array is: %d\n", arraySize);
	//printIntArray(numbers, arraySize);
	//reverseArray();
	//tenNumbers();
	
	// Start of InitalizeElementsOfArrayToZero()
	//size_t i;
	int *ptrToArray;
	//ptrToArray = InitalizeElementsOfArrayToZero(ARRAYMAX);
	//printf("This is printed from arrayoperations.c\n");
	//printf("%s%13s\n", "Element", "Value");
	//printf("Printing using pointer math\n");
	//for(i = 0; i < 10; i++)
	//{
		//printf("%7zu%13d\n", i, ptrToArray[i]);
		//printf("*(ptrToArray + %zu) : %d\n", i, *(ptrToArray + i));
	//}

	// End of InitalizeElementsOfArrayToZero()

	// Start of InitializeArrayWithRandomNumbers(int Num)
	ptrToArray = InitializeArrayWithRandomNumbers(ARRAYMAX);
	//printf("This is printed from arrayoperation.c\n");
	//for(i = 0; i < ARRAYMAX; i++)
	//{
	//	printf("ptrToArray[%zu] = %d\n", i, ptrToArray[i]);
	//}

	//countFreq(ptrToArray);
	// End of InitializeArrayWithRandomNumbers(int Num)

	// Start of buddleSort
	//bubbleSortArray(ptrToArray);
	// End of bubbleSort

	// Start of searchArray and linearSearch
	printf("This is printed from printIntArray: \n");
	printIntArray(ptrToArray, ARRAYMAX);
	int sizeOfArray = oneDimensionalArraySize(ptrToArray, ARRAYMAX);
	findSecondLargestNumberInArray(ptrToArray, ARRAYMAX);
	//int negNumInArray = numbersLessThanZeroInArray(ptrToArray, ARRAYMAX);
	//int numEqToZeroInArray = numberEqToZeroInArray(ptrToArray, ARRAYMAX);
	//int numGreaterThanZero = numberGreaterThanZeroInArray(ptrToArray, ARRAYMAX);
	//printf("%d numbers are less then 0 \n", negNumInArray);
	//printf("%d numbers are equal to 0 \n", numEqToZeroInArray);
	//printf("%d numbers are greater than to 0 \n", numGreaterThanZero);
	//findNumNegNumZeroNumPos(ptrToArray, ARRAYMAX);
	//int *ptrSortedArray = bubbleSortArray(ptrToArray);
	//int searchValue = searchingArray(ptrSortedArray);
	printf("%d elements are in array\n", sizeOfArray);
	//int binarySearchSucessValue = BinarySearch(ptrSortedArray, 0, 10, searchValue);
	//if(binarySearchSucessValue != -1)
	//{
	//	printf("%d Found in array element: %d\n", searchValue, binarySearchSucessValue);
	//}

}
