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
    
    // Creating a PersonObject and adding it to the PersonHashTable
    personHead = insertNameInBeginning(personHead, newPerson);
    personHead = insertNameInBeginning(personHead, newPerson1);
    personHead = insertNameInBeginning(personHead, newPerson2);
    
    displayList(personHead);
    
    // Start of the HashObject
    
    HashObject *personHashObjectHead = NULL;
    HashObject *createHashObject = CreateHashPersonObject(newPerson);
    HashObject *createHashObject1 = CreateHashPersonObject(newPerson1);
    HashObject *createHashObject2= CreateHashPersonObject(newPerson2);
    
    // Creating a HashMapObject from the personObject
    // Preparing the personObject to be added to the HashMap
    // Adding the HashMapObject to the PersonHashObject List of the HashMapObjects
    personHashObjectHead = insertPersonHashObjectAtBeginning(personHashObjectHead, createHashObject);
    personHashObjectHead = insertPersonHashObjectAtBeginning(personHashObjectHead, createHashObject1);
    personHashObjectHead = insertPersonHashObjectAtBeginning(personHashObjectHead, createHashObject2);
    
    displayListHashObject(personHashObjectHead);
    
    //Creating the HashTable from the HashObject
    
    HashTable *mainHashTable = NULL;
    mainHashTable = CreateHashTable(mainHashTable, createHashObject);
    mainHashTable = CreateHashTable(mainHashTable, createHashObject1);
    mainHashTable = CreateHashTable(mainHashTable, createHashObject2);
//    mainHashTable = insertHashTableAtBeginning(mainHashTable, createHashTable);
    
    displayListHashTable(mainHashTable);
    
    
    
}

