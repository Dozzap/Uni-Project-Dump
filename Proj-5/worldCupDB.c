#include "worldCupDB.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





void main() {
    printf("******************\n* 2211 World Cup *\n******************");
    char optionInp;
    for (;;) {
        printf("\nMain Menu: Input operation code:");
        scanf(" %c", &optionInp);
        switch (optionInp) {
            case 'h':
                printf("Input h (help) t (access teams) p (access players) or q (quit)");break;
            case 'q':
                return;
            case 't':
                printf("\nTeam Menu: Input a code for Team database: ");
                char teamVal;
                scanf(" %c", &teamVal);
                switch(teamVal){
                    case 'i':
                        inputTeam();break;
                    case 'u':
                        updateTeam();break;
                    case 's':
                        searchTeam();break;
                    case 'p':
                        printTeam();break;
                    case 'd':
                        deleteTeam();break;
                    default:printf("Error: Wrong Input1\n");break;
                }
                break;
            case 'p':
                printf("\nPlayer Menu:Input a code for Player database: ");
                char playerVal;
                scanf(" %c", &playerVal);
                switch(playerVal){
                    case 'i':
                        inputPlayer();break;
                    case 'u':
                        updatePlayer();break;
                    case 's':
                        searchPlayer();break;
                    case 'p':
                        printPlayer();break;
                    case 'd':
                        deletePlayer();break;
                    default:printf("Error: Wrong Input2\n");break;
                }
                break;
            default:
                printf("Error: Wrong Input\n");break;
        }
        printf("\n");
    }
}