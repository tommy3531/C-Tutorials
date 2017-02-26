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

// Information about the Person and status
struct hashobject{
    Person *personLookUp;
    int hashTableSize;
    HashTableFriend *friendLink;
    HashObject *nextHashObject;
    HashTable *nextHashTable;
};

struct hashtable{
    HashObject *hashObjectLookup;
    int numberOfFriendShip;
    int numberOfPeople;
    int numberOfEmpty;
    int numberOfSlots;
    int numberOfHashPerson;
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
int hashObjectSize = 1;
int hashTableSize = 1;
int numberOfPeople = 0;
int numberOfHashPerson = 0;


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

void displayListHashObject(HashObject *personHashObjectHead) {
    
    // Declare a new struct to store current position
    HashObject *currentHashObject;
    
    // Check if the head pointer is null
    if(personHashObjectHead == NULL)
    {
        // The list is empty
        printf("The list is empty: \n");
        return;
    }
    
    printf("This is the HashObject List: \n");
    
    // Current node points to head
    currentHashObject = personHashObjectHead;
    
    // Print out the values from the until you reach the end AKA NULL
    while(currentHashObject != NULL)
    {
        // Print out the value
        printf("This is the Hash Object->personLookUp: %p\n", currentHashObject->personLookUp);
        printf("This is the Hash Object->personLookup->personKey: %d\n", currentHashObject->personLookUp->personKey);
        printf("This is the Hash Object->personLookup->personName: %s\n", currentHashObject->personLookUp->personName);
        printf("This is the Hash Object->link: %p \n", currentHashObject->nextHashObject);
        printf("This is the Hash Object->friendlink: %p \n", currentHashObject->friendLink);
        printf("This is the Hash Object->hashTableSize: %d \n\n", currentHashObject->hashTableSize);
    
        currentHashObject = currentHashObject->nextHashObject;
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
    
    // Print out the values from the until you reach the end AKA NULL
    while(currentHashTable != NULL)
    {
        // Print out the value
        printf("Printing information out from the HashTable\n");
        printf("This is the Hash Table->hashObjectLookup: %p\n", currentHashTable->hashObjectLookup);
        printf("This is the Hash Table->nextHashTable: %p\n", currentHashTable->nextHashTable);
        printf("This is the Hash Table->numberOfFriendShip: %d \n", currentHashTable->numberOfFriendShip);
        printf("This is the Hash Table->numberOfEmpty: %d \n", currentHashTable->numberOfEmpty);
        printf("This is the Hash Table->numberOfPeople: %d \n", currentHashTable->numberOfPeople);
        printf("This is the Hash Table->numberOfSlots: %d \n\n", currentHashTable->numberOfSlots);
        
        printf("Printing information currentHashTable->hashObjectLookup->personLookUp->\n");
        printf("This is the currentHashtable->HashObjectLookUp->personLookup->personKey %d\n", currentHashTable->hashObjectLookup->personLookUp->personKey);
        printf("This is the currentHashtable->HashObjectLookUp->personLookup->personName %s\n", currentHashTable->hashObjectLookup->personLookUp->personName);
        printf("This is the currentHashtable->HashObjectLookUp->personLookup->personNameAsciiValue %d\n", currentHashTable->hashObjectLookup->personLookUp->personNameAsciiValue);
        printf("This is the currentHashtable->HashObjectLookUp->personLookup->personNameLength %d\n", currentHashTable->hashObjectLookup->personLookUp->personNameLength);
        printf("This is the currentHashtable->HashObjectLookUp->personLookup->status %d\n", currentHashTable->hashObjectLookup->personLookUp->status);
        printf("This is the currentHashtable->HashObjectLookUp->personLookup->nextPerson %p\n\n", currentHashTable->hashObjectLookup->personLookUp->nextPerson);
    
        currentHashTable = currentHashTable->nextHashTable;
    }
    
    printf("\n");
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

HashObject *CreateHashPersonObject(Person *addPerson) {
    
    // Need a Hashtable to work with
    HashObject *hashObject = NULL;
    
    // Need to allocate memory for the hashTable
    hashObject = (HashObject *) malloc(sizeof(HashObject));
    if (hashObject == NULL) {
        printf("No memory\n");
        return NULL;
    }

    
    // Need to malloc space for the pointer
    hashObject->personLookUp = (Person *)malloc(sizeof(Person));
    hashObject->personLookUp = addPerson;
    hashObject->hashTableSize = hashObjectSize;
    hashObject->nextHashObject = NULL;
    hashObject->nextHashTable = NULL;
    hashObject->friendLink = 0;
    hashObjectSize++;
    numberOfHashPerson++;
    return hashObject;
}

HashObject *insertPersonHashObjectAtBeginning(HashObject *personHashTableHead, HashObject *personHashObject){
    
    personHashObject->nextHashObject = personHashTableHead;
    personHashTableHead = personHashObject;
    return personHashTableHead;
}

// Create a hashtable based of the size the user wants
HashTable *CreateHashTable(HashTable *mainHashTable, HashObject *personHashObjectHead) {
    
    // Need a Hashtable to work with
    HashTable *hashTable = NULL;
    
    // Need to allocate memory for the hashTable
    hashTable = (HashTable *) malloc(sizeof(hashTable));
    if (hashTable == NULL) {
        printf("No memory\n");
        return NULL;
    }
    
    // Need to malloc space for the pointer
    hashTable->hashObjectLookup = malloc(sizeof(struct hashobject) * hashObjectSize);
    hashTable->hashObjectLookup = personHashObjectHead;
    // Initializing the hashTable values
    
    hashTable->numberOfEmpty = numberOfPeople - hashTableSize;
    hashTable->numberOfFriendShip = 0;
    hashTable->numberOfPeople = numberOfPeople;
    hashTable->numberOfSlots = hashTableSize;
    hashTable->hashObjectLookup = personHashObjectHead;
    hashTable->nextHashTable = mainHashTable;
    mainHashTable = hashTable;
    hashTableSize++;
    
    
    return hashTable;
}
