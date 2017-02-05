#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_CUSTOMERS 100


//void restoreUp(Customer customerStruct[], int);
//
//
//
//Customer customer[MAX_CUSTOMERS];

//int left(int index) {
//    int leftNode = 2 * index;
//    printf("This is the leftnode %d", leftNode);
//    return leftNode;
//}
//
//int right(int index){
//    int rightNode = 2 * index + 1;
//    printf("This is the rightNode %d", rightNode);
//    return rightNode;
//}
//void checkIfArrayHasRoom(Customer customer[], int index) {
//    while(customer[index].number != EOF){
//        if(index < MAX_CUSTOMERS) {
//            customer[index++] = customer[index].number;
//        }
//
//    }
//}

//void insert(int *parsedNumberValueFromFile,  char *parsedNameFromFile, int heapInsertionPosition){
//
//
//    // Increase heapSize becasue we are adding one item to heap
//    heapInsertionPosition++;
//
//    // Insert value into the struct at the given position
//    customer[heapInsertionPosition].number = *parsedNumberValueFromFile;
//
//    // Insert Char into the struct at the given position
//    customer[heapInsertionPosition].name = parsedNameFromFile;
//
//    // Pass the searchCustomerStruct[] with the heapInsertionPosition to restoreUpFunction
//    restoreUp(customer, heapInsertionPosition);
//
//}







//void fileCopy(FILE *readFrom, FILE *readTo)
//{
//
//
//    char buf[BSIZE];
//    int count;
//
//
//
//    while((count = fread(buf, 1, BSIZE, readFrom)) > 0)
//    {
//        //printf("File Opended");
//        fwrite(buf, 1, count, readTo);
//    }
//    printf("Data Read from read.txt to write.txt, Closing!!!\n");
//
//    fclose(readFrom);
//    fclose(readTo);
//
//    printf("Both files are closed\n");
//
//}


/*
 *
 *  Writes a string of characters to file
 */

//void fileFputs(FILE *ptr)
//{
//    if(!ptr)
//    {
//        printf("The file cannot be opened");
//        exit(1);
//    }
//    fputs("This is written to file with fputs new thing\n", ptr);
//}
