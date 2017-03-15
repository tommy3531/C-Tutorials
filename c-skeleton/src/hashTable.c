/*
 * Tom Marler
 * CS 3050 Hashtable
 * TJM5ND
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TSIZE 10

enum  status {EMPTY, PERSON, FRIEND};

typedef struct person Person;
typedef struct hashtable HashTable;
typedef struct hashtable HashTableFriend;
typedef struct scoreBoard ScoreBoard;

struct person {
    int personKey;
    int personNameLength;
    int personNameAsciiValue;
    char *personName;
    char *friendName;
    enum status status;
    Person *next;
};

// Information about the Person and status
struct hashtable{
    Person *personLookUp;
    int hashTableSize;
    HashTable *link;
};

// Information about the Person friends
struct hashtablefriend{
    HashTable hashTableInfo;
    char *personNameWithFriend;
    char *personFriendName[20];
    HashTableFriend **HashLink;
};

struct scoreBoard{
    int personCount;
    int friendCount;
};


Person *CreatePerson(char *);
void displayPerson(Person *);
HashTable *CreateHashTable(int);
void displayTableHash(HashTable *);
int hash(int key);

HashTable *insertPersonInHashTable(HashTable *, Person *);
int getTheLengthOfTheString(char *);
int getAsciiValueOfString(char *, int);
int checkForIntegers(char *);
void displayTableHashOfFriends(HashTable *);
void displayTableHashOfPerson(HashTable *hashTable);
int search(HashTable *, int);

int addFriendShip(HashTable *PersonHashTable, int, int, int, char *, int, int, int, char *);

int deFriend(HashTable *PersonHashTable, char *, int, int, int, char *, int, int, int);
void displayTableHashOfSpecificPerson(HashTable *hashTable, int);



void displayTableHashArray(HashTable *hashTable[]);



int main(int argc, const char *argv[]) {
    
    // Menu Variables
    int menu = 0;
    
    // Chose the case statement
    int choice = 0;
    
    // Catch Character
    char term;
    
    // New Person Name to enter
    char *newPersonName = NULL;
    
    // SearchNameFirned
    char *searchNameFriend = NULL;
    
    // Find Person friends
    char *findPersonFriend = NULL;
    
    // Check If they are friends
    char *checkForFriendShip = NULL;
    
    // Find specific Person friends
    char *findAllFriends = NULL;
    
    //char *friendFind = NULL;
    
    char *personFriendName = NULL;
    
    char *temp = NULL;
    
    // Create a HashTable with 10 values
    HashTable *PersonHashTable = NULL;
    PersonHashTable = CreateHashTable(10);
    
    // Pointer to New Person
    Person *newPerson = NULL;
    
    // Search HashTable
//    HashTable *SearcHashTable = NULL;
    
    
    // Pointer to keep Track of FriendShips
    ScoreBoard counter;
    counter.friendCount = 0;
    counter.personCount = 0;
    
    // Search for name
    char *searchName = NULL;
    
    char *findingMatch = NULL;
    
    do{
        
        printf("1. P ⟨name⟩ – Create a person record of the specified first name.\n");
        printf("2. F ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are friends.\n");
        printf("3. U ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are no longer friends.\n");
        printf("4. L ⟨name⟩ — Print out the friends of the specified person\n");
        printf("5. Q ⟨name1⟩ ⟨name2⟩ — Check whether the two people are friends\n");
        printf("6. Display Person\n");
        printf("7. Display Friend\n");
        printf("8. Display PersonFriend\n");
        printf("9. Exit\n\n");
        
        printf("Enter your choice: \n");
        
        choice = 0;
        if(scanf("%d%c", &choice, &term) != 2 || term != '\n') {
            printf("failure\n");
        }
        
        //Go to the case based off the choice
        switch (choice) {
            case 1:
                // Please enter name to store in struct
                printf("Please enter a name: ");
                
                // Read the value entered by use to struct data member
                newPersonName = malloc(sizeof(char *));
                scanf("%s", newPersonName);
                
                // Check scanf for integers
                int newPersonNameValidationValue = checkForIntegers(newPersonName);
                
                // Check if newPersonName is valid
                if (newPersonNameValidationValue == 1) {
                    
                    // We have a valid name lets create a new Person
                    newPerson = CreatePerson(newPersonName);
                    
                    // Add the person to the hashTable
                    insertPersonInHashTable(PersonHashTable, newPerson);
                    
                    // Increse the friendCounter
                    counter.personCount++;
                } else {
                    printf("You did not enter a character\n");
                    break;
                }
                break;
            
            
            case 2:
                if (counter.personCount > 0) {
                    // We have friends
                    displayTableHashOfPerson(PersonHashTable);
                    printf("Enter a name from the above HashTable: \n");
                    searchName = malloc(sizeof(char *));
                    scanf("%s", searchName);
                    int nameLength = getTheLengthOfTheString(searchName);
                    int nameAscii = getAsciiValueOfString(searchName, nameLength);
                    int hashsearch = hash(nameAscii);
                    int searchNameValidation = search(PersonHashTable, hashsearch);
                    if (searchNameValidation != 1) {
                        printf("The name does not exist\n");
                        break;
                    } else {
                        printf("The name does exisit %s\n", searchName);
                    }
                    
                    printf("Please enter a Friend you would like to be friend with from the table: \n");
                    searchNameFriend = malloc(sizeof(char *));
                    scanf("%s", searchNameFriend);
                    int nameLenghtFriend = getTheLengthOfTheString(searchNameFriend);
                    int nameAsciiFriend = getAsciiValueOfString(searchNameFriend, nameLenghtFriend);
                    int hashFriend = hash(nameAsciiFriend);
                    int searchFriendValidation = search(PersonHashTable, hashFriend);
                    if (searchFriendValidation == 1) {
                        printf("You can be friends with %s\n", searchNameFriend);
                        
                    } else {
                        printf("The name does not exisit %s\n", searchNameFriend);
                    }
                    
                    addFriendShip(PersonHashTable, nameLength, nameAscii, hashsearch, searchName, nameLenghtFriend, nameAsciiFriend, hashFriend, searchNameFriend);
                    counter.friendCount++;
                    displayTableHashOfFriends(PersonHashTable);
                    printf("Look Above to find the friendship\n");
                } else {
                    printf("Please create a person, no people to connect\n");
                }
                
                break;
            
            case 3:
                if(counter.friendCount > 0){
                    printf("Enter a name from the above HashTable to Find there friends: \n");
                    findPersonFriend = malloc(sizeof(char *));
                    scanf("%s", findPersonFriend);
                    int findPersonFriendNameLength = getTheLengthOfTheString(findPersonFriend);
                    int findPersonFriendNameAscii = getAsciiValueOfString(findPersonFriend, findPersonFriendNameLength);
                    int findPersonHashSearch = hash(findPersonFriendNameAscii);
                    int searchNameValidation = search(PersonHashTable, findPersonHashSearch);
                    printf("No people to connected with\n");
                    if (searchNameValidation != 1) {
                        printf("The name does not exist\n");
                        break;
                    } else {
                        printf("The name does exisit %s\n", findPersonFriend);
                    }
                    displayTableHashOfFriends(PersonHashTable);
                    printf("Please enter a Friend name you think %s is friends with: \n", findPersonFriend);
                    checkForFriendShip = malloc(sizeof(char *));
                    scanf("%s", checkForFriendShip);
                    int checkForFriendShipLength = getTheLengthOfTheString(checkForFriendShip);
                    int checkForFriendShipAscii = getAsciiValueOfString(checkForFriendShip, checkForFriendShipLength);
                    int checkForFriendShipHash = hash(checkForFriendShipAscii);
                    int checkForFriendValidation = search(PersonHashTable, checkForFriendShipHash);
                    if (checkForFriendValidation == 1) {
                        printf("You can unfriend %s\n", checkForFriendShip);
                    } else {
                        printf("The name does not exisit %s\n", checkForFriendShip);
                    }
                    
                    deFriend(PersonHashTable, findPersonFriend, findPersonFriendNameLength, findPersonFriendNameAscii, findPersonHashSearch , checkForFriendShip, checkForFriendShipLength, checkForFriendShipAscii, checkForFriendShipHash);
                    displayTableHashOfPerson(PersonHashTable);
                    counter.friendCount--;
                    printf("Look Above to find the friendship has been deleted\n");
                } else {
                    printf("Please create a person, no people to connect\n");
                }
                
                break;
            
            case 4:
                if(counter.friendCount > 0) {
                    printf("Enter a name: \n");
                    
                    findAllFriends = malloc(sizeof(char *));
                    scanf("%s", findAllFriends);
                    int findAllFriendsLength = getTheLengthOfTheString(findAllFriends);
                    int findAllFriendsAscii = getAsciiValueOfString(findAllFriends, findAllFriendsLength);
                    int findAllFriendsHash = hash(findAllFriendsAscii);
                    int does = search(PersonHashTable, findAllFriendsHash);
                    printf("%d", does);
                    displayTableHashOfSpecificPerson(PersonHashTable, findAllFriendsHash);
                }else {
                    printf("No frienships to list, please build some\n");
                }
                break;
            
            case 5:
                if(counter.friendCount > 0){
                    printf("Enter a person Name: ");
                    findingMatch = malloc(sizeof(char *));
                    scanf("%s", findingMatch);
                    printf("Enter a person Friend: ");
                    personFriendName = malloc((sizeof(char *)));
                    scanf("%s", personFriendName);
                    int findingMatchLength = getTheLengthOfTheString(personFriendName);
                    int findingMatchAscii = getAsciiValueOfString(personFriendName, findingMatchLength);
                    int findingMatchHash = hash(findingMatchAscii);
                    int does = search(PersonHashTable, findingMatchHash);
                    printf("%d", does);
                    temp = strdup(PersonHashTable->personLookUp[findingMatchHash].friendName);
                    printf("%s", temp);
                    int v = strcmp(temp, personFriendName);
                    
                    if (v < 0) {
                        printf("%s does not have a friend named %s\n", findingMatch, personFriendName);
                    } else if (v > 0) {
                        printf("%s does not have a friend named %s\n", findingMatch, personFriendName);
                    } else {
                        printf("They are equal\n");
                        printf("%s does have a friend name %s\n", personFriendName, personFriendName);
                        
                    }
                    
                } else {
                    printf("No friendship\n");
                }
                break;
            
            case 6:
                printf("Printing the HashTable\n");
                displayTableHash(PersonHashTable);
                break;
            
            case 7:
                if(counter.friendCount != 0){
                    printf("No connection to be made\n");
                    
                } else{
                    printf("Printing the Friends HashTable Part Only \n");
                    displayTableHashOfFriends(PersonHashTable);
                }
                
                break;
            
            case 8:
                printf("Printing the Person HashTable Part Only \n");
                displayTableHashOfPerson(PersonHashTable);
                break;
            
            case 9:
                free(PersonHashTable->personLookUp);
                free(findPersonFriend);
                free(searchName);
                free(searchNameFriend);
                free(findPersonFriend);
                free(findAllFriends);
                free(findAllFriends);
            
            
            
            default:
                printf("Invalid Selection\n");
                break;
        }
        getchar();
    } while(menu != 2);
    
    
}


int deFriend(HashTable *hashTable, char* findPersonFriend, int findPersonFriendNameLength, int findPersonFriendNameAscii, int personHash, char *heckForFriendShip, int checkForFriendShipLength, int checkForFriendShipAscii, int friendHash){
    
    // Go to the the person location in the hashTable based off the hashvalue
    if(hashTable->personLookUp[personHash].personKey != personHash){
        printf("No friendShip Made\n");
    } else {
        hashTable->personLookUp[personHash].friendName = "";
        hashTable->personLookUp[personHash].status = PERSON;
    }
    return 1;
}

int addFriendShip(HashTable *hashTable, int nameLength, int nameAscii, int nameHash, char *searchName, int nameLenghtFriend, int nameAsciiFriend, int friendHash, char* searchNameFriend){
    
    // Go to the person location
    if(hashTable->personLookUp[nameHash].personKey != nameHash) {
        printf("No friendShip Made\n");
        
    } else{
        hashTable->personLookUp[nameHash].friendName = searchNameFriend;
        hashTable->personLookUp[nameHash].status = FRIEND;
    }
    return 1;
}

// Create a person
Person *CreatePerson(char *personName){
    
    printf("Lets see if we can do this\n");
    Person *person;
    
    person = (Person *)malloc(sizeof(Person));
    person->personKey = 0;
    person->personNameAsciiValue = 0;
    person->personNameLength = 0;
    person->friendName = "";
    
    person->personName = malloc(sizeof(char *));
    person->personName = personName;
    person->status = PERSON;
    person->next = NULL;
    
    /* TODO: Need to free */
    
    return person;
}

