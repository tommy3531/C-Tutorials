#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList/linkedList.h"


int main(int argc, const char *argv[])
{
    printf("This is from linkedList.c \n");
    struct node *head = NULL;
    head = createList(head);
    displayList(head);
    insertAfter(head, 6, 2);
    head = insertBefore(head, 6, 2);
    head = insertAtPosition(head, 6, 3);
    displayList(head);


}

