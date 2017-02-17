#include <stdio.h>
#include <stdbool.h>
#include <dbg.h>
#include <curses.h>
#include <ctype.h>
#include "heapsort.h"

#define TSIZE 10

enum  type_of_record {EMPTY, PERSON, DELETED, OCCUPIED, FRIEND};

// Stores records of students
struct student{
    int studentId;
    char studentName[20];
    char friendName[20];
};

// Information about the student and status
struct Record{
    struct student info;
    enum type_of_record status;
    struct Record *link;
};

// Function prototype
int insert(struct student rec, struct Record *table[], int, char[]);
int search(int key, struct Record *table[]);
//void del(int key, struct Record table[]);
void display(struct Record *table[]);
int hash(int);
int unFriend(struct student rec, struct Record *table[], int, char[]);
int addFriend(struct student rec, struct Record *table[], int doesPersonNameExist, char personName[]);
int getAsciiValueOfString(char name[], int strLength);
int getTheLengthOfTheString(char name[]);
int displayFriend(struct Record *table[]);
int unFriendOperation(struct student rec, struct Record *table[]);
void findPersonFriends(struct student rec, struct Record *table[]);
void displaySpecificPersonFriends(struct Record *table[], int location, char[]);
void findMatch(struct Record *table[], int location);
void checkIfCharacter(char userValue[]);

