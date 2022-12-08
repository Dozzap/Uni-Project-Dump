/*

    Array and functions program
        > 6 functions that manipulate/iterate the array.

        Dhylan Usi
        251246124
        CS2211A
*/

#include <stdio.h>

//Iterate and display the value and the index of the array
void displayArray(int intArr[],int sizeArr){
    printf("Your array is: ");
    for (int i = 0; i < sizeArr ; i++){
        printf("[%d] = %d,", i,intArr[i]);
    }
    printf("[%d] = %d", sizeArr-1, intArr[sizeArr-1]);
    printf("\n");
}
//Iterate and look for the largest value in the array and prints  it
void maxValArray(int intArr[],int sizeArr){
    int intMax = intArr[0];
    printf("Your largest value in your array is: ");
    for (int i = 0; i < sizeArr; i++){
        if (intArr[i] > intMax){
            intMax = intArr[i];
        }
    }
    printf("%d", intMax);
    printf("\n");
}
//Iterate and display the array's values in a reverse way
void reverseArray(int intArr[],int sizeArr){
    printf("Your array in reverse is: ");
        for(int i = sizeArr-1; i >-1; i--){
            printf("%d ", intArr[i]);
        }
    printf("\n");
}
//Iterate and adds each value of the array and prints out the sum
void sumArray(int intArr[],int sizeArr){
    int intSum = 0;
    printf("The sum of all values in your array is: ");
    for (int i = 0; i < sizeArr ; i++){
        intSum+= intArr[i];
    }
    printf("%d", intSum);
    printf("\n");
}
//Iterate and duplicate the input array to another array
//Performs selection sort from largest to smallest value
//Prints the sorted array
void sortArray(int intArr[],int sizeArr){
    int temp;
    int sortedArr[sizeArr];
    for (int i = 0; i < sizeArr; i++){
        sortedArr[i] = intArr[i];
    }

    for (int i = 0; i <sizeArr; i++){
        for (int j = i+1; j <sizeArr; j++){
            if (sortedArr[i] < sortedArr[j]){
                temp = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = temp;
            }
        }
    }
    printf("Your array in sorted order is: ");
        for (int i = 0; i < sizeArr; i++){
            printf("%d ", sortedArr[i]);
        }
    printf("\n");            
}
//Iterate and display the array with only the first and last values swapped
void firstLastSwapArray(int intArr[],int sizeArr){
    int temp1 = intArr[0];
    int temp2 = intArr[sizeArr-1];

    printf("Your array with first and last element switched is: %d ", temp2);
    for (int i = 1; i <sizeArr-1 ; i++){
        printf("%d ", intArr[i]);
    }

    printf("%d", temp1);
    printf("\n");
}


int main(){
    //Initialize variables
    int sizeArr = 0;

    //User is prompted until the input is larger than 5 but less than 12
    while(!(sizeArr >= 5 && sizeArr <=12)){ 
        printf("Please enter the number of integers to process: ");
    scanf("%d", &sizeArr);
    }
    //Intialize the array
    int intArr[sizeArr];

    
    printf("There is enough room in your array of %d integers (%ld bytes)\n", sizeArr, sizeof(intArr));

    printf("Please enter your integers separated by spaces:" );

    //Iterate through the input and fills in the array with values
    for (int i = 0; i <sizeArr; i++) {scanf("%d", &intArr[i]);}

    //Calling the functions
    displayArray(intArr,sizeArr);
    maxValArray(intArr,sizeArr);
    reverseArray(intArr,sizeArr);
    sumArray(intArr,sizeArr);
    sortArray(intArr,sizeArr);
    firstLastSwapArray(intArr,sizeArr);
    
    

}
