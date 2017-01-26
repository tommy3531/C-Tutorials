#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int main(int argc, const char *argv[])
{
	int num;
	
	printf("Enter number: ");
	while(scanf("%d", &num) != 1)
	{
		printf("Enter number: ");
		while(getchar() != '\n');
	}
	printf("Inserted value: %d\n", num);
	return 0;
}
