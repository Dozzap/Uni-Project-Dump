#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct playerData {
    int playerCode;
    char *playerName[50];
    int playerAge;
    char *playerClub[50];
    struct playerData *next;
};

//initialize the playerTop of the linked list;
struct playerData *playerTop = NULL;
//input function for players
void inputPlayer() {

    //Takes in an integer
    int playerCode;
    printf("       ");
    printf("%s", "Please input a Player code: ");
    scanf("%d", &playerCode);

    //Checks if player code is already in the database, will return to main menu
    struct playerData *tempPointer1;
    for (tempPointer1 = playerTop; tempPointer1!= NULL; tempPointer1= tempPointer1->next ){
        if (tempPointer1->playerCode == playerCode){
            printf("Error: Player code already exist\n");
            return;
        }
    }
    if (playerCode <= -1){
        printf("Error: Player code not valid.\n");
        return;
    }

    //Takes in playerName
    //Allocates memory  for a maximum of 50 chars
    char *playerName;
    playerName = (char *) malloc(50);
    printf("       ");
    printf("%s", "Please input a valid Player Name: ");
    scanf(" %[^\n]%*c", playerName);

    //Takes in playerAge
    int playerAge;
    printf("       ");
    printf("%s", "Please input a valid Player Age: ");
    scanf(" %d", &playerAge);

    //Checks if age is under 17 or over 99, return if true
    if (playerAge < 17 || playerAge > 99){
        printf("Error: Invalid input.\n");
        return;
    }

    //takes in player's Club affiliation
    char *playerClub;
    playerClub = (char *) malloc(50);
    printf("       ");
    printf("%s", "Please input a valid Club: ");
    scanf(" %[^\n]%*c", playerClub);

    
    //If all inputs are valid, create a new data structure and value will be posted
    //data will be added to the playerTop beginning of the linked list

    struct playerData *new_node;
    new_node = malloc(sizeof(struct playerData));
    new_node->playerCode = playerCode;
    strcpy((char *) new_node->playerName, playerName);
    strcpy((char *) new_node->playerClub, playerClub);
    new_node->playerAge = playerAge;
    new_node->next = playerTop;
    playerTop = new_node;
}


//function for searching players
void searchPlayer(){
    //input the player code of the player you want to find
    //Will search through the database to see if player exist, and prints it
    //If not found, prints an error;
    int playerFinder = 0;
    printf("Input the Player code for the Player you want to find: ");
    scanf("%d",&playerFinder);

    struct playerData *playerSearch;
    for (playerSearch = playerTop; playerSearch != NULL; playerSearch= playerSearch->next ){
        if (playerFinder == playerSearch->playerCode){
            printf("%-15s%-25s%-15s%-5s\n", "Player code","Player Name","Player Age","Club affiliation");
            printf("%-10d%-25s%-15d%-5s\n", playerSearch->playerCode, (char*)playerSearch->playerName,playerSearch->playerAge,(char*)playerSearch->playerClub);
            return;
        }
    }
    printf("Player Not Found. Returning to Main menu\n");



}


//function for updating players
void updatePlayer(){
    //Works almost the same way as the input Player function
    //Locates player first and if found, will work as input Player function
    int pointerCount = 0;
    int playerFinder = 0;
    printf("Input the Player code for the Player you want to update: ");
    scanf(" %d",&playerFinder);

    struct playerData *playerLocation;
    for (playerLocation = playerTop; playerLocation != NULL; playerLocation= playerLocation->next ){
        if (playerFinder == playerLocation->playerCode){
            break;
        }
        pointerCount++;
    }
    //if the player is not found, returns to main menu
    if (playerLocation == NULL){
        printf("Error: Player does not exist\n");
        return;
    }

    char *playerName;
    playerName = (char *) malloc(50);
    printf("       ");
    printf("%s", "Please input a valid Player Name: ");
    scanf(" %[^\n]%*c", playerName);


    int playerAge;
    printf("       ");
    printf("%s", "Please input a valid Player Age: ");
    scanf(" %d", &playerAge);

    if (playerAge < 17 || playerAge > 99){
        printf("Error: Invalid input.\n");
        return;
    }

    char *playerClub;
    playerClub = (char *) malloc(50);
    printf("       ");
    printf("%s", "Please input a valid Club: ");
    scanf(" %[^\n]%*c", playerClub);

    //New values will be put inside
    playerLocation->playerCode= playerFinder;
    strcpy((char *) playerLocation->playerName, playerName);
    playerLocation->playerAge = playerAge;
    strcpy((char *) playerLocation->playerClub, playerClub);
}

//prints out all the datas in the database
void printPlayer(){

        printf("%-15s%-25s%-15s%-5s\n", "Player code","Player Name","Player Age","Club affiliation");
        struct playerData *tmp = NULL;
        for (tmp = playerTop; tmp!= NULL; tmp= tmp->next ){
            printf("%-15d%-25s%-15d%-5s\n", tmp->playerCode, (char*)tmp->playerName,tmp->playerAge,(char*)tmp->playerClub);
        }
}

//deletes player data
void deletePlayer(){
    //takes in int
    //if the player code exist, it will be deleted
    //else, return an error
    int playerFinder;
    printf("Input the Player code for the Player data you want to delete: ");

    scanf("%d",&playerFinder);

    struct playerData *curr,*prev;

    for (curr = playerTop, prev = NULL;curr != NULL && curr-> playerCode !=playerFinder; prev=curr,curr= curr->next );

    if (curr == NULL){
        printf("Error: Player not found.");
        return;
    }
    if (prev == NULL){
        playerTop = playerTop->next;
    }
    else{
        prev->next = curr ->next;
    }
    printf("Player data successfully deleted\n");
    free(curr);
}