int main(int argc, const char *argv[]) {
    printf("This is openAdressing.c\n");

    char friendName[20] = "";
    char insertKeyName[20] = "";
    char personName[20] = "";
    char findTheirFriends[20] = "";
    char lookThroughFriends[20] = "";
    char matchFriend[20] = "";
    char temp[20] = "";

    int doesFindTheirFriendsExist = 0;
    int strFindTheirFriendsLength = 0;
    int asciiFindTheirFriendsTotal = 0;
    int friendCount = 0;
    int personCount = 0;
    int unFriendCount = 0;
    int strlookThroughFriendsLength = 0;

    struct Record *table[TSIZE];

    struct student rec;

    int i, choice, menu;

    for(i = 0; i <= TSIZE-1; i++){
        table[i] = NULL;
    }

menu = 0;
while(menu != 7){

    printf("1. P ⟨name⟩ – Create a person record of the specified first name.\n");
    printf("2. F ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are friends.\n");
    printf("3. U ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are no longer friends.\n");
    printf("4. L ⟨name⟩ — Print out the friends of the specified person\n");
    printf("5. Q ⟨name1⟩ ⟨name2⟩ — Check whether the two people are friends\n");
    printf("6. X – terminate the program\n");

    printf("7. Exit\n\n");

    printf("Enter your choice: \n");
    scanf("%d", &choice);

    switch(choice) {
    case 1 :
        // Please enter name to store in struct
        printf("Please enter a name: ");

        // Read the value entered by use to struct data member
        scanf("%s", rec.studentName);
        
        // Copy the string from the struct to variable
        strcpy(insertKeyName, rec.studentName);
        
        //Check if the user entered a digit instead of a character
        checkIfCharacter(insertKeyName);

        // Get the length of the name entered by the user
        int strInsertNameKeyLength = getTheLengthOfTheString(insertKeyName);

        // Print out the string length returned from the function
        printf("%d\n", strInsertNameKeyLength);

        // Get the total ascii value of the string
        int strInsertNameKeyAsciiTotal = getAsciiValueOfString(insertKeyName, strInsertNameKeyLength);

        // Print out the ascii value of the string
        printf("%d AsciiTotal\n", strInsertNameKeyAsciiTotal);

        // Insert data into the struct
        personCount = insert(rec, table, strInsertNameKeyAsciiTotal, insertKeyName);
        break;
    case 2 :
        if(personCount > 0) {
            display(table);
            printf("Enter a name from the table: \n");
            scanf("%s", personName);
            int strPersonNameLength = getTheLengthOfTheString(personName);
            int asciiPersonNameTotal = getAsciiValueOfString(personName, strPersonNameLength);
            printf("This is the userName string lenght: %d\n", strPersonNameLength);
            printf("This is the userName ascii total: %d\n", asciiPersonNameTotal);
            int doesPersonNameExist = search(asciiPersonNameTotal, table);
            if (doesPersonNameExist <= -1) {
                printf("Key not found\n");
                break;
            } else {
                printf("Person: %d %s\n", table[doesPersonNameExist]->info.studentId,
                       table[doesPersonNameExist]->info.studentName);
            }

            printf("Enter a name from the table you would like to be friends with: \n");
            scanf("%s", friendName);
            int strfriendNameLength = getTheLengthOfTheString(friendName);
            int asciifriendNameTotal = getAsciiValueOfString(friendName, strfriendNameLength);
            printf("This is the friendName: %d\n", strfriendNameLength);
            printf("This is the friendName ascii total: %d\n", asciifriendNameTotal);


            int doesFriendNameExist = search(asciifriendNameTotal, table);

            if (doesFriendNameExist <= -1) {
                printf("Key not found\n");
                break;
            } else {
                printf("Person: %d %s\n", table[doesFriendNameExist]->info.studentId,
                       table[doesFriendNameExist]->info.studentName);
            }
            friendCount = addFriend(rec, table, doesPersonNameExist, friendName);
        } else {
            printf("Please create a person, no pepople to connect\n");
        }
        break;
    case 3 :
        if(friendCount > 0){
            printf("FriendCount %d > 0\n", friendCount);
            unFriendCount = unFriendOperation(rec, table);
            friendCount = friendCount - unFriendCount;
            printf("%d friend Count\n", friendCount);
            break;
        } else{
            printf("No relationship please build some\n");
        }
        break;

    case 4:
        if(friendCount > 0) {
            printf("Please enter a name to find their friends: \n");
            scanf("%s", findTheirFriends);
            strFindTheirFriendsLength = getTheLengthOfTheString(findTheirFriends);
            asciiFindTheirFriendsTotal = getAsciiValueOfString(findTheirFriends, strFindTheirFriendsLength);
            printf("This is the findTheirFriends string lenght: %d\n", strFindTheirFriendsLength);
            printf("This is the findTheirFriends ascii total: %d\n", asciiFindTheirFriendsTotal);
            doesFindTheirFriendsExist = search(asciiFindTheirFriendsTotal, table);
            displaySpecificPersonFriends(table, doesFindTheirFriendsExist, findTheirFriends);
        } else {
            printf("No friendship to list, please build some\n");
        }
        break;
    case 5:
        displayFriend(table);
    case 6:
        display(table);
        break;
    case 7:

        if(friendCount > 0) {
            printf("Enter a person name: ");
            scanf("%s", lookThroughFriends);
            strlookThroughFriendsLength = getTheLengthOfTheString(lookThroughFriends);
            

            printf("Enter enter their friends name: \n");
            scanf("%s", matchFriend);
            int asciimMtchFriendTotal = getAsciiValueOfString(lookThroughFriends, strlookThroughFriendsLength);
            int findFriendLocationInArray = search(asciimMtchFriendTotal, table);
            //temp = table[findFriendLocationInArray]->info.friendName;
            printf("%s\n", temp);
            strcpy(temp, table[findFriendLocationInArray]->info.friendName);
            printf("This is the value of friendLocationINArray case 7: %d\n", findFriendLocationInArray);
            printf("table[friend] = %s\n", temp);
            printf("matchName = %s\n", matchFriend);
            int v = strcmp(temp, matchFriend);
            printf("The is the value from the stncmp function %d\n", v);

            if(v < 0){
                printf("%s does not have a friend named %s\n", lookThroughFriends, matchFriend);
            }
            else if(v > 0) {
                printf("%s does not have a friend named %s\n", lookThroughFriends, matchFriend);
            }
            else {
                printf("They are equal\n");
                printf("%s does have a friend name %s\n", lookThroughFriends, matchFriend);

            }

        } else {
            printf("No friendship\n");
        }
        break;
    default:
        printf("Invalid selection\n");
    }

    // This catches the char and re displays the menu if a char is entered
    (void)getchar();
}
}

void checkIfCharacter(char userValue[]){
    int alpha = isalpha(*userValue);
    if(alpha){
        printf("It is a character");
    } else {
        printf("You entered a number\n");
    }
    return;
    
}


