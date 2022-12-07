/*

        Converter program
            >Converts values in 8 different ways
                >can convert to and from different English and Metric measuring systems
            >made using switch statements, and while loops

        Dhylan Usi
        251246124
        CS2211A

*/


#include <stdio.h>

void main(){

    //intialize variables
    
    //variable for choosing 
    int convertVar;
    char inputChar;
    int intputVal;
    int loopBool = 1;


    while(loopBool == 1){
        //Asks for an input
        printf("Choose the kind of conversion from 1 to 4 \n 1 Kilogram <=> Pounds conversion\n 2 Hectares <=> Acres conversion\n 3 Litres <=> Gallons conversion\n 4 Kilometeres <=> Miles conversion\n 5 to quit:");
        scanf(" %d", &convertVar);

        //Case statement for each options of convertion
        switch (convertVar){
                    //Asks for indepth option regarding converstion
            case 1: printf("Choose K (Kilogram => Pounds) or P (Pounds => Kilogram): ");
                    scanf(" %c",&inputChar);
                    switch(inputChar){
                        case 'K': printf("You have chosen Kilogram => Pounds conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f Pounds\n", intputVal*2.20462);
                                  break;  
                        case 'P': printf("You have chosen Pounds => Kilogram conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f\n Kilograms", intputVal/2.20462);
                                  break;  
                    }
                    break;
                    //Asks for indepth option regarding converstion            
            case 2: printf("Choose H (Hectares => Acres) or A (Acres => Hectares): ");
                    scanf(" %c",&inputChar);
                    switch(inputChar){
                                  //Will ask for an input and it will be printed as a value already converted
                        case 'H': printf("You have chosen Hectares => Acres conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f Acres\n", intputVal*2.47105);
                                  break;  
                                  //Will ask for an input and it will be printed as a value already converted
                        case 'A': printf("You have chosen Acres => Hectares conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f Hectares\n", intputVal/2.47105);
                                  break;  

                    }
                    break;     
                    //Asks for indepth option regarding converstion
            case 3: printf("Choose L (Litres => Gallons) or G (Gallons => Litres): ");
                    scanf(" %c",&inputChar);

                    switch (inputChar){
                                  //Will ask for an input and it will be printed as a value already converted
                        case 'L': printf("You have chosen Litres => Gallons conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f Gallons\n", intputVal*0.264172);
                                  break; 
                                  //Will ask for an input and it will be printed as a value already converted 
                        case 'G': printf("You have chosen Gallons => Litres conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f Litres\n", intputVal/0.264172);
                                  break;  
                    }  
                    break;   
                    //Asks for indepth option regarding converstion
            case 4: printf("Choose K (Kilometeres => Miles) or M (Miles => Kilometeres): ");
                    scanf(" %c",&inputChar);
                    switch(inputChar){
                                  //Will ask for an input and it will be printed as a value already converted
                        case 'K': printf("You have chosen Kilometeres => Miles conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f Miles\n", intputVal*0.621371);
                                  break;  
                                  //Will ask for an input and it will be printed as a value already converted
                        case 'M': printf("You have chosen Miles => Kilometeres conversion \nPlease enter a value: ");
                                  scanf("%d",&intputVal);
                                  printf("Your conversion is: %f Kilometeres\n", intputVal/0.621371);
                                  break;  

                    }
                    break;  
                    //Stops the whole program
            case 5: loopBool = 0; break;
        }
    }
}