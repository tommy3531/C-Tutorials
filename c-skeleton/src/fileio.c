#include <stdio.h>
#include <stdbool.h>
#include <dbg.h>
#include "../include/fileio.h"

#define MAX_CUSTOMERS 100
typedef struct customer {
    char name[20];
    int number;
}Customer;

void buildHeap(struct customer customer[], int);
void printHeapTree(struct customer customer[]);
void heapify(struct customer searchCustomer[], int, int);
void sort(struct customer customer[], int);
void swap(struct customer customer[], int, int);
void printData(struct customer customer[], int);
void sortAlpha(struct customer searchCustomer[], int);
void heapifyAlpha(struct customer searchCustomer[], int, int);
void swapAlpha(struct customer searchCustomer[], int, int);
void printDataAlpha(struct customer customer[], int);


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

    // This calls sorts by alpha
    sortAlpha(customer, size);

    // This display is alpha
    printDataAlpha(customer, size);

    // This calls sort by int
    sort(customer, size);

    // This sorts by int
    printData(customer, size);

    fclose(fptr);
}

void sortAlpha(struct customer searchCustomer[], int numberOfStructElements){
    int total = numberOfStructElements - 1;

    // This builds the heap
    for(int i = total / 2; i >= 0; i--){
        heapifyAlpha(searchCustomer, i, total);
    }

    // Go through the heap one element at a time
    for(int i = total; i > 0; i--){

        // Move parent to end
        swapAlpha(searchCustomer, 0, i);

        // Reduce the heapsize
        total--;

        // Since I reduced the heapsize I need to call heapify
        heapifyAlpha(searchCustomer, 0, total);
    }

}


void heapifyAlpha(struct customer searchCustomer[], int index, int total){

    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    // If the left child is larger than the parent node
    if(left <= total && searchCustomer[left].name > searchCustomer[largest].name){
        // Make the left the largest node
        largest = left;

    }

    // If the right child is larger than the parent node
    if(right <= total && searchCustomer[right].name > searchCustomer[largest].name){

        // Make the right node the largest
        largest = right;
    }

    // If the largest node is not the parent
    if(largest != index){
        swapAlpha(searchCustomer, largest, total);
        heapifyAlpha(searchCustomer, largest, total);
    }

}

void swapAlpha(struct customer searchCustomer[], int index, int largest){

    // If the result is > 0 swap index is the largest
    // If the result is < 0 the largest is largest
    // If the result is == 0 they are equal
    int result = strcmp(searchCustomer[index].name, searchCustomer[largest].name);
    if(result > 0){
        struct customer temp = searchCustomer[index];
        searchCustomer[index] = searchCustomer[largest];
        searchCustomer[largest] = temp;
    }
}

void printDataAlpha(struct customer customer[], int size){

    printf("\nWe have the following customers (sorted by their names): \n\n");
    for (int i = 0; i <= size; i++) {
        printf("%10s   %d\n", customer[i].name, customer[i].number);
    }
    printf("\n");
}













//////////////////////// This work dont mess with it ///////////////////////////////////////////////////////////////////
void sort(struct customer searchCustomer[], int numberOfStructElements){
    int total = numberOfStructElements - 1;

    // Build the heap
    for(int i = total / 2; i >= 0; i--){
        heapify(searchCustomer, i, total);
    }

    // Extract element one by one from heap
    for(int i = total; i > 0; i--){

        // Move top root element to end element
        swap(searchCustomer, 0, i);

        // Reduce heap size
        total--;

        // Call heapify on reduced heap
        heapify(searchCustomer, 0, total);
    }

}

void heapify(struct customer searchCustomer[], int index, int total){
    //printf("Heapify [%d] = %d\n", index, searchCustomer[index].number);

    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

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
    printf("Their service order should be\n\n");
    for (int i = 0; i <= size; i++) {
        printf("%10s   %d\n", customer[i].name, customer[i].number);
    }
}




////////////////// Extra Code /////////////////////////////////////////////////////////////////////////////////////////
//resultLeft = strcmp(searchCustomer[left].name, searchCustomer[largest].name);
//printf("This is the index value: %d\n ",index);
//printf("Comparing Left %s with %s\n", searchCustomer[left].name, searchCustomer[largest].name);
//printf("This is the Leftresult: %3d\n\n", resultLeft);
//
//
//resultRight = strcmp(searchCustomer[right].name, searchCustomer[largest].name);
//printf("Comparing Right %s with %s\n", searchCustomer[right].name, searchCustomer[largest].name);
//printf("This is the Rightresult: %d\n\n", resultRight);

//    if(result < 0){
//        printf("Left %s < Largest %s\n", searchCustomer[left].name, searchCustomer[largest].name);
//    }
//
//    if(result > 0){
//        printf("Left %s > Largest %s\n", searchCustomer[left].name, searchCustomer[largest].name);
//    }
//
//    if(result == 0){
//        printf("Left %s == Largest %s\n", searchCustomer[left].name, searchCustomer[largest].name);
//    }

//printf("%s < %s\n", searchCustomer[left].name, searchCustomer[largest].name);
//printf("%d = %d\n", largest, left);
//printf("%s %s\n", searchCustomer[left].name, searchCustomer[largest].name);
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