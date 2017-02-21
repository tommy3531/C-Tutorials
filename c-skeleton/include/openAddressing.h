#define TSIZE 10

enum  status {EMPTY, PERSON, FRIEND};

// Stores records of Person
struct Person{
    int personId;
    char personName[20];
    char friendName[20];
};

// Information about the Person and status
struct HashTable{
    struct Person info;
    enum status status;
    struct HashTable *link;
};

// Information about the Person friends
struct HashTableFriend{
    struct HashTable hashTableInfo;
    char personNameWithFriend[20];
    char personFriendName[20];
    struct HashTableFriend *HashLink;
};

// Function prototype
int runMenuChoiceOption();
int checkIfInt(int number);

int insert(struct Person list, struct HashTable *table[], int, char[]);
int search(int key, struct HashTable *table[]);
//void del(int key, struct Record table[]);
void display(struct HashTable *table);
int hash(int);
int unFriend(struct Person list, struct HashTable *table[], int, char[]);
int addFriend(struct Person list, struct HashTable *table[], int doesPersonNameExist, char personName[]);
int getAsciiValueOfString(char name[], int strLength);
int getTheLengthOfTheString(char name[]);
int displayFriend(struct HashTableFriend *table[]);
int unFriendOperation(struct Person list, struct HashTable *table[]);
void findPersonFriends(struct Person list, struct HashTable *table[]);
void displaySpecificPersonFriends(struct HashTable *table[], int location, char[]);
void findMatch(struct HashTable *table[], int location);
int checkIfCharacter(char *userValue);
int displayStructFriend(struct HashTableFriend *table[]);
void displaySpecificPersonFriendsHashTable(struct HashTable *table[], int location, char showFriends[]);
int addFriendToStruct(struct HashTable hashList, struct HashTable *table[], struct HashTableFriend *tableFriend[], int doesPersonNameExist, char friendName[]);
char * mallocForChar(char *name);

int checkIfInt(int number){
    if(isdigit(number)){
        printf("You entered a char\n");
    } else {
        printf("You entered a int %d: \n", number);
        return number;
    }
    return 0;
}


