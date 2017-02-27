#define TSIZE 10

enum  status {EMPTY, PERSON, FRIEND};

typedef struct person Person;
typedef struct hashobject HashObject;
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
    Person *nextPerson;
};

struct hashtable{
    Person *personLookUp;
    int numberOfFriendShip;
    int numberOfPeople;
    int numberOfEmpty;
    int numberOfSlots;
    HashTable *nextHashTable;
};

// Information about the Person friends
struct hashtablefriend{
    HashObject *hashObjectLookUp;
    char *personNameWithFriend;
    char *personFriendName;
    HashTableFriend *link;
};

struct scoreBoard{
    int personCount;
    int friendCount;
};

Person *CreatePerson(char *);
Person *insertNameInBeginning(Person *, Person *);
HashObject *CreateHashPersonObject(Person *);
HashObject *insertPersonHashObjectAtBeginning(HashObject *, HashObject *);


int hashFunction(int);
int nameLenght(char *);
int nameAscii(char *, int);


void displayList(Person *personHead);


Person *personHead = NULL;
HashObject *personHashObjectHead = NULL;
HashTable *mainHashTableHead = NULL;
int hashTableSize = 0;
int numberOfPeople = 0;



int hashFunction(int nameAsciiValue){
    int personKey = 0;
    personKey = (nameAsciiValue % TSIZE);
    return personKey;
}

int nameLenght(char *name){
    int personNameLength = 0;
    personNameLength = strlen(name);
    return personNameLength;
}

int nameAscii(char *name, int nameLenght){
    
    // Int variable to hold the running total of ascii values
    int personNameAsciiValue = 0;
    
    if(nameLenght != '\0'){
        for (int j = 0; j < nameLenght; ++j) {
            printf("%c -> %d\n", name[j], (int)name[j]);
            personNameAsciiValue += (int)name[j];
        }
    }
    return personNameAsciiValue;
}

void displayList(Person *personHead) {
    
    // Declare a new struct to store current position
    Person *current;
    
    // Check if the head pointer is null
    if(personHead == NULL)
    {
        // The list is empty
        printf("The list is empty: \n");
    }
    
    printf("This is the List of People: \n");
    
    // Current node points to head
    current = personHead;
    
    // Print out the values from the until you reach the end AKA NULL
    while(current != NULL)
    {
        // Print out the value
        printf("[%d]", current->personKey);
        printf("[%s]", current->personName);
        
        current = current->nextPerson;
    }
    
    printf("\n");
}

void displayListHashTable(HashTable *mainHashTableHead) {
    
    // Declare a new struct to store current position
    HashTable *currentHashTable;
    
    // Check if the head pointer is null
    if(mainHashTableHead == NULL)
    {
        // The list is empty
        printf("The list is empty: \n");
        return;
    }
    
    printf("This is the hashTable: \n");
    
    // Current node points to head
    currentHashTable = mainHashTableHead;
    
    /* TODO: Need to fix only prints out one record */
    // Print out the values from the until you reach the end AKA NULL
    while(currentHashTable != NULL)
    {
        // Print out the value
        printf("Printing information out from the HashTable\n");
        printf("This is the Hash Table->hashObjectLookup: %p\n", currentHashTable->personLookUp);
        printf("This is the Hash Table->nextHashTable: %p\n", currentHashTable->nextHashTable);
        printf("This is the Hash Table->numberOfFriendShip: %d \n", currentHashTable->numberOfFriendShip);
        printf("This is the Hash Table->numberOfEmpty: %d \n", currentHashTable->numberOfEmpty);
        printf("This is the Hash Table->numberOfPeople: %d \n", currentHashTable->numberOfPeople);
        printf("This is the Hash Table->numberOfSlots: %d \n", currentHashTable->numberOfSlots);
    
    
        currentHashTable = currentHashTable->nextHashTable;
    }
    
    printf("\n");
}

void displayTableHash(HashTable *mainTable) {
    printf("This is the displayTableHash Function\n\n");
    
    for(int i = 0; i < 10; i++) {
        printf("[%d] This is the Person ID : %d\n", i, mainTable->personLookUp[i].personKey);
        printf("This is the Person Name Length : %d\n", mainTable->personLookUp[i].personNameLength);
        printf("This is the Person Name Asics Value : %d\n", mainTable->personLookUp[i].personNameAsciiValue);
        printf("This is the Person Name : %s\n", mainTable->personLookUp[i].personName);
        printf("This is the Person Friend : %s\n", mainTable->personLookUp[i].friendName);
        printf("This is the Person Status : %d\n", mainTable->personLookUp[i].status);
        printf("This is the HashTable numberOfEmpty : %d\n", mainTable->numberOfEmpty);
        printf("This is the HashTable numberOfFriendShip : %d\n", mainTable->numberOfFriendShip);
        printf("This is the HashTable numberOfPeople : %d\n", mainTable->numberOfPeople);
        printf("This is the HashTable numberOfSlots : %d\n\n", mainTable->numberOfSlots);

    }
}