void displayPerson(Person *person){
    printf("This is the displayPerson Function\n");
    printf("This is the Person ID : %d\n", person->personKey);
    printf("This is the Person Name Length : %d\n", person->personNameLength);
    printf("This is the Person Name AsciiValue : %d\n", person->personNameAsciiValue);
    printf("This is the Person Name : %s\n", person->personName);
    printf("This is the Person Friend : %s\n", person->friendName);
    printf("This is the Person Status : %d\n", person->status);
    printf("This is the Person NextPtr : %p\n\n", person->next);
    
    
}
//// Create a hashtable based of the size the user wants
HashTable *CreateHashTable(int hashTableSize) {
    
    // Need a Hashtable to work with
    HashTable *hashTable = NULL;
    
    // Check to make sure the hashTable size greater than 1
    if (hashTableSize < 1) {
        return NULL;
    }
    
    // Need to allocate memory for the hashTable
    hashTable = (HashTable *) malloc(sizeof(hashTable));
    if (hashTable == NULL) {
        printf("No memory\n");
        return NULL;
    }
    
    // Need to malloc space for the pointer
    hashTable->personLookUp = malloc(sizeof(Person) * hashTableSize);
    
    // Initializing the hashTable values
    for(int i = 0; i < hashTableSize; i++){
        hashTable->personLookUp[i].personKey = 0;
        hashTable->personLookUp[i].personNameLength = 0;
        hashTable->personLookUp[i].personNameAsciiValue = 0;
        hashTable->personLookUp[i].personName = "";
        hashTable->personLookUp[i].friendName = "";
        hashTable->personLookUp[i].status = EMPTY;
        hashTable->personLookUp[i].next = NULL;
        hashTable->link = NULL;
        hashTable->hashTableSize = hashTableSize;
    }
    
    return hashTable;
}



