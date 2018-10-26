#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//student structure
typedef struct{

    int studentID;
    char firstName[15];
    char lastName[15];
    int project1Grade;
    int project2Grade;
    double finalGrade;
} student;

//Function prototypes
student **create_class_list(char *filename, int *sizePtr);
int find(int idNo, student **list, int size);
void input_grade(char *filename, student **list, int size);
void compute_final_course_grades(student **list, int size);
void print_list(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);

int main(void){
    int class_A_size, i;
    student **class_A = create_class_list("studentListNew.txt", &class_A_size);

    //Testing of create_class_list
    printf("*sizePtr: %d\n", class_A_size);
    for(i = 0; i < class_A_size; class_A++, i++)
        printf("%d %s %s\n", (*class_A) -> studentID,(*class_A) -> firstName, (*class_A) -> lastName);


    //testing of find
    class_A = class_A - i;
    printf("\nfind tests\n");
    printf("%d\n", find(1200, class_A, class_A_size));
    printf("%d\n", find(4580, class_A, class_A_size));
    printf("%d\n", find(9000, class_A, class_A_size));
    printf("%d\n", find(1111, class_A, class_A_size));

    //testing input_grade
    input_grade("grades.txt", class_A, class_A_size);
    printf("\ngrade_input tests\n");
    for(i = 0; i < class_A_size; class_A++, i++)
        printf("%d %d\n", (*class_A) -> project1Grade,(*class_A) -> project2Grade);


    //testing for compute_final_course_grades
    class_A = class_A - i;
    compute_final_course_grades(class_A, class_A_size);

    //testing for print_list
    printf("\nprinting list\n");
    print_list(class_A, class_A_size);

    //testing withdraw
    withdraw(1200, class_A, class_A_size);
    print_list(class_A, class_A_size);

    return 0;
}

student **create_class_list(char *filename, int *sizePtr){
    FILE *input_file = fopen(filename, "r");
    student **class_list = NULL;

    if(input_file != NULL){
        fscanf(input_file, "%d", sizePtr);

        class_list = calloc(*sizePtr, sizeof(student *));

        for(int i = 0; i < *sizePtr; i++){
            *(class_list + i) = malloc(sizeof(student));
            fscanf(input_file, "%d %s %s", &((*(class_list + i)) -> studentID), &((*(class_list + i)) -> firstName), &((*(class_list + i)) -> lastName));

        }

    }

    else printf("NULL\n");

    fclose(input_file);
    return class_list;
}

int find(int idNo, student **list, int size){
    int i;

    for(i = 0; i < size; i++){
        if((*(list + i)) -> studentID == idNo)
            return i;
    }

    return -1;
}

void input_grade(char *filename, student **list, int size){
     int currID;
     double wasteData;

     FILE* input_file = fopen(filename, "r");

     if(input_file == NULL) printf("NULL\n");

     else{
        for(int i = 0; i < size; i++){
            fscanf(input_file, "%d", &currID);
            //printf("currID: %d, indexNum: %d\n", currID, find(currID, list, size));

            if(find(currID, list, size) != -1){
                fscanf(input_file, "%d %d",
                       &(list[find(currID, list, size)] -> project1Grade),
                       &(list[find(currID, list, size)] -> project2Grade));
                //printf("%d\n", (*(list + find(currID, list, size))) -> project1Grade);
            }

            else{
                fscanf(input_file, "%d", &wasteData);
                fscanf(input_file, "%d", &wasteData);
                i--;
            }
        }
     }

     fclose(input_file);
}

void compute_final_course_grades(student **list, int size){

    for(int i = 0; i < size; i++){
        (*(list + i)) -> finalGrade = ((*(list + i)) -> project1Grade + (*(list + i)) -> project2Grade) / 2;
    }
}

void print_list(student **list, int size){

    for(int i = 0; i < size; i++)
        printf("%d %s %s %d %d %f\n",
               (*(list + i)) -> studentID,
               (*(list + i)) -> firstName,
               (*(list + i)) -> lastName,
               (*(list + i)) -> project1Grade,
               (*(list + i)) -> project2Grade,
               (*(list + i)) -> finalGrade
               );
}

void withdraw(int idNo, student **list, int *sizePtr){
    int counter;
    //printf("index: %d, size: %d\n", find(idNo, list, *sizePtr), *sizePtr);
    for(int counter = 0; counter < *sizePtr; counter++){

        if(list[counter] -> studentID == idNo){
            for(counter += 1; counter < *sizePtr; counter++){
                *(list[counter - 1]) = *(list[counter]);
            }
            break;
        }

    }

    free(list[--*sizePtr]);
}