// Need to create a person
Person *CreatePerson(char *personName){
    
    int nameLengthValue = 0;
    int nameAsciiValue = 0;
    int nameHashValue = 0;
    
    nameLengthValue = nameLenght(personName);
    nameAsciiValue = nameAscii(personName, nameLengthValue);
    nameHashValue = hashFunction(nameAsciiValue);
    
    // Need a pointer to a person
    Person *newPerson = NULL;
    
    // Need to malloc space
    newPerson = (Person *)malloc(sizeof(Person));
    
    // Need to set the struct person data members
    newPerson->personKey = nameHashValue;
    newPerson->personNameLength = nameLengthValue;
    newPerson->personNameAsciiValue = nameAsciiValue;
    
    newPerson->personName = malloc(sizeof(char *));
    newPerson->personName = personName;
    
    newPerson->friendName = malloc(sizeof(char *));
    newPerson->friendName = "";
    
    newPerson->status = PERSON;
    newPerson->nextPerson = NULL;
    numberOfPeople++;
    
    return newPerson;
}

Person *insertNameInBeginning(Person *personHead, Person *addPerson){
    
    addPerson->nextPerson = personHead;
    personHead = addPerson;
    return personHead;
}

// Create a hashtable based of the size the user wants
HashTable *CreateHashTable(HashTable *mainHashTable) {
    
    // Need a Hashtable to work with
    HashTable *hashTable = NULL;
    
    // Need to allocate memory for the hashTable
    hashTable = (HashTable *) malloc(sizeof(hashTable));
    if (hashTable == NULL) {
        printf("No memory\n");
        return NULL;
    }
    
    // Need to malloc space for the pointer

    hashTable->personLookUp = malloc(sizeof(Person));
    
    for (int i = 0; i < 4; i++) {
    
        // Create the hashTable Based off the NUmber of HashObjects
        hashTable->personLookUp[i].personKey = 0;
        hashTable->personLookUp[i].personName = "";
        hashTable->personLookUp[i].friendName = "";
        hashTable->personLookUp[i].personNameAsciiValue = 0;
        hashTable->personLookUp[i].personNameLength = 0;
        hashTable->personLookUp[i].nextPerson = NULL;
        hashTable->personLookUp[i].status = EMPTY;
        
        hashTable->numberOfEmpty = 0;
        hashTable->numberOfFriendShip = 0;
        hashTable->numberOfPeople = 0;
        hashTable->numberOfSlots = 0;
        hashTable->nextHashTable = NULL;
        hashTableSize++;

    }
    
    return hashTable;
}

HashTable *insertHashObjectIntoTheHashTableBeginning(HashTable *mainHashTableHead, HashTable *hashTable, Person *addPerson){
    
    
    for(int i = 0; i < 4; i++){
        
        /* TODO: NEED to check for Collision */
        /* TODO: NEED Get the size of teh HashTable */

        while(addPerson != NULL){
            hashTable->numberOfEmpty = hashTableSize - numberOfPeople;
            hashTable->numberOfSlots = hashTableSize;
            hashTable->numberOfFriendShip = 0;
            hashTable->numberOfPeople = numberOfPeople;
            hashTable->personLookUp[addPerson->personKey].personKey = addPerson->personKey;
            hashTable->personLookUp[addPerson->personKey].personName = addPerson->personName;
            hashTable->personLookUp[addPerson->personKey].friendName = addPerson->friendName;
            hashTable->personLookUp[addPerson->personKey].personNameAsciiValue = addPerson->personNameAsciiValue;
            hashTable->personLookUp[addPerson->personKey].personNameLength = addPerson->personNameLength;
            hashTable->personLookUp[addPerson->personKey].status = addPerson->status;
            hashTable->personLookUp[addPerson->personKey].nextPerson = addPerson->nextPerson;
            addPerson->nextPerson = hashTable->personLookUp[addPerson->personKey].nextPerson;
            return hashTable;
        }
    }
    
    return hashTable;
}



//void displayListHashObject(HashObject *personHashObjectHead) {
//
//    // Declare a new struct to store current position
//    HashObject *currentHashObject;
//
//    // Check if the head pointer is null
//    if(personHashObjectHead == NULL)
//    {
//        // The list is empty
//        printf("The list is empty: \n");
//        return;
//    }
//
//    printf("This is the HashObject List: \n");
//
//    // Current node points to head
//    currentHashObject = personHashObjectHead;
//
//    // Print out the values from the until you reach the end AKA NULL
//    while(currentHashObject != NULL)
//    {
//        // Print out the value
//        printf("This is the Hash Object->personLookUp: %p\n", currentHashObject->personLookUp);
//        printf("This is the Hash Object->personLookup->personKey: %d\n", currentHashObject->personLookUp->personKey);
//        printf("This is the Hash Object->personLookup->personName: %s\n", currentHashObject->personLookUp->personName);
//        printf("This is the Hash Object->link: %p \n", currentHashObject->nextHashObject);
//        printf("This is the Hash Object->friendlink: %p \n", currentHashObject->friendLink);
//        printf("This is the Hash Object->hashTableSize: %d \n\n", currentHashObject->hashTableSize);
//
//        currentHashObject = currentHashObject->nextHashObject;
//    }
//
//    printf("\n");
//}