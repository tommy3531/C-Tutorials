#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/dbg.h"
#include "../include/facttail.h"
#include "sorting/selectionsort.h"
#include "sorting/insertionsort.h"
#include "../include/binarysearch.h"
#define MAXNUMBERS 10

struct stuff
{
	int val;
	float b;
};

int main(int argc, const char *argv[])
{
	// Delcare a new struct of stuff
	// Delcare a variable s of type struct stuff
	// struct stuff s;
	
	// give the struct items values
//	s.val = 34;
//	s.b = 3.14;
	
	// print the values
//	printf("The val field is: %d\n", s.val);
//	printf("The b field is: %f\n", s.b);
//	int value = facttail(4, 1);
//	printf("This is the value from facttail: %d\n", value);

	//void selectionSort(int[], int, int);
	//int num[MAXNUMBERS];
	//printf("Type up to %d number followed by 0\n", MAXNUMBERS);
	//int n = 0;
	//int v = 0;
	//scanf("%d", &v);
	//while(v != 0 && n < MAXNUMBERS)
	//{
	//	num[n++] = v;
	//	scanf("%d", &v);
	//}
	//if (v != 0) 
	//{
          //    printf("More than %d numbers entered\n", MAXNUMBERS);
            //  printf("First %d used\n", MAXNUMBERS);
        //}

	//n numbers are stored from num[0] to num[n-1]
	//selectionSort(num, 0, n-1);
	//printf("\nThe sorted numbers are\n");
	//for (int h = 0; h < n; h++) 
	//{
	//	printf("%d ", num[h]);
	//}
	//printf("\n");

//	void insertionSort(int [], int);
	int num[MAXNUMBERS];
	printf("Type up to %d number followed by 0\n", MAXNUMBERS);
	int n = 0;
	int v = 0;
	scanf("%d", &v);
	while (v != 0 && n < MAXNUMBERS) 
	{
              num[n++] = v;
              scanf("%d", &v);
        }
	if (v != 0) 
	{
		printf("More than %d numbers entered\n", MAXNUMBERS);
		printf("First %d used\n", MAXNUMBERS);
	}
		//n numbers are stored from num[0] to num[n-1]
	//	insertionSort(num, n);
	//	printf("\nThe sorted numbers are\n");
	//for (int h = 0; h < n; h++)
	//{
	//	 printf("%d ", num[h]);
	//}
	//printf("\n");	
	int item = 3;
	int ans = binarySearch(item, num, 0, 11);
	if(ans == -1)
	{
		printf("%d not found\\n", item);

	}
	else
	{
		printf("%d found in location %d\n", item, ans);

	}

	

}
