#include <stdio.h>

#define N 3

//Testing elements
int mat1[2][2] = {3,4,-1,2}; //Matrix dominant
int mat2[4][5] = {10,9,8,9,20,1,2,3,4,5,5,4,3,2,1,4,3,5,2,7,-1,-1,-3,-4,-5}; //Matrix dominant
int mat3[5][3] = {3,4,6,5,6,7,0,0,0,2,4,6,29,3,6}; //not dominant
int mat4[4][4] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}; //not dominant

int is_dominant(int mat[][N], int n);

int main(void){

    //Testcases
    printf("Testcase: %s", (is_dominant(mat3, 5) == 0) ? "Successful" : "Failed");

    return 0;
}

int is_dominant(int mat[][N], int n){

    for(int colNum = 0; colNum < N; colNum++){ //Outerloop iterates through columns
        for(int rowNum = 1; rowNum < n; rowNum++){ //Inner loop iterates through rows

            if(mat[0][colNum] <= mat[rowNum][colNum]) //In the event top element of column is not strictly larger than a lower element, return 0 and break function
                return 0;
        }
    }

    return 1; //return 1 is matrix is dominant
}
