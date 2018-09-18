#include <stdio.h>

int squareInt(int num){
    return num * num;
}

int q1_a(void){
    int total = 0;
    for (int num = 30; num <= 1000; num + 4){
        total += num;

    }

    return total;
}

int q1_b(void){
    int total = 0, num = 30;

    while(num <= 1000){
        total += num;
        num += 4;
    }

    return total;
}

int q1_c(void){
    int total = 0, num = 30;

    do{
        total += num;
        num += 4;
    } while(num <= 1000);

    return total;
}

// Question 2
void q2(void){
    int num;

    do{
        printf("Please input a positive number: ");
        scanf("%i", &num);
    }while(num < 0);

    printf("Thank you");

}

int q3(void){
    int n, min, inp;

    do{
        printf("Please input the amount of digits you'd like to enter: ");
        scanf("%i", &n);
    } while(!(n > 0));

    for (int i = 0; i < n; i++){
        printf("Enter digit: ");
        scanf("%i", &inp);

        if(min == NULL || inp < min){
            min = inp;
        }
    }

    return min;
}

void q4(void){
    int inp;

    do{
        printf("Please input integer: ");
        scanf("%i", &inp);

        if (inp - 10000 >= 0 && inp - 100000 < 0){
            printf("%i\n", inp);
        }
    } while(inp != 0);
}


void q5(void){ //FIX ME!!!
    float avg;

    printf("Please input student average: ");
    scanf("%f", &avg);

    if (avg > 100.0){
        do{
            printf("Invalid input. Please input student average: ");
            scanf("%f", &avg);
        }while(avg > 100.0);
    }


    switch((int)avg){

        case 90 ... 100 :
            printf("%d\n", 4);
            break;

        case 80 ... 89 :
            printf("%d\n", 3);
            break;

        case 70 ... 79 :
            printf("%d\n", 2);
            break;

        case 60 ... 69 :
            printf("%d\n", 1);
            break;

        default :
            printf("%d\n", 0);
    }
}


void q6(void){
    int n; //Number of terms
    float pi = 0.0, sign = 1.0, denom = 1.0; //Will contain computed result

    //Prompting user for n
    printf("Please enter the number of terms you desire to use: ");
    scanf("%d", &n);

    //Computing pi
    for (int i = 0; i < n; i++, denom + 2){
        //printf("Pi: %f \t denom: %f \t sign: %f \n", pi, denom, sign);
        pi += sign * 4 / denom;

        denom += 2;
        sign *= -1.0;
    }

    printf("Pi: %f \n", pi);
}

void q7(void){ // FIX ME!!
    int side1, side2, hypotenuse;

    for (hypotenuse = 1; hypotenuse <= 400; hypotenuse++){

        for (side1 = 1; side1 < hypotenuse; side1++){

            for (side2 = 1; side2 <= side1; side2++){

                if (squareInt(side1) + squareInt(side2) == squareInt(hypotenuse))
                    printf("side 1: %d \t side 2: %d \t hypotenuse: %d \n", side1, side2, hypotenuse);
            }
        }
    }

}

void q8(void){
    int m; //Declaring necessary value

    //Prompting user
    printf("Input integer: ");
    scanf("%d", &m);

    printf("Perfect numbers: ");

    //Finding perfect numbers
    for (int i = 1; i <= m; i++){
        for (int n = 1, sum = 0; n < i; n++){

            if (i % n == 0){
                sum += n;
            }

            if (n == i - 1 && sum == i)
                printf("%d, ", n);

        }

    }

    printf("\n");

}

long q13_a(void){ //FIX ME!!
    long n, prod = 1;

    printf("Enter integer: ");
    scanf("%ld", &n);

    if (n > 0){
        while(n > 0){
            prod *= n--;
        }
    }

    else if (n < 0){
        q13_a();
    }

    return prod;
}






// executions

int main(void){
    q8();
    return 0;
}