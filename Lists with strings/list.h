#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct list{
    int size;
    node *first;
    node *last;
    char *name;

}list;

list *create_list(){
    list *Class = (list*)malloc(sizeof(list));

    Class->size = 0;
    Class->first = NULL;
    Class->last  = NULL;
    Class->name = (char*)malloc(sizeof(char));

    printf("\nIntroduce the name of the class: "), fgets(Class->name, N, stdin);
    Class->name[strcspn(Class->name, "\n")] = 0;

    return Class;
}

void introduce_students(list *Class, node *student){
    if(Class->first == NULL){
        Class->first = student;
        Class->last = student;
    }
    else{
        Class->last->link = student;
        Class->last = student;
    }
    printf("\nStudent '%s %s' has joined in the list '%s'!", student->name, student->surname, Class->name);
}

void eliminate_student(list *Class){
    char *name = (char*)malloc(sizeof(char));
    int aux_num = 0;

    printf("\nIntroduce the name of the student to remove it: "), fgets(name, N, stdin);
    name[strcspn(name, "\n")] = 0;

    node *aux = Class->first;
    node *prev = aux;
    
    for(int i = 0; i < Class->size && aux_num == 0; i++){
        if(strcmp(aux->name, name) == 0){
            node *post = aux->link;
            prev->link = post;
            free(aux);
            aux_num = 1;
            break;
        }
        prev = aux;
        aux = aux->link;
    }

    if(aux_num == 0){
        printf("\nERROR: Student not found in the data base...\n");

    }
    else{
        printf("\nStudent succesfully eliminated!");
    }
}

void search_student(list *A, list *B, list *C){

    char *name = (char*)malloc(sizeof(char));
    int aux_num = 0;
    printf("\nIntroduce the name of the student to search it: "), fgets(name, N, stdin);
    name[strcspn(name, "\n")] = 0;

    node *aux = A->first;
    for(int i = 0; i < A->size && aux_num == 0; i++){
        if(strcmp(aux->name, name) == 0){
            printf("\nStudent '%s %s' founded in class A '%s'.", aux->name, aux->surname, A->name);
            aux_num = 1;
            break;
        }
        aux = aux->link;
    }

    if(aux_num == 0){
        aux = B->first;

        for(int i = 0; i < B->size && aux_num == 0; i++){
            if(strcmp(aux->name, name) == 0){
                printf("\nStudent '%s %s' founded in class B '%s'.", aux->name, aux->surname, B->name);
                aux_num = 1;
                break;
            }
            aux = aux->link;
        }

        if(aux_num == 0){
            
            aux = C->first;

            for(int i = 0; i < C->size && aux_num == 0; i++){
                if(strcmp(aux->name, name) == 0){
                    printf("\nStudent '%s %s' founded in class B '%s'.", aux->name, aux->surname, C->name);
                    aux_num = 1;
                    break;
                }
                aux = aux->link;
            }

            if(aux_num == 0){
                printf("\nERROR: Student not found in the data base...\n");
            }
        }
    }
}

void show_list(list *Class){
    node *aux = Class->first;

   for(int i = 0; i < Class->size; i++){
    printf("Student %d: ", i + 1);
    show_student(aux);
    aux = aux->link;
   }
}

#endif