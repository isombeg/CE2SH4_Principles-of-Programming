#include <stdio.h>
#include <stdlib.h>

int main(void){
    int binNum, addOn, decNum = 0, counter = -1; // binNum stores user input

    //Prompting user
    printf("Please input a positive binary integer: ");
    scanf("%d", &binNum);

    //Processing and making decimal number
    while(binNum != 0){
        addOn = 1; //quantity that will be added to binNum
        counter++; //represents the exponent to the 2

        //if applicable digit is 1:
        if(binNum % 2 == 1){

            //exponentiation
            for (int powerNum = 0; powerNum < counter; powerNum++)
                addOn *= 2;
        }

        //if applicable digit is 0:
        else
            addOn = 0;

        decNum += addOn;
        //printf("addOn: %d, decNum: %d\n", addOn, decNum);
        binNum = binNum / 10;
    }

    printf("decimal equivalent: %d\n", decNum);

    return 0;
}