HashTable *insertPersonInHashTable(HashTable *hashTable, Person *addPerson) {
    
    int personNameLenght = 0;
    int personNameLenghtAscii = 0;
    int hashValue = 0;
    
    // Get the lenght of the name
    personNameLenght = getTheLengthOfTheString(addPerson->personName);
    printf("This is the person name: %s\n", addPerson->personName);
    
    // Get the ASCII value of the string name
    personNameLenghtAscii = getAsciiValueOfString(addPerson->personName, personNameLenght);
    printf("%d This is the keyAsciiValue\n", personNameLenghtAscii);
    
    // Get the hashValue from the string Name, this will be used as the index value of the array
    hashValue = hash(personNameLenghtAscii);
    printf("This is the hash value: %d\n", hashValue);
    
    // Add the hash Value to the Person
    addPerson->personKey = hashValue;
    
    for (int i = 0; i < hashTable->hashTableSize; i++) {
        
        // Use the hashValue to lookup the HashTable if it is Zero we can insert
        if (hashTable->personLookUp[hashValue].personKey == 0) {
            
            hashTable->personLookUp[hashValue].personKey = hashValue;
            hashTable->personLookUp[hashValue].personNameLength = personNameLenght;
            hashTable->personLookUp[hashValue].personNameAsciiValue = personNameLenghtAscii;
            hashTable->personLookUp[hashValue].personName = addPerson->personName;
            hashTable->personLookUp[hashValue].status = addPerson->status;
            hashTable->personLookUp[hashValue].next = addPerson->next;
            addPerson->next = hashTable->personLookUp[hashValue].next;
            return hashTable;
        }
        
        // If it is equal to hashValue need to generate new hash
        if (hashTable->personLookUp[hashValue].personKey == hashValue) {
            printf("Duplicate Key, Generating New Hash Value\n");
        }
        hashValue = (hashValue + i) % TSIZE;
    }
    
    return hashTable;
}

