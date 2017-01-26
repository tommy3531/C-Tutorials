#include <stdio.h>
#include <stddef.h>
#include <time.h>
#define SIZE 10

/********************* Arrays *******************************************************
 *
 *  declare Array
 *	- data_type array_name[number of elements]
 *	- Example int arry[100]; - declares array arry with 100 elements of type int
 *	- Use a marco to set array size #define SIZE 100
 *  
 *  Array initialization
 *	- int arr[4] = {10, 20, 30, 40}; 
 ***********************************************************************************/

/********************* Reverse Array *****************************************************
 *
 * Declare array of 5 elements add values 1.2 - 1.5 using loop
 *
 ****************************************************************************************/

void reverseArray()
{
	int i;
	
	// Create an array with 5 elements that are type double
	double array[5];

	for(i = 0; i < 5; i++)
	{
		// array[0] = 1.1 + (0*0.1) array[0] = 1.1
		// array[1] = 1.1 + (1*0.1) array[1] = 1.2
		array[i] = 1.1 + (i*0.1);
		printf("%f\n", array[i]);
	}
	printf("This is the values in reverse order: \n");

	// 4 instead of 5 not accounting for NULL terimater
	for(i = 4; i >= 0; i--)
	{
		// array[4] = 1.5
		// array[3] = 1.4
		// array[2] = 1.3
		// array[1] = 1.2
		// array[0] = 1.1
		printf("%f\n", array[i]);
	}

	
}

/********************* Read 10 integers ****************************************************
 *
 * Reads 10 integers and stores them in an array, checks if the array is symmetric,
 * if the value of the first element is equal to the last one, the value of the second
 * one equal to th value of the last 
 *
 ****************************************************************************************/
void tenNumbers()
{
	int i;
	
	// Declare array with 10 element of type int
	int array[SIZE];
	
	// Fill the array with ten int items
	for(i = 0; i < SIZE; i++)
	{
		printf("Enter element a[%d]: ", i);

		// scanf found something other then an int
		while(scanf("%d", &array[i]) != 1)
		{
			// Notify user of error
			printf("Invalid, Please enter intergers only!!\n");

			// Enter element
			printf("Enter element a[%d]: ", i);

			// Last character in input buffer in \n
			while(getchar() != '\n');
		}
	}
	printf("You have entered %d integers into the array: \n", SIZE);

}



int oneDimensionalArraySize(int array[], int size)
{
	int count = 0; 
	for(int i = 0; i < size; i++)
	{
		count++;
	}
 
	return count;
}



void printIntArray(int array[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%4d", array[i]);
	}
	puts("");

}

int *InitalizeElementsOfArrayToZero(int Num)
{
	size_t i; // Counter

	int *n = malloc(Num * sizeof(int));

	// Initialize elements of array n to 0
	for(i = 0; i < Num; i++)
	{
		// Set elements at location i to 0
		n[i] = 0;
	}

	printf("%s%13s\n", "Element", "Value");

	// Output the content of the array
	for(i = 0; i < Num; i++)
	{
		printf("%7zu%13d\n", i, n[i]);
	}
	
	return n;

}

int *InitializeArrayWithRandomNumbers(int Num)
{
	size_t i;

	// Malloc Array Space 
	int *n = malloc(Num * sizeof(int));

	// Set the seed
	srand((unsigned)time(NULL));

	for(i = 0; i < Num; i++)
	{
		n[i] = rand() % 10;
		//printf("n[i] = %d\n", i, n[i]);
	}

	return n;

}

void countFreq(int *arrayOfRandomNumbers)
{
	// Counter for freq and and arrayOfRandomNumbers
	size_t random;
	size_t freq;

	// initialize frequency counter to 0
	int frequency[10] = {0};

	// arrayOfRandomNumbers = [3,4,9,2,4,8,9,5,5,9]
	// 1st iteration: ++frequency[arrayofRandomNumbers[0]]
	//				  ++frequency[3] 3 = 1
	// 2nd iteration: ++frequency[arrayofRandomNumbers[1]]
	//				  ++frequency[4] 4 = 1
	for(random = 0; random < 10; random++)
	{
		++frequency[arrayOfRandomNumbers[random]];
	}

	// Display results
	printf("%s%13s%17s\n", "Random Number", "Frequency", "Histogram");

	// output the frequencies in a tabluar form
	for(freq = 0; freq < 10; freq++)
	{
		printf("%7zu%13d              ", freq, frequency[freq]);

		// 1st iteration: 1 <= frequency[0] = 2
		//				  1 <= 2 print * j++
		//                2 <= 2 print ** j++
		//                3 <= 3 false ""
		for(int j = 1; j <= frequency[freq]; j++)
		{
		
			printf("%c", '*');
		}
		puts("");
	}
}

