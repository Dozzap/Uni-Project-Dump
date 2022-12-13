#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct teamData {
    int teamCode;
    char *teamName[25];
    char *teamSeed[2];
    char teamKit;
    struct teamData *next;
};

//Initialize the linked list
struct teamData *teamTop = NULL;
void inputTeam() {


    //Takes in an integer
    int teamCode;
    printf("       ");
    printf("%s", "Please input a valid Team Code: ");
    scanf("%d", &teamCode);

    //Checks to see if the value inputted already exist or is less than 0, if true, will print error
    struct teamData *tempPointer1;
    for (tempPointer1 = teamTop; tempPointer1!= NULL; tempPointer1= tempPointer1->next ){
        if (tempPointer1->teamCode == teamCode){
            printf("Error: Invalid Input. Team already Exist\n");
            return;
        }
    }
    if (teamCode <= -1){
        printf("Error: Invalid Input.\n");
        return;
    }


    //Takes in char array, checks if it already exist in the database
    //If true, prints error and bring back to main menu
    char *teamName;
    teamName = (char *) malloc(25);
    printf("       ");
    printf("%s", "Please input a valid Team Name: ");
    scanf(" %[^\n]%*c", teamName);

    struct teamData *tempPointer2;
    for (tempPointer2 = teamTop; tempPointer2!= NULL; tempPointer2= tempPointer2->next ){

        if (strcmp((char *)tempPointer2->teamName, teamName) == 0){
            printf("Error: Team already exist ");
            return;
        }
    }

    //Takes in char array, check if it is valid and if it does not exist in database
    //If true, will return to main menu
    char *teamSeed;
    teamSeed = (char *) malloc(2);
    printf("       ");
    printf("%s", "Enter group seeding of the team: ");
    scanf("%s",teamSeed);

    if (teamSeed[0] < 'A' || teamSeed[0] > 'H' || (int)teamSeed[1] - '0' > 4 || (int)teamSeed[1] - '0' < 1){
        return;
    }
    struct teamData *tempPointer3;
    for (tempPointer3 = teamTop; tempPointer3 != NULL; tempPointer3= tempPointer3->next ){

        if (strcmp((char *)tempPointer3->teamSeed, teamSeed) == 0){
            printf("Error: Team already exist");
            return;
        }
    }



    //Takes in a  char
    //Checks if the char is valid and if not, return to main menu
    char newTeamKit;
    printf("       ");
    printf("%s", "Please input a valid Team Kit color: ");
    scanf(" %c", &newTeamKit);

    //Checks if the value is in the specified set
    //If it is not, returns to main  menu
    switch (newTeamKit) {
        case 'R':
        case 'O':
        case 'Y':
        case 'G':
        case 'B':
        case 'I':
        case 'V':
            break;
        default:
            printf("Error: Input not valid. Returning to Main menu\n");
            return;
    }

    //If all inputs are valid, it will be stored in the structure and will be added to the linked list
    struct teamData *new_node;
    new_node = malloc(sizeof(struct teamData));
    new_node->teamCode = teamCode;
    strcpy((char *) new_node->teamName, teamName);
    strcpy((char *) new_node->teamSeed, teamSeed);
    new_node->teamKit = newTeamKit;
    new_node->next = teamTop;
    teamTop = new_node;



}

//function that searches for the team
void searchTeam(){
    //input the team code of the team you want to find
    //if the team exist, it will be printed out
    //if not, returns to main menu
    int teamFinder = 0;
    printf("Input the team code for the team you want to find: ");
    scanf("%d",&teamFinder);

    struct teamData *teamSearch;
    for (teamSearch = teamTop; teamSearch != NULL; teamSearch= teamSearch->next ){
        if (teamFinder == teamSearch->teamCode){
            printf("%-10s%-25s%-15s%-5s\n", "Team Code","Team Name","Team Seed","Team Color");
            printf("%-10d%-25s%-15s", teamSearch->teamCode, (char*)teamSearch->teamName,(char*)teamSearch->teamSeed);

            switch(teamSearch->teamKit){
                case 'R':printf("%-5s","Red");break;
                case 'O':printf("%-5s","Orange");break;
                case 'Y':printf("%-5s","Yellow");break;
                case 'G':printf("%-5s","Green");break;
                case 'B':printf("%-5s","Blue");break;
                case 'I':printf("%-5s","Indigo");break;
                case 'V':printf("%-5s","Violet");break;

            }
            printf("\n");
            return;
        }
    }
    printf("Team Not Found. Returning to Main menu\n");



}