int search(HashTable *hashTable, int hash){
    if (hashTable->personLookUp[hash].personKey != hash) {
        printf("The name does not exist!!");
        
        return 0;
    } else {
        printf("The searchName ascic Value %d: ", hashTable->personLookUp->personNameAsciiValue);
        printf("Found it");
    }
    
    return 1;
}

void displayTableHash(HashTable *hashTable) {
    printf("This is the displayTableHash Function\n\n");
    
    for(int i = 0; i < 10; i++) {
        printf("[%d] This is the Person ID : %d\n", i, hashTable->personLookUp[i].personKey);
        printf("This is the Person Name Length : %d\n", hashTable->personLookUp[i].personNameLength);
        printf("This is the Person Name Asics Value : %d\n", hashTable->personLookUp[i].personNameAsciiValue);
        printf("This is the Person Name : %s\n", hashTable->personLookUp[i].personName);
        printf("This is the Person Friend : %s\n", hashTable->personLookUp[i].friendName);
        printf("This is the Person Status : %d\n\n", hashTable->personLookUp[i].status);
        
    }
    
}

void displayTableHashOfSpecificPerson(HashTable *hashTable, int location) {
    printf("This is the displayTableHash Function\n\n");
    
    if (hashTable->personLookUp[location].personKey == location){
        printf("This is the Person ID : %d\n", hashTable->personLookUp[location].personKey);
        printf("This is the Person Name Length : %d\n", hashTable->personLookUp[location].personNameLength);
        printf("This is the Person Name Asics Value : %d\n", hashTable->personLookUp[location].personNameAsciiValue);
        printf("This is the Person Name : %s\n", hashTable->personLookUp[location].personName);
        printf("This is the Person Friend : %s\n", hashTable->personLookUp[location].friendName);
        printf("This is the Person Status : %d\n\n", hashTable->personLookUp[location].status);
    } else {
        printf("Person does not exist\n");
    }
    
    
}