int checkIfCharacter(char *userValue){
    if(isalpha(*userValue)){
        printf("It is a character");
        return 1;
    } else {

    }
    return 0;
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

char * mallocForChar(char *name){
    //temp = (struct HashTable *) malloc(sizeof(struct HashTable));
    char *ptr = malloc(sizeof(strlen(name)));
    return ptr;
}

int insert(struct Person list, struct HashTable *table[], int keyAsciiValue, char name[]){
    int location, h, i;
    int personCount = 0;
    
    struct HashTable *temp;
    
    printf("%d This is the keyAsciiValue\n", keyAsciiValue);
    printf("%s This is the name\n", name);
    
    // Call hash and pass the key to generate a hashvalue
    h = hash(keyAsciiValue);
    
    // Print out the hashValue
    printf("This is the hash value: %d\n", h);
    
    // The hash value is the location within the array
    location = h;
    
    // Print out the location within the array
    printf("This is the location within the array: %d\n", location);
    
    for(i = 1; i < TSIZE; i++) {
        
        // If the table location is Empty of Deleted change the status of that location and add data
        if (table[location] == NULL) {
            temp = (struct HashTable *) malloc(sizeof(struct HashTable));
            temp->info = list;
            temp->status = PERSON;
            temp->info.personId = location;
            temp->link = table[location];
            table[location] = temp;
            printf("Record inserted\n\n");
            personCount++;
            return personCount;
        }
        
        // If the key is a duplicate, show message and generate a new hash value
        if (table[location]->info.personId == h) {
            printf("This is a duplicate key\n");
            printf("Generating new hash value\n");
        }
        location = (h + i) % TSIZE;
    }
    return personCount;
    
}


int unFriendOperation(struct Person list, struct HashTable *table[]){
    char unlinkFriend[20] = "";
    
    //char unlinkFriend[20] = "";
    char unFriendName[20] = "";
    int unlinkDeletedNameLength = 0;
    int asciiUnlinkedNameTotal = 0;
    int unLinkFriendExist = 0;
    int unFriendNameExist = 0;
    int unFriendCount = 0;
    
    //displayFriend(table);
    
    printf("Above are the relationship you can unlink\n");
    printf("Example First -> tom tim, please enter what first is pointing to do the unfriending\n");
    printf("Which friend would you like to use to do the unfriending with: \n");
    scanf("%s", unlinkFriend);
    unlinkDeletedNameLength = getTheLengthOfTheString(unlinkFriend);
    asciiUnlinkedNameTotal = getAsciiValueOfString(unlinkFriend, unlinkDeletedNameLength);
    printf("This is the deletedName string lenght: %d\n", unlinkDeletedNameLength);
    printf("This is the userName ascii total: %d\n", asciiUnlinkedNameTotal);
    unLinkFriendExist = search(asciiUnlinkedNameTotal, table);
    if (unLinkFriendExist <= -1 ) {
        printf("Key not found\n");
        return -1;
    } else {
        printf("Person: %s\n", table[unLinkFriendExist]->info.personName);
    }
    
    //displayFriend(table);
    
    printf("Enter the friends name: \n");
    scanf("%s", unFriendName);
    int strunfriendNameLength = getTheLengthOfTheString(unFriendName);
    int asciiunfriendNameTotal = getAsciiValueOfString(unFriendName, strunfriendNameLength);
    printf("This is the unfriendName: %d\n", strunfriendNameLength);
    printf("This is the unfriendName ascii total: %d\n", asciiunfriendNameTotal);
    
    unFriendNameExist = search(asciiunfriendNameTotal, table);
    
    if (unFriendNameExist <= -1){
        
        printf("Key not found\n");
        return -1;
    } else {
        
        printf("Unlinked: %s\n", table[unLinkFriendExist]->info.friendName);
        
    }
    unFriendCount = unFriend(list, table, unLinkFriendExist, unFriendName);
    return unFriendCount;
    
}

int unFriend(struct Person list, struct HashTable *table[], int unFriendLocation, char unFriendName[]){
    char empty[] = "";
    int count = 0;
    
    printf("Perform unFriending Operation with: %s\n", table[unFriendLocation]->info.personName);
    printf("No longer what to be friend with: %s\n", unFriendName);
    printf("StudentId %d\n", table[unFriendLocation]->info.personId);
    printf("This should equal StudentId: %d\n", unFriendLocation);
    
    if(table[unFriendLocation]->info.personId == unFriendLocation){
        strcpy(table[unFriendLocation]->info.friendName, empty);
        table[unFriendLocation]->status = PERSON;
        count++;
        printf("%d unFriendFunction if statement count\n", count);
        printf("%s", table[unFriendLocation]->info.friendName);
        printf("%d", table[unFriendLocation]->status);
    }
    printf("%d unFriendFunction count\n", count);
    return count;
}





int hash(int key){
    return (key%TSIZE);
}



int search(int key, struct HashTable *table[]) {
    //int i
    int h, location;
    h = hash(key);
    printf("This is the hashvalue: %d\n", h);
    location = h;
    printf("This is the location value: %d\n", location);
    
    struct HashTable *p = table[h];
    
    while (p != NULL) {
        if (p->info.personId == location) {
            printf("Inside the if statement struct value %d |h value %d\n", p->info.personId, location);
            return location;
        }
        p = p->link;
    }
    return location;
}


//int addFriend(struct Person list, struct HashTable *table[], int doesPersonNameExist, char friendName[]){
//
//    int friendCount = 0;
//    struct HashTableFriend *temp;
//    printf("Requesting Friendship: %s\n", table[doesPersonNameExist]->info.personName);
//    printf("Receiving Friendship: %s\n", friendName);
//    printf("StudentId %d\n", table[doesPersonNameExist]->info.personId);
//    printf("This should equal StudentId: %d\n", doesPersonNameExist);
//
//    if(table[doesPersonNameExist]->info.personId == doesPersonNameExist){
//
//        strcpy(table[doesPersonNameExist]->info.friendName, friendName);
//        table[doesPersonNameExist]->status = FRIEND;
//        friendCount++;
//    }
//    return friendCount;
//}


int addFriendToStruct(struct HashTable hashList, struct HashTable *table[], struct HashTableFriend *tableFriend[], int doesPersonNameExist, char friendName[]){
    printf("This is the addFriendToStruct");
    int friendCount = 0;
    struct HashTableFriend *temp;
    printf("Requesting Friendship: %s\n", table[doesPersonNameExist]->info.personName);
    printf("Receiving Friendship: %s\n", friendName);
    printf("StudentId %d\n", table[doesPersonNameExist]->info.personId);
    printf("This should equal StudentId: %d\n", doesPersonNameExist);
    
    if(table[doesPersonNameExist]->info.personId == doesPersonNameExist){
        temp = (struct HashTableFriend *)malloc(sizeof(struct HashTableFriend));
        
        temp->hashTableInfo = hashList;
        
        temp->hashTableInfo.info.personId = doesPersonNameExist;
        
        temp->HashLink = tableFriend[doesPersonNameExist];
        
        tableFriend[doesPersonNameExist] = temp;
        
        
        
        strcpy(tableFriend[doesPersonNameExist]->personNameWithFriend, table[doesPersonNameExist]->info.personName);
        strcpy(tableFriend[doesPersonNameExist]->personFriendName, friendName);
        tableFriend[doesPersonNameExist]->hashTableInfo.status = FRIEND;
        friendCount++;
        return friendCount;
    }
    return friendCount;
}

void display(struct HashTable *table) {
    int i;
    struct HashTable *p;
    for (i = 0; i < TSIZE; i++) {
        //printf("[%i] : ", i);
        if (table[i] != NULL) {
            p = table[i];
            while (p != NULL) {
                printf("%3d %3s %3s\n", p->info.personId, p->info.personName, p->info.friendName);
                p = p->link;
            }
        }
    }
    printf("\n");
}

void displaySpecificPersonFriends(struct HashTable *table[], int location, char showFriends[]){
    
    printf("Perform unFriending Operation with: %s\n", table[location]->info.personName);
    printf("No longer what to be friend with: %d\n", location);
    printf("StudentId %d\n", table[location]->info.personId);
    printf("This should equal StudentId: %d\n", location);
    
    if(table[location]->info.personId == location){
        printf("%s is friends with %s\n", showFriends, table[location]->info.friendName);
    }
    
}

int displayFriend(struct HashTableFriend *table[]){
    int i;
    int count = 0;
    struct HashTableFriend *p;
    for(i = 0; i < TSIZE; i++){
        if(table[i] != NULL && table[i]->hashTableInfo.status == FRIEND){
            p = table[i];
            while (p != NULL){
                printf("%s %s\n", p->personFriendName, p->personNameWithFriend);
                count++;
                p = p->HashLink;
            }
            return 1;
        }
    }
    return 0;
}

int displayStructFriend(struct HashTableFriend *table[]){
//    int i;
//    int count = 0;
//    struct HashTableFriend *p;
//    for(i = 0; i < TSIZE; i++){
//        if(table[i] != NULL && table[i]->hashTableInfo.status == FRIEND){
//            p = table[i];
//            while (p != NULL){
//                printf("%s %s\n", p->personNameWithFriend, p->personFriendName);
//                count++;
//                p = p->HashLink;
//            }
//            return 1;
//        }
//    }
//    return 0;
    int i;
    //int count = 0;
    //struct HashTableFriend *p;
    for(i = 0; i < TSIZE; i++){
        if(table[i] != NULL && table[i]->hashTableInfo.status == FRIEND){
            printf("%s %s\n", table[i]->personNameWithFriend, table[i]->personFriendName);
//            p = table[i];
//            while (p != NULL){
//                printf("%s %s\n", p->personNameWithFriend, p->personFriendName);
//                count++;
//                p = p->HashLink;
//            }
//            return 1;
        }
    }
    return 0;
}


















/////////////////////////////////////// Code That might work somewhere else ///////////////////////////////////////////
//void makeFriends(struct Record table[]){
//
//    char friendName[4];
//    printf("Enter friends name\n");
//    scanf("%c\n", friendName);
//    //int charToIntValue = atoi(friendName);
//    printf("%d\n\n\n\n", atoi(friendName));
//}

//int charToInt(char *friendName){
//    int charToIntValue = atoi(friendName);
//    return charToIntValue;
//}
//void del(int key, struct Record table[]){
//
//    int location = search(key, table,);
//    if(location == -1){
//        printf("Key not found\n");
//    } else {
//        table[location].status = DELETED;
//    }
//}

//printf("This Must %d = %d\n", table[location]->info.studentId, h);
//for(i = 1; i < TSIZE; i++){
//
//// Stop searching when location is EMPTY
//if(table[location]->status == EMPTY){
//return -1;
//}
//if(table[location]->info.studentId == h){
////insert(rec, table, location, name);
//return location;
//}
//location = (h + i) % TSIZE;
//}
//return -1;
//}
//if(table[i]->status == PERSON){
//printf("[%s] : ", "P");
//printf("%s\n", table[i]->info.studentName);
//} else if(table[i]->status == FRIEND){
//printf("[%s] : ", "F");
//printf("%s %s\n", table[i]->info.studentName, table[i]->info.friendName);
//} else {
//printf("Empty\n");
//}
//}
//}
// Please entere name to search for
//printf("Enter a name to be searched for: ");
//
//// Read the value entered by the user into a variable
//scanf("%s", searchNameKey);
//
//// Get the length of the name string entered by the user
//int strSearchNameKeyLength = getTheLengthOfTheString(searchNameKey);
//
//// Get the total number of ascii values of the string
//int strSearchNameKeyAsciiTotal = getAsciiValueOfString(searchNameKey, strSearchNameKeyLength);
//
//// Search of the name
//i = search(strSearchNameKeyAsciiTotal, rec, table);
//if(i == -1){
//printf("Key not found\n");
//} else {
//printf("Key found at index %d\n", i);
//printf("%d %s\n", table[i]->info.studentId, table[i]->info.studentName);
//}
//display(table);
//printf("Enter a name from the table: \n");
//scanf("%s", personName);
//int strPersonNameLength = getTheLengthOfTheString(personName);
//int asciiPersonNameTotal = getAsciiValueOfString(personName, strPersonNameLength);
//printf("This is the userName string lenght: %d\n", strPersonNameLength);
//printf("This is the userName ascii total: %d\n", asciiPersonNameTotal);
//display(table);
//printf("Enter a name from the table you would like to be friends with: \n");
//scanf("%s", friendName);
//int strfriendNameLength = getTheLengthOfTheString(friendName);
//int asciifriendNameTotal = getAsciiValueOfString(friendName, strfriendNameLength);
//printf("This is the friendName: %d\n", strfriendNameLength);
//printf("This is the friendName ascii total: %d\n", asciifriendNameTotal);
//
//int doesUserNameExist = search(asciiPersonNameTotal, rec, table);
//int doesFriendExist = search(asciifriendNameTotal, rec, table);
//if(doesUserNameExist <= -1) {
//printf("Key not found\n");
//break;
//}
//if (doesFriendExist <= -1){
//printf("Key not found\n");
//break;
//}
//
//else {
//printf("Person: %d %s\n", table[doesUserNameExist]->info.studentId, table[doesUserNameExist]->info.studentName);
//printf("Friend: %d %s\n", table[doesFriendExist]->info.studentId, table[doesFriendExist]->info.studentName);
//}
//addFriend(rec, table, doesUserNameExist, personName, doesFriendExist, friendName);
//void displayHashTable(struct Record *table[]){
//
//    struct Record *p = *table;
//
//    while (p != NULL) {
//        printf("%d--->", p->link->info.studentId);
//        p = p->link;
//    }
//    printf("\n");
//
//}
//int displayMenuOption(){
//
//    int menuChoice = 0;
//
//    printf("1. P ⟨name⟩ – Create a person record of the specified first name.\n");
//    printf("2. F ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are friends.\n");
//    printf("3. U ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are no longer friends.\n");
//    printf("4. L ⟨name⟩ — Print out the friends of the specified person\n");
//    printf("5. Q ⟨name1⟩ ⟨name2⟩ — Check whether the two people are friends\n");
//    printf("6. X – terminate the program\n");
//    printf("7. Display Person\n");
//    printf("8. Display Person with Friends\n");
//
//    printf("9. Exit\n\n");
//
//    printf("Enter your choice: \n");
//    scanf("%d", &menuChoice);
//
//    // Check if value in menuChoice is an int
//    int isANumber = checkIfInt(menuChoice);
//    if(isANumber == 0) {
//
//        printf("Character was entered\n");
//    } else {
//        printf("This is the menuChoice value %d: \n", menuChoice);
//
//    }
//
//    return menuChoice;
//}
//
//int runMenuChoiceOption(){
//
//    int caseStatementValue = 0;
//    caseStatementValue = displayMenuOption();
//    switch(caseStatementValue){
//        case 1:
//            printf("Creating a person\n");
//            runMenuChoiceOption();
//            break;
//        case 2:
//            printf("Creating Friendship\n");
//            break;
//        case 3:
//            printf("Unlink Friendship\n");
//            break;
//        case 4:
//            printf("Print out friends of the specified person\n");
//            break;
//        case 5:
//            printf("Check wheather the two people are friends\n");
//            break;
//        case 6:
//            printf("Terminate");
//            break;
//        case 7:
//            printf("Display Person\n");
//            break;
//        case 8:
//            printf("Display Person with friends");
//            break;
//        default:
//            printf("Entered invalid choice\n");
//    }
//    return caseStatementValue;
//
//}