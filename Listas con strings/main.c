#include "list.h"

int main(){
    list *A = create_list();

    printf("\nIntroduce the students do you want in the class 'A' named '%s': ", A->name), scanf("%d", &A->size);
    getchar();

    for(int i = 0; i < A->size; i++){
        introduce_students(A, create_node());
    }

    printf("\n");
    show_list(A);

    list *B = create_list();
    printf("\nIntroduce the students do you want in the class 'B' named '%s': ", B->name), scanf("%d", &B->size);
    getchar();

    for(int i = 0; i < B->size; i++){
        introduce_students(B, create_node());
    }

    printf("\n");
    show_list(B);

    list *C = create_list();
    printf("\nIntoduce the students do you want in the class 'C' named '%s': ", C->name), scanf("%d", &C->size);
    getchar();

    for(int i = 0; i < C->size; i++){
        introduce_students(C, create_node());
    }

    printf("\n");
    show_list(C);

    int op, op2, op3;
    do{
        printf("\n- - - -- --  - - - --  MAIN MENU - - - - - -- - -- - -\n");
        printf("(0) Exit the program.\n");
        printf("(1) Introduce a new student.\n");
        printf("(2) Eliminate a student.\n");
        printf("(3) Search a student.\n");
        printf("(4) Show lists.\n");
        printf("Select an option: "), scanf("%d", &op);
        getchar();

        switch(op){
            case 0:
            break;

            case 1:
            printf("\n\n(0) Cancel the selection.\n");
            printf("(1) Introduce in the list A.\n");
            printf("(2) Introduce in the list B.\n");
            printf("(3) Introduce in the list C.\n");
            printf("Select the class to introduce the student in it: "), scanf("%d", &op2);
            getchar();

            switch(op2){
                case 0:
                printf("\nCancelling the process...\n");

                break;

                case 1:
                introduce_students(A, create_node());
                printf("\nStudent succesfully created!");
                break;

                case 2:
                introduce_students(B, create_node());
                printf("\nStudent succesfully created!");
                break;

                case 3:
                introduce_students(C, create_node());
                printf("\nStudent succesfully created!");
                break;

                default:
                printf("\nERROR: not valid option...\n");
            }
            printf("\nReturning to the main menu...\n");
            break;

            case 2:
            printf("\n\n(0) Cancel the selection.\n");
            printf("(1) Eliminate a student in the list A.\n");
            printf("(2) Eliminate a student in the list B.\n");
            printf("(3) Eliminate a student in the list C.\n");
            printf("Select the class to eliminate the student in it: "), scanf("%d", &op2);
            getchar();

            switch(op2){
                case 0:
                printf("\nCancelling the process...\n");

                break;

                case 1:
                eliminate_student(A);
                break;

                case 2:
                eliminate_student(B);
                break;

                case 3:
                eliminate_student(C);
                break;

                default:
                printf("\nERROR: not valid option...\n");
            }
            printf("\nReturning to the main menu...\n");
            break;

            case 3:
            search_student(A, B, C);
            break;

            case 4:
            do{
                printf("\n\n(0) Cancel the selection.\n");
                printf("(1) Show the class A.\n");
                printf("(2) Show the class B.\n");
                printf("(3) Show the class C.\n");
                printf("(4) Showw all the lists.\n");

                switch(op2){
                    case 0:
                    printf("\nCancelling the process...\n");
                    break;

                    case 1:
                    show_list(A);
                    break;

                    case 2:
                    show_list(B);
                    break;

                    case 3:
                    show_list(C);
                    break;

                    case 4:
                    printf("\nClass A: \n");
                    show_list(A);
                    printf("\nClass B: \n");
                    show_list(B);
                    printf("\nClass C: \n");
                    show_list(C);
                    break;

                    default:
                    printf("\nERROR: not valid option...\n");
                }
            }while(op2 != 0);
            break;

            default:
            printf("\nERROR: not valid option...\n\n");
        }
    }while(op != 0);

    printf("\nFinishing the program...\n");

    return 0;
}