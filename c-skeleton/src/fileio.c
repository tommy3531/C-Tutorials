#include <stdio.h>
#include <stdbool.h>
#include "../include/fileio.h"

typedef struct Customer {
	char name[20];
	int number;
}Customer;

int main(int argc, const char *argv[])
{
	Customer customer;
	FILE *fptr;

	if((fptr = fopen("../include/data/customer.txt", "r")) == NULL) {
		printf("Error! Can not open file\n");
		exit(1);
	}
	while(fscanf(fptr, "%s %d\n", customer.name, &customer.number) != EOF) {
		printf("%s %d\n", customer.name, customer.number);
	}
}