void displayTableHashOfFriends(HashTable *hashTable){
    for(int i = 0; i < 10; i++) {
        printf("[%d] This is the Person ID : %d\n", i, hashTable->personLookUp[i].personKey);
        printf("This is the Person Name : %s\n", hashTable->personLookUp[i].personName);
        printf("This is the Person Friend : %s\n", hashTable->personLookUp[i].friendName);
        if(hashTable->personLookUp[i].status == 0){
            printf("This is the Person Status : %s", "Empty");
        }
        if(hashTable->personLookUp[i].status == 1){
            printf("This is the Person Status : %s", "Person");
        }
        if(hashTable->personLookUp[i].status == 2){
            printf("This is the Person Status : %s", "Friend");
        }
        printf("\n\n");
    }
}

void displayTableHashOfPerson(HashTable *hashTable){
    for(int i = 0; i < 10; i++) {
        printf("[%d] This is the Person ID : %d\n", i, hashTable->personLookUp[i].personKey);
        printf("This is the Person Name : %s\n", hashTable->personLookUp[i].personName);
        printf("This is the Person Friend : %s\n", hashTable->personLookUp[i].friendName);
        if(hashTable->personLookUp[i].status == 0){
            printf("This is the Person Status : %s", "Empty");
        }
        if(hashTable->personLookUp[i].status == 1){
            printf("This is the Person Status : %s", "Person");
        }
        if(hashTable->personLookUp[i].status == 2){
            printf("This is the Person Status : %s", "Friend");
        }
        printf("\n\n");
        
    }
}

