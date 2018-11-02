#include <stdio.h>


void double_copy(const int x[], int y[], int n);

int main(void){

    //Testing elements
    int x1[4] = {1,2,3,4};
    int x2[7] = {-3,5,7,2,6,1,7};

    int y1[8];
    int y2[14];

    //Main will be used for testing functions
    double_copy(x1,y1,4);
    double_copy(x2,y2,7);

    printf("Test case 1: \n");
    for(int g = 0; g < 8; g++)
        printf("%d, ", y1[g]);


    printf("\nTest case 2: \n");
    for(int i = 0; i < 14; i++)
        printf("%d, ", y2[i]);

    return 0;
}

void double_copy(const int x[], int y[], int n){

    for(int indexNum = 0; indexNum < 2*n; indexNum++){
        y[2*indexNum] = x[indexNum]; //copy the element of x at indexNum into element of y at twice that of index
        y[2*indexNum + 1] = x[indexNum]; // copy the element of x at indexNum into the next element of y
    }

}

/*
TESTCASES

Testcase 1
Input: {1,2,3,4}
Expected output: {1,1,2,2,3,3,4,4}
Result: Successful

Testcase 2
Input: {-3,5,7,2,6,1,7}
Expected output: {-3,-3,5,5,7,7,2,2,6,6,1,1,7,7}
Result: Successful
*/