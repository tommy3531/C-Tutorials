#include <stdio.h>
#include <stdbool.h>
#include "../include/fileio.h"

#define MAX_CUSTOMERS 100
typedef struct Customer {
    char name[20];
    int number;
}Customer;

void restoreUp(struct Customer customerStruct[], int);
//struct Customer heapify(struct Customer customerStruct[], int);

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

    while(fscanf(fptr, "%s %d", customer[index].name, &customer[index].number) != EOF) {
        //heapify(customer, index);
        index++;
    }

    size = index;

     //Text file data has been read into Customer struct



    printf("The size is %d\n", size);

    for(index = 0; index < size; index++){
        printf("This is the index value: %d\n", index);
        printf("This is the customer name: %s\n", customer[index].name);
        printf("This is the customer number: %d\n\n", customer[index].number);
    }



    fclose(fptr);
}

//void heapSort(struct Customer customerStruct[], int index){
//
//    struct Customer customer[] = {{{0,0}}};
//    customer[index].number = heapify(customerStruct, index);
//    printf("%d", customer[index].number);
//
//        //readFromFile(customer, index, fptr);
//        //checkIfArrayHasRoom(customer, index);
//        //printf("%s %d\n", customer[index].name, customer[index].number);
//}
//
//
//struct Customer[] heapify(struct Customer customerStruct[], int index){
//
//    int item,i,j,k;
//    for(k=1 ; k<index ; k++)
//    {
//        item = customerStruct[k].number;
//        i = k;
//        j = (i-1)/2;
//
//        while( (i>0) && (item>customerStruct[j].number) )
//        {
//            customerStruct[i].number = customerStruct[j].number;
//            i = j;
//            j = (i-1)/2;
//        }
//        customerStruct[i].number = item;
//        printf("%d\n", customerStruct[item].number);
//    }
//    return customerStruct;
//    //printf("%s", customerStruct[])
//}
//void restoreUp(struct Customer customerStruct[], int keyThatValiatesTheHeapOrder){
//
//    // Key that has to be more up in the order
//    int key = 0;
//
//    // Parnet key
//    int parent = 0;
//
//    // Get the key that is in valilation of the heap order
//    key = customerStruct[keyThatValiatesTheHeapOrder].number;
//
//    // Calculate the parent keys position within the array
//    parent = keyThatValiatesTheHeapOrder/2;
//
//    while(customerStruct[parent].number > key){
//        customerStruct[keyThatValiatesTheHeapOrder].number = customerStruct[parent].number;
//        keyThatValiatesTheHeapOrder = parent;
//        parent = keyThatValiatesTheHeapOrder/2;
//    }
//    customerStruct[keyThatValiatesTheHeapOrder].number = key;
//
//    for(index = 0; index < size; index++){
//        printf("This is the index value : %d\n", index);
//        printf("This is the customer name: %s\n", customer[index].name);
//        printf("This is the customer number: %d\n\n", customer[index].number);
//        //readFromFile(customer, index, fptr);
//        //checkIfArrayHasRoom(customer, index);
//        //printf("%s %d\n", customer[index].name, customer[index].number);
//    }
//
//    printf("This is the sorted struct array\n");
//    for(int i = 0; i < 100; i++){
//        printf("Sorting by this number: %d\n\n", customerStruct[i].number);
////        printf("Customer Name: %s\n", customerStruct[i].name);
////        printf("Index Value: %d\n", i);
//
//
//    }
//
//
//}




//while(fscanf(fptr, "%s %d\n", customer.name, &customer.number) != EOF) {
////		printf("%s %d\n", customer.name, customer.number);
////	}