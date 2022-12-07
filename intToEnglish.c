/*

        Integer to English program
            >Converts inputed integers into it's english counterpart
            >made using switch statements, if statements, and math arithmetics

        Dhylan Usi
        251246124
        CS2211A

*/

#include <stdio.h>


void main(){

    //initialize variables
    //loopBool is outside of loop to avoid infinite loop
    int loopBool = 1;
    int inputVal,ifBool;
    

    while (loopBool == 1){

    //Will keep the if statement True;
    ifBool = 1;

    //Ask for input for the the int to english translation
    printf("Please enter a value (1-999, 0 to quit): \n");
    scanf("%d", &inputVal);

    //if input is 0, it will quit the program
    if (inputVal == 0){loopBool =0;}


    printf("You entered the number ");

        //Checks if theres a value on the hundreths digit
        switch(inputVal/100){
            case 1: printf("one hundred ");break; 
            case 2: printf("two hundred ");break;
            case 3: printf("three hundred ");break;
            case 4: printf("four hundred ");break;
            case 5: printf("five hundred ");break;
            case 6: printf("six hundred ");break;
            case 7: printf("seven hundred ");break;
            case 8: printf("eight hundred ");break;
            case 9: printf("nine hundred ");break;
        }
        
        //Checks if there is a value on the tens digit
        //Has special cases on 11-19 that will make the checker for ones digits not work if cases is 11-19
        //Ones check will still work if it is not 11-19 
        switch (inputVal % 100){
            case 11: printf("eleven");ifBool =0; break; 
            case 12: printf("twelve");ifBool =0; break;
            case 13: printf("thirteen");ifBool =0; break;
            case 14: printf("fourteen");ifBool =0; break;
            case 15: printf("fifteen");ifBool =0; break;
            case 16: printf("sixteen");ifBool =0; break;
            case 17: printf("seventeen");ifBool =0; break;
            case 18: printf("eighteen");ifBool =0; break;
            case 19: printf("nineteen");ifBool =0; break;

            default:switch(((inputVal)%100)/10){
                    case 1: printf("ten ");break;
                    case 2: printf("twenty ");break;
                    case 3: printf("thirty ");break;
                    case 4: printf("forty ");break;
                    case 5: printf("fifty ");break;
                    case 6: printf("sixty ");break;
                    case 7: printf("seventy ");break;
                    case 8: printf("eighty ");break;
                    case 9: printf("ninety ");break;
            }
        }

        //if there is no numbers from 11-19, this statement will be true
        //Checks if theres a number at ones digit
        if (ifBool == 1){
                switch (inputVal%10){
                case 1: printf("one"); break; 
                case 2: printf("two"); break;
                case 3: printf("three"); break;
                case 4: printf("four"); break;
                case 5: printf("five"); break;
                case 6: printf("six"); break;
                case 7: printf("seven"); break;
                case 8: printf("eight"); break;
                case 9: printf("nine"); break;
            }
        }
    //print new line
    printf("\n");
    }   
}
