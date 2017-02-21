#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../include/openAddressing.h"

int main(int argc, const char *argv[]) {
    printf("This is openAdressing.c\n");
    
//    char *insertKeyName = NULL;
//    char *prt = NULL;
    char insertKeyName[20] = "";
    char friendName[20] = "";

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

    struct HashTable *table[TSIZE];

    struct HashTableFriend *hashTableFriend[TSIZE];

    struct Person list;
    
    struct HashTable hashList;

    int i, menu;
    int choice = 0;

    for (i = 0; i <= TSIZE - 1; i++) {
        table[i] = NULL;
    }
//
//    int caseValue = runMenuChoiceOption();
//    printf("%d", caseValue);


    for (int j = 0; j <= TSIZE - 1 ; j++) {

        hashTableFriend[i] = NULL;
    }

    menu = 0;

    do {
        choice = 0;
        printf("1. P ⟨name⟩ – Create a person record of the specified first name.\n");
        printf("2. F ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are friends.\n");
        printf("3. U ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are no longer friends.\n");
        printf("4. L ⟨name⟩ — Print out the friends of the specified person\n");
        printf("5. Q ⟨name1⟩ ⟨name2⟩ — Check whether the two people are friends\n");
        printf("6. DisplayFriend\n");
        printf("7. Display Person\n");

        printf("8. Exit\n\n");

        printf("Enter your choice: \n");

        
        // Check if the value stored in choice is an int
        char term;
        if(scanf("%d%c", &choice, &term) != 2 || term != '\n') {
            printf("failure\n");
        }

        switch (choice) {
            case 1 :
                
                // Please enter name to store in struct
                printf("Please enter a name: ");

                // Read the value entered by use to struct data member
                scanf("%s", list.personName);
                
//                prt = mallocForChar(insertKeyName);

                // Copy the string from the struct to variable
                strcpy(insertKeyName, list.personName);
//                memcpy(prt, list.personName, strlen(list.personName)+1);
        
        
                //Check if the user entered a digit instead of a character
                int checkValueOfCharacter = checkIfCharacter(insertKeyName);

                if (checkValueOfCharacter == 1) {

                    // Get the length of the name entered by the user
                    int strInsertNameKeyLength = getTheLengthOfTheString(insertKeyName);

                    // Print out the string length returned from the function
                    printf("%d\n", strInsertNameKeyLength);

                    // Get the total ascii value of the string
                    int strInsertNameKeyAsciiTotal = getAsciiValueOfString(insertKeyName, strInsertNameKeyLength);

                    // Print out the ascii value of the string
                    printf("%d AsciiTotal\n", strInsertNameKeyAsciiTotal);

                    // Insert data into the struct
                    personCount = insert(list, table, strInsertNameKeyAsciiTotal, insertKeyName);
                } else {
                    printf("You entered number why\n");
                    break;
                }
                
                break;
            case 2 :
                if (personCount > 0) {
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
                        strcpy(hashList.info.personName, personName);
                        printf("Person: %s", hashList.info.personName);
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
                        strcpy(hashList.info.friendName, friendName);
                        printf("Person: %d %s\n", table[doesFriendNameExist]->info.personId,
                               table[doesFriendNameExist]->info.personName);
                    }
                    friendCount = addFriendToStruct(hashList, table, hashTableFriend, doesPersonNameExist, friendName);
                    //friendCount = addFriend(list, table, doesPersonNameExist, friendName);
                } else {
                    printf("Please create a person, no pepople to connect\n");
                }
                break;
            case 3 :
                if (friendCount > 0) {
                    printf("FriendCount %d > 0\n", friendCount);
                    unFriendCount = unFriendOperation(list, table);
                    friendCount = friendCount - unFriendCount;
                    printf("%d friend Count\n", friendCount);
                    break;
                } else {
                    printf("No relationship please build some\n");
                }
                break;

            case 4:
                if (friendCount > 0) {
                    printf("Please enter a name to find their friends: \n");
                    scanf("%s", findTheirFriends);
                    strFindTheirFriendsLength = getTheLengthOfTheString(findTheirFriends);
                    asciiFindTheirFriendsTotal = getAsciiValueOfString(findTheirFriends, strFindTheirFriendsLength);
                    printf("This is the findTheirFriends string lenght: %d\n", strFindTheirFriendsLength);
                    printf("This is the findTheirFriends ascii total: %d\n", asciiFindTheirFriendsTotal);
                    doesFindTheirFriendsExist = search(asciiFindTheirFriendsTotal, table);
                    displaySpecificPersonFriends(table, doesFindTheirFriendsExist, findTheirFriends);
                    //displaySpecificPersonFriendsHashTable(hashTableFriend, doesFindTheirFriendsExist, findTheirFriends);
                } else {
                    printf("No friendship to list, please build some\n");
                }
                break;
            case 5:
                if (friendCount > 0) {
                    printf("Enter a person name: ");
                    scanf("%s", lookThroughFriends);
                    strlookThroughFriendsLength = getTheLengthOfTheString(lookThroughFriends);
        
        
                    printf("Enter enter their friends name: \n");
                    scanf("%s", matchFriend);
                    int asciimMtchFriendTotal = getAsciiValueOfString(lookThroughFriends, strlookThroughFriendsLength);
                    int findFriendLocationInArray = search(asciimMtchFriendTotal, table);
                    //temp = table[findFriendLocationInArray]->info.friendName;
                    printf("%s\n", temp);
                    strcpy(temp, hashTableFriend[findFriendLocationInArray]->personFriendName);
    
                    //strcpy(temp, table[findFriendLocationInArray]->info.friendName);
                    printf("This is the value of friendLocationINArray case 7: %d\n", findFriendLocationInArray);
                    printf("table[friend] = %s\n", temp);
                    printf("matchName = %s\n", matchFriend);
                    int v = strcmp(temp, matchFriend);
                    printf("The is the value from the stncmp function %d\n", v);
        
                    if (v < 0) {
                        printf("%s does not have a friend named %s\n", lookThroughFriends, matchFriend);
                    } else if (v > 0) {
                        printf("%s does not have a friend named %s\n", lookThroughFriends, matchFriend);
                    } else {
                        printf("They are equal\n");
                        printf("%s does have a friend name %s\n", lookThroughFriends, matchFriend);
            
                    }
        
                } else {
                    printf("No friendship\n");
                }
                break;
            case 6:
                displayStructFriend(hashTableFriend);
                break;
            case 7:
                display(table);
                break;
            case 8:
                printf("This is blank");
                break;

            default:
                printf("Invalid selection\n");
                break;

        }

        // This catches the char and re displays the menu if a char is entered
        getchar();
    } while(menu != 9);

}