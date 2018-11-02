#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num, colLen, spaceNum = 0; //variable which stores user input, var stores corresponding column length

    //Loop prompts user
    do{
        printf("Please input an odd integer betweem 5 and 31: ");
        scanf("%d", &num);
    }while((num % 2) != 1 || !(num >= 5 && num <= 31)); //Conditions for input to be accepted

    colLen = 2 * num - 1;

    //Printing process
    for (int row = 0; row < num; row++){ //Outer loop takes care of printing rows

        for(int col = 0; col < colLen; col++){
            if(col >= spaceNum && col <= colLen - spaceNum - 1)
                printf("*");

            else
                printf(" ");
        }

        printf("\n");
        spaceNum++;
    }

    return 0;
}
