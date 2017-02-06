#include <stdio.h>
#include <stdbool.h>
#include "../include/fileio.h"

#define MAX_CUSTOMERS 100
typedef struct customer {
    char name[20];
    int number;
}Customer;

void buildHeap(struct customer customer[], int);
void printHeapTree(struct customer customer[]);
void heapify(struct customer searchCustomer[], int, int);
void restoreUp(struct customer customer[], int);
void sort(struct customer customer[], int);
void swap(struct customer customer[], int, int);
void printData(struct customer customer[], int);

int main(int argc, const char *argv[])
{
	Customer customer[MAX_CUSTOMERS];
    int index = 0;
    int size = 0;
	FILE *fptr;

	if((fptr = fopen("../include/data/text.txt", "r")) == NULL) {
		printf("Error! Can not open file\n");
		exit(1);
	}

    while(fscanf(fptr, "%s %d", customer[index].name, &customer[index].number) != EOF) {
        index++;
    }

    size = index;
    printf("This is the size %d\n", size);
    sort(customer, size);
    printHeapTree(customer);
    printData(customer, size);

    fclose(fptr);
}

void sort(struct customer searchCustomer[], int numberOfStructElements){
    int total = numberOfStructElements - 1;
    printf("This is total in sort function: %d\n", total);

    for(int i = total / 2; i >= 0; i--){
        printf("This is i inside the for loop within sort: %d\n", i);
        heapify(searchCustomer, i, total);
    }
    for(int i = total; i > 0; i--){
        swap(searchCustomer, 0, i);
        --total;
        heapify(searchCustomer, 0, total);
    }

}

void heapify(struct customer searchCustomer[], int index, int total){
    printf("Heapify [%d] = %d\n", index, searchCustomer[index].number);

    int largest = index;
    int left = 2 * index;
    int right = left + 1;

    if(left <= total && searchCustomer[left].number > searchCustomer[largest].number){
        largest = left;

    }

    if(right <= total && searchCustomer[right].number > searchCustomer[largest].number){
        largest = right;
    }

    if(largest != index){
        swap(searchCustomer, index, largest);
        heapify(searchCustomer, largest, total);
    }

}

void swap(struct customer searchCustomer[], int index, int largest){
    do {
        struct customer temp = searchCustomer[index];
        searchCustomer[index] = searchCustomer[largest];
        searchCustomer[largest] = temp;
    } while (0);
}

void printHeapTree(struct customer customer[]){

printf("                                    %s %d\n", "index->0", customer[0].number);
printf("                  %s %d                            %s %d\n\n", "index->1", customer[1].number, "index->2", customer[2].number);
printf("          %s %d             %s %d                %s %d               %s %d\n\n","index->3", customer[3].number, "index->4", customer[4].number,"index->5", customer[5].number, "index->6", customer[6].number);
printf("%s %d       %s %d    %s %d       %s % d      %s %d  %s %d   %s %d \n    %s %d\n\n", "index->7", customer[7].number,"index->8", customer[8].number,
                                                                                     "index->9", customer[9].number,"index->10", customer[10].number,
                                                                                     "index->11", customer[11].number,"index->12", customer[12].number,
                                                                                     "index->13", customer[13].number, "index->14", customer[14].number);

}

void printData(struct customer customer[], int size){
    for (int i = 0; i <= size; i++) {
        printf("This is the index value: %d\n", i);
        printf("This is the struct value: %d\n", customer[i].number);
    }

}




////////////////// Extra Code /////////////////////////////////////////////////////////////////////////////////////////
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

//
//     //Text file data has been read into Customer struct
//
//
//
//    printf("The size is %d\n", size);
//
//    for(index = 0; index < size; index++){
//        printf("This is the index value: %d\n", index);
//        printf("This is the customer name: %s\n", customer[index].name);
//        printf("This is the customer number: %d\n\n", customer[index].number);
//    }






//while(fscanf(fptr, "%s %d\n", customer.name, &customer.number) != EOF) {
////		printf("%s %d\n", customer.name, customer.number);
////	}