#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/binarysearch.h"
#define MAXNUMBERS 10

int main(int argc, const char *argv[])
{
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