int *bubbleSortArray(int *array)
{
	printf("This is the original array\n");
	//Output original array
	for(int i = 0; i < 10; i++)
	{
		printf("%4d", array[i]);
	}
	puts("");

	// Use bubbleSort on data
	printf("Starting buddlesort\n");

	int pass;
	//clock_t start_t = clock();
	for(pass = 0; pass < 10; pass++)
	{
		// Need to loop over all the numbers
		for(int i = 0; i < 9; i++)
		{
			// Check if array[0] > array[1] need to swap
			// array[0] = 5   
			// array[0+1] = 1 
			// Since 5 > 1
			//  hold = 5
			//  array[0] = array[1] 
			//       1 is loaded at index 0
			//  array[1] = 5
			//       5 is loaded at index 1
			if(array[i] > array[i + 1])
			{
				// hold array[i]
				int hold = array[i];
				
				// Store largest number first
				array[i] = array[i + 1];

				// Store smallest number next
				array[i + 1] = hold;
				
			} 
		}
	}
	//clock_t end_t = clock();
	printf("BuddleSort Done!!!\n");
	//printf("%s%13s%13s%13s\n", "Start", "End", "Clock Per Sec", "Total");
	//printf("%ld", start_t);
	//printf("%15ld", end_t);
	//printf("%14d", CLOCKS_PER_SEC);
	//float total_t = (end_t - start_t);
	//printf("%14f\n\n", total_t/CLOCKS_PER_SEC);
	printf("This the sorted array\n");
	for(int i = 0; i < 10; i ++)
	{
		printf("%4d", array[i]);
	}

	puts("");
	return array;
}
int linearSearch(int *array, int searchKey, int size)
{
	int n;
	
	// Loop through array
	for(n = 0; n < size; n++)
	{
		if(array[n] == searchKey)
		{
			return n; // return location of searchKey
		}
	}

	// return -1 key not found
	return -1;
}

int searchingArray(int *array)
{
	int searchKey;
	int element;
	int size = 10;

	puts("Enter integer to search for: ");
	scanf("%d", &searchKey);

	// try and find the searchKey
	element = linearSearch(array, searchKey, size);

	if(element != -1)
	{
		printf("The searchKey was found at: %d\n", element);
		return element;
	}
	
	else
	{
		printf("The searchKey was not found: ");
	}
	return -1;

}
void printRow(int *array, int low, int mid, int high)
{
	size_t i;

	// loop through array
	for(i = 0; i < 10; i++)
	{
		// display spaces if outside current subarray range
		if( i < low || i > high)
		{
			printf("%s", "   ");
		}

		// display the middle element
		else if( i == mid)
		{
			// mark the middle value
			printf("%3d*", array[i]);
		}

		else
		{
			printf("%3d ", array[i]);
		}
	}
	puts("");

}

int BinarySearch(int *array, int lower, int higher, int searchKey)
{
	// variable to hold middle element of array
	int middle;

	// llop until low subscript is greater thean high subscript
	// 0 <= 10
	while( lower <= higher)
	{   //          0  1  2  3  4  5  6  7  8  9  
		// array = {1, 2, 4, 5, 5, 5, 5, 5, 6, 7}
		// find the middle of the array
		// 1st = 0 + 10 / 2 = 5
		// 2nd = 0 + 4 / 2 = 2
		// 3td = 0 + 1
		middle = (lower + higher) / 2;

		// display the subarray used in this loop iteration
		//       array, 0,    ,5     , 10
		//       array, 0,    ,2     , 10

		printRow(array, lower, middle, higher);
		//  1, 2, 4, 5, 5, 5*, 5, 5, 6, 7
		//  1, 2, 4*, 5, 5
		//  1*, 2 

		// if searchKey matched middle element return middle
		//       1   ==     5 (FALSE)
		//		 1   ==     4 (FALSE)

		if(searchKey == array[middle])
		{
			return middle;
		}

		// if searchKey less than middle element set new high
		// 1st      1     <     array[5] = 5
		// 2nd      1     <     array[2] = 4
		else if(searchKey < array[middle])
		{
			// Change array index Range to search
			//  4   =   5 - 1	
			// Ownly searching through 4 elements

			//  1   =   2 - 1
			// Only searching through 2 elements
			higher = middle - 1;
		}

		// if searchKey greater than middle element, set new low
		else
		{
			lower = middle + 1;
		}
		
	}
	return -1;
}

int numbersLessThanZeroInArray(int* array, int size)
{
	int numNeg;

	numNeg = 0;

	// Travel the array
	for(int i = 0; i < size; i++)
	{
		if(array[i] < 0)
		{
			numNeg = numNeg + 1;
		}
	}
	return numNeg;
}

int numberEqToZeroInArray(int* array, int size)
{
	int numZero;

	numZero = 0;

	//Travel the array
	for(int i = 0; i < size; i++)
	{
		if(array[i] == 0)
		{
			numZero = numZero + 1;
		}
	}
	return numZero;
}

int numberGreaterThanZeroInArray(int* array, int size)
{
	int numPos;
	numPos = 0;

	// Travel the array
	for(int i = 0; i < size; i++)
	{
		if(array[i] > 0)
		{
			numPos = numPos + 1;
		}
	}

	return numPos;
}

void findNumNegNumZeroNumPos(int* array, int size)
{
	// Need counter for numNeg, numZero, num
	int numNeg;
	int numZero;
	int numPos;

	// Initialize variable with 0
	numNeg = 0;
	numZero = 0;
	numPos = 0;

	// Travel the array
	for(int i = 0; i < size; i++)
	{
		// Check if value inside array in negative
		if(array[i] < 0)
		{
			numNeg = numNeg + 1;
		}
		
		// Check if value of array in == 0
		else if(array[i] == 0)
		{
			numZero = numZero + 1;
		}

		else
		{
			numPos = numPos + 1;
		}
	}

	printf("%d numbers are less then 0 \n", numNeg);
	printf("%d numbers are equal to 0 \n", numZero);
	printf("%d numbers are greater than 0 \n", numPos);

}

void findSecondLargestNumberInArray(int* array, int size)
{
	int largest;
	int secondLargest;

	largest = 0;

	// Travel the array
	for(int i = 0; i < size; i++)
	{
		// array[0] > array[1]
		if(array[i] < array[i+1])
		{	
			// Put largest in front
			largest = array[i+1];
		}
		else if(largest < array[i+1])
		{
			secondLargest = array[i+1];
		}
		
	}
	printf("%d is the first largest number\n", largest);
	printf("%d is the second largest number\n", secondLargest);
}








