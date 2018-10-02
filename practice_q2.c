#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Constants
#define N 4

#define ascii_A 65
#define ascii_Z 90
#define ascii_a 97
#define ascii_z 122

//Necessary elements
int freq[26];

//Initialization of test elements

    //Matrices
int intMtrx1[4][4] = {5,2,2,3,6,8,1,2,2,3,88,29,2,5,99,103};
int intMtrx2[3][3] = {1,34,5,2,5,3,3,6,8};
int intMtrx3[4][5] = {9,2,1,0,4,7,9,2,1,0,3,7,9,2,1,5,3,7,9,2};
int intMtrx4[4][4] = {9,1,2,3,1,8,2,3,1,2,10,3,1,2,3,11};
int intMtrx5[4][4] = {9,1,2,3,1,2,2,3,1,2,10,3,1,2,3,11};
int intMtrx6[4][4] = {9,-1,-2,-3,1,8,2,3,1,2,10,3,1,2,3,-11};

    //Integer arrays
int intArray1[8] = {1,5,8,11,65,99,130,934};
int intArray2[5] = {4,2,6,7,6};
int intArray3[3] = {2,2,2};
int intArray4[8] = {0,-1,2,0,7,6,-8,0};

    //Double arrays
double lfArray[]; //empty double array

double lfArray1[4] = {3.4,5.7,3.5,0.3};
double lfArray2[4] = {8.33, 9.24, 1.11, 49.878};

double lfArray3[8] = {4.2,6.7,3.2,9.2,993.554,43.44,9.3,2.22};

    //Strings
char str1[];
char str2[5];
char str3[2];
char str4[10];


//Function prototypes

    //Question 1
void print_vector(double array[], int size);
void add_vectors(double vector1[], double vector2[], double vector3[], int n);
double scalar_prod(double vector1[], double vector2[], int n);

    //Question 2
void isSorted(int array[], int size);

    //Question 3
void int_freq(int array[], int num, int size);

    //Question 4
void change(int x[], int n);

    //Question 5
int is_diag_dom( int mat[ ][N]);

    //Question 6
void print_diag_scan(int mat[ ][N]);

    //Question 7
int is_toeplitz(int a[][N], int m);

    //Question 8
void letter_freq(const char word[], int freq[]);

    //Question 9
void string_copy(const char source[], char destination[], int n);

    //Question 10
void my_strcat(const char str1[], const char str2[], char str3[], int n);

    //Question 11
int my_strcomp(const char str1[], const char str2[]);


//MAIN (for testing functions)____________________________________________________________________________________
int main(void){
    printf("%d \n", my_strcomp("vijay", "shreyal"));

    return 0;
}

//________________________________________________________________________________________________________________




//QUESTION Answers

    //Question 1

void print_vector(double array[], int size){

    //For loop prints vector entries from first from second last
    for (int indexNum = 0; indexNum < size - 1; indexNum++){
        printf("%lf, ", array[indexNum]);
    }

    printf("%lf \n", array[size - 1]); //statement prints vector's last entry without comma

}

void add_vectors(double vector1[], double vector2[], double vector3[], int n){

    //Array entries are summed in every iteration and stored in vector3
    for(int indexNum = 0; indexNum < n; indexNum++){
        vector3[indexNum] = vector1[indexNum] + vector2[indexNum];
    }

    print_vector(vector3, n);
}

double scalar_prod(double vector1[], double vector2[], int n){
    double rslt = 0; //stores scalar product

    //Every iteration adds the product of appropriate vector entries to rslt
    for(int indexNum = 0; indexNum < n; indexNum++){
        rslt += (vector1[indexNum] * vector2[indexNum]);
    }

    return rslt;
}

    //Question2

void isSorted(int array[], int size){
    int indexNum; //Counter for for loop

    //Processing: Every iteration compares current element to previous element
    for(indexNum = 1; indexNum < size; indexNum++){

        //Conditional makes comparison
        if(array[indexNum] < array[indexNum - 1]){
            //If condition is true, loop breaks
            break;
        }
    }

    //Conditionals determine what to print
    if(indexNum == size){
        printf("Array is sorted \n");
    }

    else{
        printf("Array is not sorted \n");
    }
}

    //Question 3
void int_freq(int array[], int num, int size){
    int occCounter = 0; //occurance counter

    //Processing
    for(int indexNum = 0; indexNum < size; indexNum++){

        //occCounter is incremented every time array element and num match
        if(array[indexNum] == num){
            occCounter++;
        }
    }

    printf("%d occurs %d times within array \n", num, occCounter);
}

    //Question 4