void displayTableHashArray(HashTable *hashTable[]) {
    printf("This is the displayTableHashArrray Function\n\n");
    
    for(int i = 0; i < 10; i++) {
        if (hashTable[i]->personLookUp->personKey == 0){
            printf("[%d] This is the Person ID : %d\n", i, hashTable[i]->personLookUp[i].personKey);
            printf("[%d] This is the Person Name : %s\n", i, hashTable[i]->personLookUp[i].personName);
            printf("[%d] This is the Person Friend : %s\n", i, hashTable[i]->personLookUp[i].friendName);
            printf("[%d] This is the Person Status : %d\n", i, hashTable[i]->personLookUp[i].status);
        }
    }
}

int checkForIntegers(char *userValue){
    if(isalpha(*userValue)){
        printf("It is a character");
        return 1;
    } else {
        
    }
    return 0;
}


int hash(int key){
    return (key%TSIZE);
}


int getTheLengthOfTheString(char *personName){
    
    // Int variable to hold the string length
    int strLength = 0;
    
    // Using strlen to get the length of the character
    strLength = strlen(personName);
    
    // return the length
    return strLength;
}
int getAsciiValueOfString(char *personName, int strLength){
    
    // Int variable to hold the running total of ascii values
    int asciiTotal = 0;
    
    if(strLength != '\0'){
        for (int j = 0; j < strLength; ++j) {
            printf("%c -> %d\n", personName[j], (int)personName[j]);
            asciiTotal += (int)personName[j];
        }
    }
    
    // return the total
    return asciiTotal;
}



//void FreeMemory(HashTable *hashTable, Person *person){
//    free(hashTable->personLookUp);
//    free(hashTable);
//    free(person->personName);
//    free(person);
//}



















// Go to HashTable and use the hashValue for the index
//temp = hashTable->personLookUp + hashValue;

//printf("This is the hashTable index value: %p\n", temp);


//    /* TODO: This seems to be the problem becasue nothing is being sent to the mainHashTable that is global */
//    if (!temp) {
//
//        temp = (Person *) malloc(sizeof(Person));
//        hashTable->personLookUp[hashValue].personKey = (int) temp;
////
//////        hashTable->personLookUp = (Person *)malloc(sizeof(Person));
//////        hashTable->personLookUp = addPerson;
//////        hashTable->personLookUp->personKey = hashValue;
//////        hashTable->link = mainHashTable[hashValue];
////        //mainHashTable[hashValue] = temp;
////    }
//        return hashTable;
//
//    }