int unFriendOperation(struct student rec, struct Record *table[]){
    char unlinkFriend[20] = "";
    char unFriendName[20] = "";
    int unlinkDeletedNameLength = 0;
    int asciiUnlinkedNameTotal = 0;
    int unLinkFriendExist = 0;
    int unFriendNameExist = 0;
    int unFriendCount = 0;

    displayFriend(table);

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
        printf("Person: %s\n", table[unLinkFriendExist]->info.studentName);
    }

    displayFriend(table);

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
    unFriendCount = unFriend(rec, table, unLinkFriendExist, unFriendName);
    return unFriendCount;
    
}

int unFriend(struct student rec, struct Record *table[], int unFriendLocation, char unFriendName[]){
    char empty[] = "";
    int count = 0;

    printf("Perform unFriending Operation with: %s\n", table[unFriendLocation]->info.studentName);
    printf("No longer what to be friend with: %s\n", unFriendName);
    printf("StudentId %d\n", table[unFriendLocation]->info.studentId);
    printf("This should equal StudentId: %d\n", unFriendLocation);

    if(table[unFriendLocation]->info.studentId == unFriendLocation){
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

int hash(int key){
    return (key%TSIZE);
}

int insert(struct student rec, struct Record *table[], int keyAsciiValue, char name[]){
    int location, h, i;
    int personCount = 0;

    struct Record *temp;

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
            temp = (struct Record *) malloc(sizeof(struct Record));
            temp->info = rec;
            temp->status = PERSON;
            temp->info.studentId = location;
            temp->link = table[location];
            table[location] = temp;
            printf("Record inserted\n\n");
            personCount++;
            return personCount;
        }

        // If the key is a duplicate, show message and generate a new hash value
        if (table[location]->info.studentId == h) {
            printf("This is a duplicate key\n");
            printf("Generating new hash value\n");
        }
        location = (h + i) % TSIZE;
    }
    return personCount;

}

int search(int key, struct Record *table[]) {
    //int i
    int h, location;
    h = hash(key);
    printf("This is the hashvalue: %d\n", h);
    location = h;
    printf("This is the location value: %d\n", location);

    struct Record *p = table[h];

    while (p != NULL) {
        if (p->info.studentId == location) {
            printf("Inside the if statement struct value %d |h value %d\n", p->info.studentId, location);
            return location;
        }
        p = p->link;
    }
    return location;
}


int addFriend(struct student rec, struct Record *table[], int doesPersonNameExist, char friendName[]){

    int friendCount = 0;
    printf("Requesting Friendship: %s\n", table[doesPersonNameExist]->info.studentName);
    printf("Receiving Friendship: %s\n", friendName);
    printf("StudentId %d\n", table[doesPersonNameExist]->info.studentId);
    printf("This should equal StudentId: %d\n", doesPersonNameExist);

    if(table[doesPersonNameExist]->info.studentId == doesPersonNameExist){
        strcpy(table[doesPersonNameExist]->info.friendName, friendName);
        table[doesPersonNameExist]->status = FRIEND;
        friendCount++;
    }
    return friendCount;
}

void display(struct Record *table[]) {
    int i;
    struct Record *p;
    for (i = 0; i < TSIZE; i++) {
        //printf("[%i] : ", i);
        if (table[i] != NULL) {
            p = table[i];
            while (p != NULL) {
                printf("%3d %3s %3s\n", p->info.studentId, p->info.studentName, p->info.friendName);
                p = p->link;
            }
        }
    }
    printf("\n");
}

void displaySpecificPersonFriends(struct Record *table[], int location, char showFriends[]){

    printf("Perform unFriending Operation with: %s\n", table[location]->info.studentName);
    printf("No longer what to be friend with: %d\n", location);
    printf("StudentId %d\n", table[location]->info.studentId);
    printf("This should equal StudentId: %d\n", location);

    if(table[location]->info.studentId == location){
        printf("%s is friends with %s\n", showFriends, table[location]->info.friendName);
    }

}

int displayFriend(struct Record *table[]){
    int i;
    int count = 0;
    struct Record *p;
    for(i = 0; i < TSIZE; i++){
        if(table[i] != NULL && table[i]->status == FRIEND){
            p = table[i];
            while (p != NULL){
                printf("%s %s\n", p->info.studentName, p->info.friendName);
                count++;
                p = p->link;
            }
            return 1;
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