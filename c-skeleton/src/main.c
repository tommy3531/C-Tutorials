#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <openAddressing.h>
//#include "../include/openAddressing.h"
#define TSIZE 10

enum  status {EMPTY, PERSON, FRIEND};

typedef struct person Person;
typedef struct hashtable HashTable;
typedef struct hashtable HashTableFriend;

struct person {
    int personId;
    char *personName;
    char *friendName;
};

// Information about the Person and status
struct hashtable{
    Person *info;
    enum status status;
    HashTable *link;
};

// Information about the Person friends
struct hashtablefriend{
    HashTable hashTableInfo;
    char *personNameWithFriend;
    char *personFriendName[20];
    HashTableFriend *HashLink;
};

HashTable *mainHashTable[TSIZE];

void displayHash(HashTable *[]);
Person *CreatePersonObject(int personId, char *personName, char *personFriendName);
HashTable *CreateHashTableObject();
void insert();
int hash(int);


int main(int argc, const char *argv[])
{
    // Print message start building person
    printf("Starting to build a person: \n");
	Person *newP = CreatePersonObject(1, "Tom", "Tim");
    printf("This is the personId: %d\n", newP->personId);
    printf("This is the personName: %s\n", newP->personName);
    printf("This is the personFriend: %s\n", newP->friendName);
    

    // Starting to build the hashTable
    printf("Starting to build the hashtable\n");
    CreateHashTableObject();

    displayHash(mainHashTable);

}

void addPerson(Person addPersonElement, HashTable *mainHashTable[], int personNameAsciiValue){
    
    //Person person;
    int location, h, i;
//    int personCount = 0;
    
    //HashTable *temp;
    
    printf("%d This is the keyAsciiValue\n", personNameAsciiValue);
    
    // Call hash and pass the key to generate a hashvalue
    h = hash(personNameAsciiValue);
    
    // Print out the hashValue
    printf("This is the hash value: %d\n", h);
    
    // The hash value is the location within the array
    location = h;
    
    // Print out the location within the array
    printf("This is the location within the array: %d\n", location);
    
    for(i = 1; i < TSIZE; i++) {
    
        // Malloc space for char
        addPersonElement.personName = (char *) malloc(strlen(addPersonElement.personName) + 1);
    
        addPersonElement.friendName = (char *) malloc(strlen(addPersonElement.friendName) + 1);
    }
}

Person *CreatePersonObject(int personId, char *personName, char *personFriendName){
    
    Person *person;
    // Malloc Space for person
    person = (Person *)malloc(sizeof(Person));
    
    // Check if person struct is null if so throw error
    if(person == NULL){
        printf("No memory\n");
        return NULL;
    }
    
    // Hash Value is the personID
    person->personId = personId;
    
    // Malloc space for char
    person->personName = (char *)malloc(strlen(personName)+1);
    
    person->friendName = (char *)malloc(strlen(personFriendName)+1);
    
    // Add that string to the struct data member
    memcpy(person->personName, personName, strlen(personName)+1);
    
    memcpy(person->friendName, personFriendName, strlen(personFriendName)+1);
    
    
    return person;
}
    
int hash(int key){
    return (key%TSIZE);
}

// This create an HashTable Object for a specific Person
// I think of this function as a student Record and it must be interested into an of Hash
HashTable *CreateHashTableObject(){

    // Malloc space for the hastTable
    HashTable *hashTable;
    hashTable = malloc(sizeof(HashTable));
    
    // Check if hashtable struct is null if so throw error
    if(hashTable == NULL){
        printf("No memory\n");
        return NULL;
    }
    
    hashTable->info = NULL;
    hashTable->status = EMPTY;
    hashTable->link = NULL;
    return hashTable;
    
}
int getTheLengthOfTheString(char name[]){
    
    // Int variable to hold the string length
    int strLength = 0;
    
    // Using strlen to get the length of the character
    strLength = strlen(name);
    
    // return the length
    return strLength;
}
int getAsciiValueOfString(char name[], int strLength){
    
    // Int variable to hold the running total of ascii values
    int asciiTotal = 0;
    
    if(strLength != '\0'){
        for (int j = 0; j < strLength; ++j) {
            printf("%c -> %d\n", name[j], (int)name[j]);
            asciiTotal += (int)name[j];
        }
    }
    
    // return the total
    return asciiTotal;
}

void displayHash(HashTable *hashTable[]) {
    
    HashTable *hashTablePtr;
    for(int i = 0; i < TSIZE; i++){
        if(hashTable[i] != NULL){
            hashTablePtr = hashTable[i];
            while(hashTablePtr != NULL){
                printf("%3d %3s %3s\n", hashTablePtr->info->personId, hashTablePtr->info->personName, hashTablePtr->info->friendName);
                hashTablePtr = hashTablePtr->link;
            }
        }
    }
    
    printf("\n");
}