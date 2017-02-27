#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/hashTable/hashTable.h"

Person *CreatePerson(char *);
Person *insertNameInBeginning(Person *, Person *);


int hashFunction(int);
int nameLenght(char *);
int nameAscii(char *, int);


void displayList(Person *personHead);

int main(int argc, const char *argv[]) {
    
    // Start of the Person Head
    
    Person *personHead = NULL;
    Person *newPerson = CreatePerson("Tom");
    Person *newPerson1 = CreatePerson("Tim");
    Person *newPerson2 = CreatePerson("Tony");
    Person *newPerson3 = CreatePerson("John");
    
    // Creating a PersonObject and adding it to the PersonHashTable
    personHead = insertNameInBeginning(personHead, newPerson);
    personHead = insertNameInBeginning(personHead, newPerson1);
    personHead = insertNameInBeginning(personHead, newPerson2);
    personHead = insertNameInBeginning(personHead, newPerson3);
    
    displayList(personHead);
    

    HashTable *mainHashTable = NULL;
    HashTable *createHashTable = CreateHashTable(mainHashTable);
    mainHashTable = insertHashObjectIntoTheHashTableBeginning(mainHashTable, createHashTable, newPerson);
    mainHashTable = insertHashObjectIntoTheHashTableBeginning(mainHashTable, createHashTable, newPerson1);
    mainHashTable = insertHashObjectIntoTheHashTableBeginning(mainHashTable, createHashTable, newPerson2);
    mainHashTable = insertHashObjectIntoTheHashTableBeginning(mainHashTable, createHashTable, newPerson3);
    
    
    
    displayListHashTable(mainHashTable);
    printf("This is MainTableHash pointer\n");
    displayTableHash(mainHashTable);
    
    
    
}

// Creating a HashMapObject from the personObject
// Preparing the personObject to be added to the HashMap
// Adding the HashMapObject to the PersonHashObject List of the HashMapObjects
//    personHashObjectHead = insertPersonHashObjectAtBeginning(personHashObjectHead, createHashObject);
//    personHashObjectHead = insertPersonHashObjectAtBeginning(personHashObjectHead, createHashObject1);
//    personHashObjectHead = insertPersonHashObjectAtBeginning(personHashObjectHead, createHashObject2);
//    personHashObjectHead = insertPersonHashObjectAtBeginning(personHashObjectHead, createHashObject3);


//displayListHashObject(personHashObjectHead);

//Creating the HashTable from the HashObject

//    HashTable *createHashTable1 = CreateHashTable(mainHashTable, createHashObject1);
//    HashTable *createHashTable2 = CreateHashTable(mainHashTable, createHashObject2);
//    HashTable *createHashTable3 = CreateHashTable(mainHashTable, createHashObject3);
//    mainHashTable = insertHashObjectIntoTheHashTableBeginning(mainHashTable, createHashTable1, createHashObject1);
//    mainHashTable = insertHashObjectIntoTheHashTableBeginning(mainHashTable, createHashTable2, createHashObject2);
//    mainHashTable = insertHashObjectIntoTheHashTableBeginning(mainHashTable, createHashTable3, createHashObject3);