////HashTable *mainHashTable[TSIZE];
//ScoreBoard counter;
//
//
//Person *CreatePersonObject(char *);
//HashTable *CreateHashTable(int);
////void insert();
//int hash(int);
//int getTheLengthOfTheString(char *);
//int getAsciiValueOfString(char *, int);
////void addPersonToHashArray(Person *, HashTable *, HashTable *[], int);
////void displayScoreBoard(ScoreBoard boardCount);
//void displayPerson(Person *);
//void displayTableHashArray(HashTable *[]);
//void displayTableHash(HashTable *);
////void InsertPersonIntoHashTable(HashTable *, HashTable *[], Person *);
//
//
//int main(int argc, const char *argv[])
//{
//
//	Person *newPerson = CreatePersonObject("a");
//    printf("Display a person: \n\n");
//    displayPerson(newPerson);;
//    HashTable *intializeHashTable = CreateHashTable(10);
//    displayTableHash(intializeHashTable);
//
//}
//
//// Create a person
//Person *CreatePersonObject(char *personName){
//
//    printf("Lets see if we can do this");
//    Person *person;
//
//    printf("%s", personName);
//
//
//    person = (Person *)malloc(sizeof(Person));
//    // Hash Value is the personID
//    person->personKey = 0;
//
//
//    person->friendName = "";
//
//    // Add that string to the struct data member
//    strcpy(person->personName, personName);
//
//    // Set the status to PERSON
//    person->status = PERSON;
//
//    person->next = NULL;
//
//    free(person);
//    return person;
//}
//
//void displayPerson(Person *person){
//    printf("This is the displayPerson Function\n");
//    printf("This is the Person ID : %d\n", person->personKey);
//    printf("This is the Person Name : %s\n", person->personName);
//    printf("This is the Person Friend : %s\n", person->friendName);
//    printf("This is the Person Status : %d\n", person->status);
//
//}
//
//// Create a hashtable based of the size the user wants
//HashTable *CreateHashTable(int hashTableSize) {
//
//    // Need a Hashtable to work with
//    HashTable *hashTable = NULL;
//
//    // Check to make sure the hashTable size greater than 1
//    if (hashTableSize < 1) {
//        return NULL;
//    }
//
//    // Need to allocate memory for the hashTable
//    hashTable = (HashTable *) malloc(sizeof(hashTable) * hashTableSize);
//    if (hashTable == NULL) {
//        printf("No memory\n");
//        return NULL;
//    }
//
//    hashTable->personLookUp = malloc(sizeof(Person) * hashTableSize);
//
//    hashTable->link = NULL;
//
//    // Keep track of the size of the HashTable
//    hashTable->hashTableSize = hashTableSize;
//
//    for(int i = 0; i < hashTableSize; i++){
//        hashTable->personLookUp[i] = 0;
//    }
//
//    return hashTable;
//
//}
//
////void InsertPersonIntoHashTable(HashTable *hashTable, HashTable *mainHashArray[], Person *addPerson){
////
////    int personNameLenght = 0;
////    int personNameLenghtAscii = 0;
////    int hashValue = 0;
////
////    // Get the lenght of the name
////    personNameLenght = getTheLengthOfTheString(addPerson->personName);
////    printf("This is the person name: %s", addPerson->personName);
////
////    // Get the ASCII value of the string name
////    personNameLenghtAscii = getAsciiValueOfString(addPerson->personName, personNameLenght);
////    printf("%d This is the keyAsciiValue\n", personNameLenghtAscii);
////
////    // Get the hashValue from the string Name, this will be used as the index value of the array
////    hashValue = hash(personNameLenghtAscii);
////    printf("This is the hash value: %d\n", hashValue);
////
////    mainHashArray[hashValue]->personLookUp = addPerson;
//
////    HashTable *temp;
////    temp = (HashTable *)malloc(sizeof(*temp));
////    temp->personLookUp = *addPerson;
////    temp->personLookUp.personName = addPerson->personName;
////    temp->personLookUp.friendName = addPerson->friendName;
////    temp->personLookUp.personKey = hashValue;
////    temp->tableLink = mainHashArray[hashValue];
////    mainHashArray[hashValue] = temp;
//
//
////}//
////void displayTableHashArray(HashTable *hashTable[]) {
////    printf("This is the displayTableHash Function\n");
////
////    HashTable *p;
////    for(int i = 0; i < 10; i++) {
////        if (hashTable[i] != 0){
////            p = hashTable[i];
////            while (p != NULL) {
////                printf("[%d] This is the Person ID : %d\n", i, p->personLookUp[i]->personKey);
////                printf("[%d] This is the Person Name : %s\n", i, p->personLookUp[i]->personName);
////                printf("[%d] This is the Person Friend : %s\n", i, p->personLookUp[i]->friendName);
////                printf("[%d] This is the Person Status : %d\n", i, p->personLookUp[i]->status);
////            }
////        }
////    }
////}
//
//
//void displayTableHash(HashTable *hashTable) {
//    printf("This is the displayTableHash Function\n");
//
//    for(int i = 0; i < 10; i++) {
//        if (hashTable->personLookUp[i]->personKey == 0){
//            printf("[%d] This is the Person ID : %d\n", i, hashTable->personLookUp[i]->personKey);
//            printf("[%d] This is the Person Name : %s\n", i, hashTable->personLookUp[i]->personName);
//            printf("[%d] This is the Person Friend : %s\n", i, hashTable->personLookUp[i]->friendName);
//            printf("[%d] This is the Person Status : %d\n", i, hashTable->personLookUp[i]->status);
//        }
//    }
//}
//
//
//
//void displayScoreBoard(ScoreBoard boardCount){
//    printf("The personCount is %d: \n", boardCount.personCount);
//    printf("The friendCount is %d: \n", boardCount.friendCount);
//
//}
//
//int hash(int key){
//    return (key%TSIZE);
//}
//
//
//int getTheLengthOfTheString(char *personName){
//
//    // Int variable to hold the string length
//    int strLength = 0;
//
//    // Using strlen to get the length of the character
//    strLength = strlen(personName);
//
//    // return the length
//    return strLength;
//}
//int getAsciiValueOfString(char *personName, int strLength){
//
//    // Int variable to hold the running total of ascii values
//    int asciiTotal = 0;
//
//    if(strLength != '\0'){
//        for (int j = 0; j < strLength; ++j) {
//            //printf("%c -> %d\n", personName[j], (int)personName[j]);
//            asciiTotal += (int)personName[j];
//        }
//    }
//
//    // return the total
//    return asciiTotal;
//}
//
//
//
//
//
//
//
//
////void addPersonToHashArray(Person *addPersonElement, HashTable *personInfo, HashTable *mainHashTable[], int personNameAsciiValue){
////
////
////
////    //Person person;
////    int location, hashValue;
//////    int personCount = 0;
////
////    printf("%d This is the keyAsciiValue\n", personNameAsciiValue);
////
////    // Call hash and pass the key to generate a hashvalue
////    hashValue = hash(personNameAsciiValue);
////
////    // Print out the hashValue
////    printf("This is the hash value: %d\n", hashValue);
////
////    // The hash value is the location within the array
////    location = hashValue;
////
////    // Print out the location within the array
////    printf("This is the location within the array: %d\n", location);
////
////    for(int index = 1; index < TSIZE; index++) {
////
////        // If the table location has the status of NULL add the Person to the mainHashTable
////        if(mainHashTable[location] == NULL){
////
////            // Add the person to the mainHashTable according to the hashValue
////            mainHashTable[location] = personInfo;
////
////            // Show message that Person was inserted into MainHashTable
////            printf("Person was inserted into the mainHashTable at index %d\n", location);
////
////            b.personCount++;
////            free(personInfo);
////            free(addPersonElement);
////            return;
////        }
////
////        // Check for collision, if so generate new hash value and return the new location
////        if(mainHashTable[location]->info->personId == hashValue){
////            printf("Duplication key, generating new hash value\n");
////        }
////        location = (hashValue + index) % TSIZE;
////        printf("%d is the new HashValue\n", location);
////        return;
////    }
////
////
////}
//
//
//
//
////    hashTable->personLookUp = addPerson;
////    memcpy(hashTable->personLookUp[hashValue].personName, addPerson->personName, personNameLenght);
////    printf("This the hashTable->personLookup[%d] = %s",hashValue, hashTable->personLookUp[hashValue].personName);
////    memcpy(hashTable->personLookUp[hashValue].friendName, addPerson->friendName, 0);
////    printf("This the hashTable->personLookup[%d].friendName = %s", hashValue, hashTable->personLookUp[hashValue].friendName);
////    hashTable->personLookUp[hashValue].personKey = addPerson->personKey;
////    printf("This the hashTable->personLookup[%d].personKey = %d",hashValue, hashTable->personLookUp[hashValue].personKey);
////    hashTable->personLookUp[hashValue].status = addPerson->status;
////    printf("This the hashTable->personLookup[%d].status = %d", hashValue, hashTable->personLookUp[hashValue].status);
////    hashTable->tableLink = mainHashArray[hashValue];
////    mainHashArray[hashValue] = hashTable;
//
//
//
