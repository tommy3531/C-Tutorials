#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/stackLinkedList/stackLinkedList.h"


int main(int argc, const char *argv[])
{
    int topValue;
    printf("This is from stackLinkedList.c \n");
    initializeStack();
    push(1);
    push(2);
    push(3);
    display();
    topValue = peek();
    printf("The value at the top of the stack is %d\n", topValue);


}