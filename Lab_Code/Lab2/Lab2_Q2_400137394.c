#include <stdio.h>

int count(char s[], char a);

//Testing elements
char s1[]= "ayaaaa";
char s2[] = "g-unit gang gang";

int main(void){
     //Testing count

     printf("Testcase 1 \nInput: %s, Expected output: %d \nTest: %s \n", s1, 5, count(s1,'a') == 5 ? "Succesful\n" : "Failed\n"); //Testcase 1
     printf("\nTestcase 2 \nInput: %s, Expected output: %d \nTest: %s \n", s1, 1, count(s1,'y') == 1 ? "Succesful\n" : "Failed\n"); //Testcase 2
     printf("\nTestcase 3 \nInput: %s, Expected output: %d \nTest: %s \n", s2, 2, count(s2,'a') == 2 ? "Succesful\n" : "Failed\n"); //Testcase 3
     printf("\nTestcase 4 \nInput: %s, Expected output: %d \nTest: %s \n", s2, 5, count(s2,'g') == 5 ? "Succesful\n" : "Failed\n"); //Testcase 4

    return 0;
}

int count(char s[], char a){
    int counter = 0; //holds the amount of occurences of a

    for(int indexNum = 0; s[indexNum] != '\0'; indexNum++){
        counter = s[indexNum] == a ? counter + 1 : counter; //increments counter IFF element of s at indexNum is equal to a
    }

    return counter;
}

/*
TESTCASES

Testcase 1
Input: "ayaaaa", 'a'
Expected output: 5
Result: Successful

Testcase 2
Input: "ayaaaa", 'y'
Expected output: 1
Result: Successful

Testcase 3
Input: "g-unit gang gang", 'a'
Expected output: 2
Result: Successful

Testcase 4
Input: "g-unit gang gang", 'g'
Expected output: 5
Result: Successful
*/