#include <stdio.h>
#include <stdlib.h>
#include "sorting/selectionsort.h"
#define MAXNUMBERS 10

int main(int argc, const char *argv[])
{	

	void selectionSort(int[], int, int);
	int num[MAXNUMBERS];
	printf("SelectionSort\n");
	printf("Type up to %d number followed by 0\n", MAXNUMBERS);
	int n = 0;
	int v = 0;
	scanf("%d", &v);
	while(v != 0 && n < MAXNUMBERS)
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
	selectionSort(num, 0, n-1);
	printf("\nThe sorted numbers are\n");
	for (int h = 0; h < n; h++) 
	{
		printf("%d ", num[h]);
	}
	printf("\n");

}


