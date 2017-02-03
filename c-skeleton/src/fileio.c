#include <stdio.h>
#include <stdbool.h>
#include "../include/fileio.h"

#define MAX_CUSTOMERS 100
#define NAME_MAX_LENGHT 20

//int readFromFile(struct Customer[], int, FILE *);



int main(int argc, const char *argv[])
{
	Customer customer[MAX_CUSTOMERS];
    int index = 0;
    int size = 0;
	FILE *fptr;

	if((fptr = fopen("../include/data/customer.txt", "r")) == NULL) {
		printf("Error! Can not open file\n");
		exit(1);
	}

    while(!feof(fptr)) {
        readFromFile(customer, index, fptr);
        checkIfArrayHasRoom(customer, index);
        index++;
    }

    size = index;
    printf("The size is %d\n", size);

    for(index = 0; index < size; index++){
        printf("%s %d\n", customer[index].name, customer[index].number);
    }

    fclose(fptr);
}




//while(fscanf(fptr, "%s %d\n", customer.name, &customer.number) != EOF) {
////		printf("%s %d\n", customer.name, customer.number);
////	}