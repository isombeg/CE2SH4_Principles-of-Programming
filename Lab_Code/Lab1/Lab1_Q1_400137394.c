
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num = 5; //variable that will be squared

    //Loop where squaring will take place until perfect squares exceed 3000
    while(num * num < 3000){
        printf("%d\n", num * num);
        num++; //Increment num by one to move on to next perf square
    }

    return 0;
}
