#include <stdio.h>
#include <stdlib.h>

int main(void){
    int termQty, signDig = 1; //termQty is for user input
    double rsltNum = 0.0, denom = 1.0; //rsltNum is the final number that will be printed

    //Prompting user
    printf("Please input amount of terms you wish to use: ");
    scanf("%d", &termQty);

    //printf("denom: %f, rsltNum: %f \n", denom, rsltNum);

    for (int term = 1; term <= termQty; term++){
        denom *= 2; //denominator in the term
        signDig =  3.0 / denom < 0.75 ? signDig * -1 : signDig; //determines whether added term is positive or negative

        rsltNum += signDig * (3.0/denom); //adding term to resultant number
        //printf("denom: %f, rsltNum: %f \n", denom, rsltNum);
    }

    printf("%f", rsltNum);

}
