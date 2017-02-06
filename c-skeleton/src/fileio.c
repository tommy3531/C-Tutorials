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
int stringCompare(struct customer customer[], int, int);


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

    int stringCompareValue = stringCompare(customer, 0, 1);
    printf("%d", stringCompareValue);

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

int stringCompare(struct customer customer[], int index, int largest){

    int count;
    printf("%s %s\n", customer[index].name, customer[largest].name);
    count = (*customer[index].name - *customer[largest].name);
    printf("This is the result value in stringCompare: %d\n", count);
    return count;
}

void swapAlpha(struct customer searchCustomer[], int index, int largest){

    // If the result is > 0 swap index is the largest
    // If the result is < 0 the largest is largest
    // If the result is == 0 they are equal
    int result = stringCompare(searchCustomer, index, largest);
    printf("This is the result in swapAlpha: %d\n", result);
    //int result = strcmp(searchCustomer[index].name, searchCustomer[largest].name);
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

void sort(struct customer searchCustomer[], int numberOfStructElements){
    int total = numberOfStructElements - 1;

    // Build the heap
    for(int i = total / 2; i >= 0; i--){
        heapify(searchCustomer, i, total);
    }

    // Extract element one by one from heap
    for(int i = total; i > 0; i--){

        // Move parent element to end element
        swap(searchCustomer, 0, i);

        // Reduce heap size
        total--;

        // Call heapify on reduced heap
        heapify(searchCustomer, 0, total);
    }

}

void heapify(struct customer searchCustomer[], int index, int total){

    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    // If the left child is larger than the parent node
    if(left <= total && searchCustomer[left].number > searchCustomer[largest].number){

        // Make the left node the largest
        largest = left;

    }

    // If the right child is larger than the parent node
    if(right <= total && searchCustomer[right].number > searchCustomer[largest].number){

        // Make the right node the largest
        largest = right;
    }

    if(largest != index){
        swap(searchCustomer, index, largest);
        heapify(searchCustomer, largest, total);
    }

}

void swap(struct customer searchCustomer[], int index, int largest){

    // Keep on doing th swap until o
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
