#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/converter/converter.h"


int main(int argc, const char *argv[])
{
    int numberToBeConverted;
    int octalBase = 8;
    int hexBase = 15;

    printf("This is from converter.c\n");
    printf("Please enter a positive number: ");
    scanf("%d", &numberToBeConverted);

    printf("This is the binary form: ");
    toBinary(numberToBeConverted);
    printf("\n");

    printf("This is the Octal form: ");
    convertBase(numberToBeConverted, octalBase);
    printf("\n");

    printf("This is the Hexadecimal form: ");
    convertBase(numberToBeConverted, hexBase);
    printf("\n");

}