void change(int x[], int n){
    int zeroCounter = 0; //counts how many zeros are in array in realtime

    //Processing
    for(int indexNum = 0; indexNum < n; indexNum++){

        //Increment zeroCounter when encountering a zero
        if(x[indexNum] == 0){
            zeroCounter++;
        }

        else if(x[indexNum] != 0 && indexNum != 0){
            x[indexNum - zeroCounter] = x[indexNum]; //If entry is non zero, move value zeroCounter places back
            x[indexNum] = 0;
        }
    }

    //Array printing process (similar to print_vector)
    for (int indexNum = 0; indexNum < n - 1; indexNum++){
        printf("%d, ", x[indexNum]);
    }

    printf("%d \n", x[n - 1]); //statement prints vector's last entry without comma

}

    //Question 5
int is_diag_dom( int mat[ ][N]){
    int sum;

    for(int rowNum = 0, sum = 0; rowNum < N; rowNum++, sum = 0){

        for(int colNum = 0; colNum < N; colNum++){

            if(rowNum != colNum){
                sum += mat[rowNum][colNum];
            }
        }

        if(fabs(sum) > fabs(mat[rowNum][rowNum])){
            return 0;
        }
    }

    return 1;
}

    //Question 6
void print_diag_scan(int mat[ ][N]){
    int iterMax = 2*N - 1; //Number of outer iterations,

    //Printing top diagonal half and diagonal
    for(int i = 0, rowNum = 0; i < N; i++, rowNum = i){

        for(int colNum = 0; rowNum >= 0; rowNum--, colNum++){
            printf("%d ", mat[rowNum][colNum]);
        }
    }

    //Printing bottom diagonal half
    for(int i = N, colNum = 1; i < iterMax; i++, colNum = i - N + 1){

        for(int rowNum = N - 1; colNum < N; colNum++, rowNum--){
            printf("%d ", mat[rowNum][colNum]);
        }

    }
}

    //Question 7
int is_toeplitz(int a[][N], int m){

    for(int rowNum = 0; rowNum < m - 1; rowNum++){

        for(int colNum = 0; colNum < N - 1; colNum++){
            if(a[rowNum][colNum] != a[rowNum + 1][colNum + 1]){ //if element to bottom right does not match
                return 0; //return 0 and break whole function if mtrx is not toeplitz
            }
        }
    }

    return 1; //return 1 if mtrx is toeplitz
}

    //Question 8
void letter_freq(const char word[], int freq[]){

    for(int charNum = 0; word[charNum] != '\0'; charNum++){

        printf("%c", word[charNum]);
        if((word[charNum] > ascii_A && word[charNum] < ascii_Z) || (word[charNum] > ascii_a && word[charNum] < ascii_z)){
            (freq[word[charNum] > ascii_A && word[charNum] < ascii_Z != 0 ? word[charNum] - 65 : word[charNum] - 97])++;
        }
    }

    for(int alphaNum = 0; alphaNum < 26; alphaNum++){
        printf("The count of '%c' and '%c' is %d \n", alphaNum + 65, alphaNum + 97, freq[alphaNum]);
    }

}

    //Question 9

/*For this function, we're assuming that the person using it inputs the correct n */
void string_copy(const char source[], char destination[], int n){

    for(int indexNum = 0; indexNum < n; indexNum++){
        destination[indexNum] = source[indexNum];
    }

}

    //Question 10

/*For this function, we're assuming that the person using it inputs the correct n */
void my_strcat(const char str1[], const char str2[], char str3[], int n){ //FIX ME!!
    int i = 0, j = 0;

    while(str1[i] != '\0' && i + j < n){
        str3[i] = str1[i];
        i++;
    }

    while(str2[j] != '\0' && i + j < n){
        str3[i+j] = str2[j];
        j++;
    }

    if(i + j > n){
        printf("Error: not enough memory is being allocated for concatenated string.\n");
        i = 0;

        while(str3[i] != '\0'){
            str3[i] = ' ';
            i++;
        }
    }

}

    //Question 11
int my_strcomp(const char str1[], const char str2[]){ //INCOMPLETE
    int indexNum = 0;

    for(indexNum = 0; str1[indexNum] != '0'; indexNum++){
        if((str1[indexNum] > ascii_A && str1[indexNum] < ascii_Z != 0 ? str1[indexNum] - 65 : str1[indexNum] - 97) < (str2[indexNum] > ascii_A && str2[charNum] < ascii_Z != 0 ? str2[charNum] - 65 : str2[charNum] - 97))
            return -1;

        else if((str1[charNum] > ascii_A && str1[charNum] < ascii_Z != 0 ? str1[charNum] - 65 : str1[charNum] - 97) > (str2[charNum] > ascii_A && str2[charNum] < ascii_Z != 0 ? str2[charNum] - 65 : str2[charNum] - 97))
            return 1;
    }

    return 0;

}