//team updater
void updateTeam(){
    //takes in an integer input
    //checks if team code exist in database
    //if exist, it will prompt inputs to update
    //if not, prints error and returns to main menu
    int pointerCount=0;
    int teamFinder = 0;
    printf("Input the team code for the team you want to update: ");
    scanf("%d",&teamFinder);

    struct teamData *teamLocation;
    for (teamLocation = teamTop; teamLocation != NULL; teamLocation= teamLocation->next ){
        if (teamFinder == teamLocation->teamCode){
            break;
        }
        pointerCount++;
    }
    if (teamLocation == NULL){
        printf("Error: Team Does not exist.\n");
        return;
    }
    //takes in char array
    //checks team name already exist
    //this takes into account that you can input same team name for the team you want to update
    char *teamName;
    teamName = (char *) malloc(25);
    printf("       ");
    printf("%s", "Please input a valid Team Name: ");
    scanf(" %[^\n]%*c", teamName);

    struct teamData *tempPointer6;
    int similarCheck = 0;
    for (tempPointer6 = teamTop; tempPointer6!= NULL; tempPointer6= tempPointer6->next ){

        if (strcmp((char *)tempPointer6->teamName, teamName) == 0 && pointerCount != similarCheck){
            printf("Error: Team already exist");
            return;
        }
        similarCheck++;
    }


    //Takes in Team Seed
    //Allocates memory for 2 bits or 2 chars
    //takes in char array
    //checks team seed already exist
    //this takes into account that you can input same team seed for the team you want to update
    char *teamSeed;
    teamSeed = (char *) malloc(2);
    printf("       ");
    printf("%s", "Enter group seeding of the team: ");
    scanf("%s",teamSeed);

    if (teamSeed[0] < 'A' || teamSeed[0] > 'H' || (int)teamSeed[1] - '0' > 4 || (int)teamSeed[1] - '0' < 1){
        printf("Error: Team already exist");
        return;
    }
    similarCheck = 0;
    struct teamData *tempPointer7;
    for (tempPointer7 = teamTop; tempPointer7 != NULL; tempPointer7= tempPointer7->next ){

        if (strcmp((char *)tempPointer7->teamSeed, teamSeed) == 0 && pointerCount != similarCheck){
            printf("Error: Team already exist");
            return;
        }
        similarCheck++;
    }



    //Takes in a char
    //Checks if it is valid
    char newTeamKit;
    printf("       ");
    printf("%s", "Please input a valid Team Kit color: ");
    scanf(" %c", &newTeamKit);


    switch (newTeamKit) {
        case 'R':
        case 'O':
        case 'Y':
        case 'G':
        case 'B':
        case 'I':
        case 'V':
            break;
        default:
            printf("Error: Input not valid. Returning to Main menu\n");
            return;
    }

    //if all updated values are valid, it will be stored on the location you wanted to update
    free(teamLocation);
    teamLocation->teamCode= teamFinder;
    strcpy((char *) teamLocation->teamName, teamName);
    strcpy((char *) teamLocation->teamSeed, teamSeed);
    teamLocation->teamKit = newTeamKit;

}


//prints out all the data in the database
void printTeam(){
    printf("%-10s%-25s%-15s%-5s\n", "Team Code","Team Name","Team Seed","Team Color");
        struct teamData *printPointer = NULL;
        for (printPointer = teamTop; printPointer!= NULL; printPointer= printPointer->next ){
            printf("%-10d%-25s%-15s", printPointer->teamCode, (char*)printPointer->teamName,(char*)printPointer->teamSeed);

            switch(printPointer->teamKit){
                case 'R':printf("%-5s","Red");break;
                case 'O':printf("%-5s","Orange");break;
                case 'Y':printf("%-5s","Yellow");break;
                case 'G':printf("%-5s","Green");break;
                case 'B':printf("%-5s","Blue");break;
                case 'I':printf("%-5s","Indigo");break;
                case 'V':printf("%-5s","Violet");break;

            }
            printf("\n");
        }

}

//deletes team data in the database
void deleteTeam(){
    //takes in int
    //if the team code exist, it will be deleted
    //else, return an error
    int teamFinder = 0;
    printf("Input the team code for the team data you want to delete: ");

    scanf("%d",&teamFinder);

    struct teamData *curr,*prev;

    for (curr = teamTop, prev = NULL;curr != NULL && curr->teamCode !=teamFinder; prev=curr,curr= curr->next );

    if (curr == NULL){
        printf("Error: Team not found.\n");
        return;
    }
    if (prev == NULL){
        teamTop = teamTop->next;
    }
    else{
        prev->next = curr ->next;
    }
    printf("Team data successfully deleted\n");
    free(curr);



}



