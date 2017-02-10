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
};

// Function prototype
void insert(struct student rec, struct Record table[]);
int search(int key, struct Record table[]);
void del(int key, struct Record table[]);
void display(struct Record table[]);
int hash(int key);
void addFriend(struct Record table[], int, char *);
int charToInt(char *);
//void makeFriends(struct Record table[]);

int main(int argc, const char *argv[]) {
    printf("This is openAdressing.c\n");
    char friendName = '\0';

    struct Record table[TSIZE];

    struct student rec;

    int i, key, choice;

    for(i = 0; i <= TSIZE-1; i++){
        table[i].status = EMPTY;
    }


    //makeFriends(table);

    while(1){
        printf("1. Insert a record\n");
        printf("2. Search a record\n");
        printf("3. Delete a record\n");
        printf("4. Display a record\n");
        printf("5. Find Friend\n");

        printf("6. Exit\n\n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch(choice){
            case 1 :
                printf("Enter studentID: ");
                scanf("%d", &rec.studentId);
                printf("Enter student name: ");
                scanf("%s", rec.studentName);
                insert(rec, table);
                break;
            case 2 :
                printf("Enter a key to be searched: ");
                scanf("%d", &key);
                i = search(key, table);
                if(i == -1){
                    printf("Key not found\n");
                } else {
                    printf("Key found at index %d\n", i);
                    printf("%d %s\n", table[i].info.studentId, table[i].info.studentName);
                }
                break;
            case 3 :
                printf("Enter a key to be deleted\n");
                scanf("%d", &key);
                del(key, table);
                break;
            case 4 :
                display(table);
                break;
            case 5 :
                printf("Enter friends name\n");
                scanf("%s", &friendName);
                //int value = charToInt(friendName);
                printf("%d %d\n", (int)friendName, atoi(&friendName));
                //int location = search(charToInt, table);

//                if(location == -1){
//                    printf("Key not found\n");
//                } else {
//                    printf("Key found at index %d\n", location);
//                    printf("%d %s\n", table[location].info.studentId, table[location].info.studentName);
//                }
//                //insert(rec, table);
//                addFriend(table, location, friendName);
                break;
            default:
                printf("Invalid selection\n");
        }
    }
}



int hash(int key){
    return (key%TSIZE);
}

void insert(struct student rec, struct Record table[]){
    int i, location, h;

    // Need to get the key from the record
    int key = rec.studentId;

    // Call hash and pass the key to generate a hashvalue
    h = hash(key);

    // The hash value is the location within the array
    location = h;


    for(i=1; i<TSIZE-1; i++){

        // If the table location is Empty of Deleted change the status of that location and add data
        if(table[location].status == EMPTY || table[location].status == DELETED){
            table[location].info = rec;
            table[location].status = PERSON;
            printf("Record inserted\n\n");
            return;
        }

        // If the key is a duplicate, show message and generate a new hash value
        if(table[location].info.studentId == key){
            printf("This is a duplicate key\n");
        }
        location = (h + i) % TSIZE;
    }

    // We visited the whole table and there was not open slot in the table
    printf("Record cant be inserted: Table overFlow\n");
}

int search(int key, struct Record table[]){
    int i, h, location;
    h = hash(key);

    location = h;

    for(i = 1; i < TSIZE; i++){

        // Stop searching when location is EMPTY
        if(table[location].status == EMPTY){
            return -1;
        }
        if(table[location].info.studentId == key){

            return location;
        }
        location = (h + i) % TSIZE;
    }
    return -1;
}

void addFriend(struct Record table[], int location, char *friendName){

    printf("Requesting Friendship: %s", table[location].info.studentName);
    printf("Receiving Friendship: %s", friendName);
}

void display(struct Record table[]){
    int i;
    for(i=0; i<TSIZE; i++){
        //printf("[%u] : ", table[i].status);
        if(table[i].status == PERSON){
            printf("Person: %d %s\n", table[i].info.studentId, table[i].info.studentName);
        } else if(table[i].status == FRIEND){
            printf("Friend: %d %s %s\n", table[i].info.studentId, table[i].info.studentName, table[i].info.friendName);
        } else {
            printf("Empty\n");
        }
    }
}
void del(int key, struct Record table[]){

    int location = search(key, table);
    if(location == -1){
        printf("Key not found\n");
    } else {
        table[location].status = DELETED;
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