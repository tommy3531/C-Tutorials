#include <stdio.h>
#include <stdbool.h>
#include <dbg.h>
#include "heapsort.h"

#define TSIZE 19

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
    //struct Record *link;
};

// Function prototype
void insert(struct student rec, struct Record table[], int, char[]);
int search(int key, struct student rec, struct Record table[]);
//void del(int key, struct Record table[]);
void display(struct Record table[]);
int hash(int);
void addFriend(struct student rec, struct Record table[], int, char[], int, char[]);
int getAsciiValueOfString(char name[], int strLength);
int getTheLengthOfTheString(char name[]);

int main(int argc, const char *argv[]) {
    printf("This is openAdressing.c\n");
    char friendName[20] = "";
    char searchNameKey[20] = "";
    char insertKeyName[20] = "";
    char personName[20] = "";

    struct Record table[TSIZE];

    struct student rec;

    int i, choice;

    for(i = 0; i <= TSIZE-1; i++){
        table[i].status = EMPTY;
    }

    while(1){
        printf("1. Insert a Person\n");
        printf("2. Search for a Person\n");
        printf("3. Delete a Person\n");
        printf("4. Display a Person\n");
        printf("5. Create Friendship\n");
        printf("6. UnFriend\n");

        printf("7. Exit\n\n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch(choice){
            case 1 :

                // Please enter name to store in struct
                printf("Please enter a name: ");

                // Read the value entered by use to struct data member
                scanf("%s", rec.studentName);

                // Copy the string from the struct to variable
                strcpy(insertKeyName, rec.studentName);

                // Get the length of the name entered by the user
                int strInsertNameKeyLength = getTheLengthOfTheString(insertKeyName);

                // Print out the string length returned from the function
                printf("%d\n", strInsertNameKeyLength);

                // Get the total ascii value of the string
                int strInsertNameKeyAsciiTotal = getAsciiValueOfString(insertKeyName, strInsertNameKeyLength);

                // Print out the ascii value of the string
                printf("%d AsciiTotal\n", strInsertNameKeyAsciiTotal);

                // Insert data into the struct
                insert(rec, table, strInsertNameKeyAsciiTotal, insertKeyName);
                break;
            case 2 :

                // Please entere name to search for
                printf("Enter a name to be searched for: ");

                // Read the value entered by the user into a variable
                scanf("%s", searchNameKey);

                // Get the length of the name string entered by the user
                int strSearchNameKeyLength = getTheLengthOfTheString(searchNameKey);

                // Get the total number of ascii values of the string
                int strSearchNameKeyAsciiTotal = getAsciiValueOfString(searchNameKey, strSearchNameKeyLength);

                // Search of the name
                i = search(strSearchNameKeyAsciiTotal, rec, table);
                if(i == -1){
                    printf("Key not found\n");
                } else {
                    printf("Key found at index %d\n", i);
                    printf("%d %s\n", table[i].info.studentId, table[i].info.studentName);
                }
                break;
            case 3 :
//                printf("Enter a key to be deleted\n");
//                scanf("%d", &key);
//                del(key, table);
                break;
            case 4 :
                display(table);
                break;
            case 5 :
                display(table);
                printf("Enter a name from the table: \n");
                scanf("%s", personName);
                int strPersonNameLength = getTheLengthOfTheString(personName);
                int asciiPersonNameTotal = getAsciiValueOfString(personName, strPersonNameLength);
                printf("This is the userName string lenght: %d\n", strPersonNameLength);
                printf("This is the userName ascii total: %d\n", asciiPersonNameTotal);
                display(table);
                printf("Enter a name from the table you would like to be friends with: \n");
                scanf("%s", friendName);
                int strfriendNameLength = getTheLengthOfTheString(friendName);
                int asciifriendNameTotal = getAsciiValueOfString(friendName, strfriendNameLength);
                printf("This is the friendName: %d\n", strfriendNameLength);
                printf("This is the friendName ascii total: %d\n", asciifriendNameTotal);

                int doesUserNameExist = search(asciiPersonNameTotal, rec, table);
                int doesFriendExist = search(asciifriendNameTotal, rec, table);
                if(doesUserNameExist <= -1) {
                    printf("Key not found\n");
                    break;
                }
                if (doesFriendExist <= -1){
                    printf("Key not found\n");
                    break;
                }

                else {
                    printf("Person: %d %s\n", table[doesUserNameExist].info.studentId, table[doesUserNameExist].info.studentName);
                    printf("Friend: %d %s\n", table[doesFriendExist].info.studentId, table[doesFriendExist].info.studentName);
                }
                addFriend(rec, table, doesUserNameExist, personName, doesFriendExist, friendName);
                //display(table);
                // AddFriend
                // rec, table

                break;
            default:
                printf("Invalid selection\n");
        }
    }
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

void insert(struct student rec, struct Record table[], int keyAsciiValue, char name[]){
    int i, location, h;

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


    for(i=1; i<TSIZE-1; i++){

        // If the table location is Empty of Deleted change the status of that location and add data
        if(table[location].status == EMPTY || table[location].status == DELETED){
            table[location].info = rec;
            table[location].status = PERSON;
            table[location].info.studentId = location;
            printf("Record inserted\n\n");
            return;
        }

        // If the key is a duplicate, show message and generate a new hash value
        if(table[location].info.studentId == h){
            printf("This is a duplicate key\n");
        }
        location = (h + i) % TSIZE;
    }

    // We visited the whole table and there was not open slot in the table
    printf("Record cant be inserted: Table overFlow\n");
}

int search(int key, struct student rec, struct Record table[]){
    int i, h, location;
    h = hash(key);

    location = h;

    printf("This Must %d = %d\n", table[location].info.studentId, h);
    for(i = 1; i < TSIZE; i++){

        // Stop searching when location is EMPTY
        if(table[location].status == EMPTY){
            return -1;
        }
        if(table[location].info.studentId == h){
            //insert(rec, table, location, name);
            return location;
        }
        location = (h + i) % TSIZE;
    }
    return -1;
}

void addFriend(struct student rec, struct Record table[], int personNameLocation, char personName[], int doesFriendExit, char friendName[]){

    printf("Requesting Friendship: %s\n", table[personNameLocation].info.studentName);
    printf("Receiving Friendship: %s\n", friendName);
    printf("StudentId %d\n", table[personNameLocation].info.studentId);
    printf("This should equal StudentId: %d\n", personNameLocation);

    if(table[personNameLocation].info.studentId == personNameLocation){
        strcpy(table[personNameLocation].info.friendName, friendName);
        table[personNameLocation].status = FRIEND;
    }
}

void display(struct Record table[]){
    int i;
    for(i=0; i<TSIZE; i++){
        //printf("[%i] : ", i);
        if(table[i].status == PERSON){
            printf("[%s] : ", "P");
            printf("%s\n", table[i].info.studentName);
        } else if(table[i].status == FRIEND){
            printf("[%s] : ", "F");
            printf("%s %s\n", table[i].info.studentName, table[i].info.friendName);
        } else {
            printf("Empty\n");
        }
    }
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