#include <stdio.h>
#include <stdbool.h>
#include <dbg.h>
#include "heapsort.h"

#define MAX_CUSTOMERS 10

typedef struct customer {
    char name[20];
    int number;
}Customer;

void heapify(struct customer searchCustomer[], int, int);
void sort(struct customer customer[], int);
void swap(struct customer customer[], int, int);
void printData(struct customer customer[], int);
void sortAlpha(struct customer searchCustomer[], int);
void heapifyAlpha(struct customer searchCustomer[], int, int);
void swapAlpha(struct customer searchCustomer[], int, int);
void printDataAlpha(struct customer customer[], int);
int stringCompare(struct customer customer[], int, int);
int printMin(struct customer customer[], int);

int main(int argc, const char *argv[])
{
	Customer customer[MAX_CUSTOMERS];
    int index = 0;
    int size = 0;
	FILE *fptr;

	if((fptr = fopen("../include/data/customer.txt", "r")) == NULL) {
		printf("Error! Can not open file\n");
	}

    while(fscanf(fptr, "%s %d", customer[index].name, &customer[index].number) != EOF) {
        index++;
    }

    // This is the number of struct elements
    size = index;

    // This calls sorts by alpha
    sortAlpha(customer, size);

    // This display is alpha
    printDataAlpha(customer, size);

    // This calls sort by int
    sort(customer, size);

    // This sorts by int
    printData(customer, size);

    // This prints the total of number
    int minData = printMin(customer, size);
    printf("The total waiting time of all customers will be : \n %d", minData);

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

    int customerValue = strncmp(searchCustomer[left].name,
                                    searchCustomer[largest].name, 5);

    printf("This is the value of strncmp %d\n", customerValue);


    // If the left child is larger than the parent node
    if(left <= total && customerValue < 0){

        // Make the left the largest node
        largest = left;

    }

    // If the right child is larger than the parent node
    if(right <= total && customerValue > 0){

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

    //printf("These are the strings to compare %s %s\n", customer[index].name, customer[largest].name);

    int count;
    count = (*customer[index].name - *customer[largest].name);
    return count;
}

void swapAlpha(struct customer searchCustomer[], int index, int largest) {
    do {

        struct customer temp = searchCustomer[index];
        searchCustomer[index] = searchCustomer[largest];
        searchCustomer[largest] = temp;
    } while (0);
}

void printDataAlpha(struct customer customer[], int size){

    //printf("\nWe have the following customers (sorted by their names): \n\n");
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

void heapify(struct customer searchCustomer[], int parent, int total){


    int largest = parent;
    int left = 2 * parent;
    int right = 2 * parent + 1;

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

    // If the largest is not the parent move it their
    if(largest != parent){
        swap(searchCustomer, parent, largest);
        heapify(searchCustomer, largest, total);
    }

}

void swap(struct customer searchCustomer[], int index, int smallest){

    // Keep on doing th swap

    do {
        struct customer temp = searchCustomer[index];
        searchCustomer[index] = searchCustomer[smallest];
        searchCustomer[smallest] = temp;
    } while (0);
}

int printMin(struct customer customer[], int size){

    int count = size;
    int temp = 0;
    int result = 0;
    for(int i = 0; i < size; i++){
        temp = customer[i].number;
        result += temp * count;
        count--;
    }
    return result;
}

void printData(struct customer customer[], int size){
    printf("Their service order should be\n\n");
    for (int i = 0; i <= size; i++) {
        printf("%10s   %d\n", customer[i].name, customer[i].number);
    }
}
