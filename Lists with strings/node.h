#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct node{
    char *name, *surname;
    int age;
    struct node *link;
}node;

node *create_node(){
    node *student = (node*)malloc(sizeof(node));
    
    student->name = (char*)malloc(sizeof(char));
    printf("\nIntroduce the name of the student: "), fgets(student->name, N, stdin);
    student->name[strcspn(student->name, "\n")] = 0;

    student->surname = (char*)malloc(sizeof(char));
    printf("\nIntrodue the surname of the student %s: ", student->name), fgets(student->surname, N ,stdin);
    student->surname[strcspn(student->surname, "\n")] = 0;

    printf("\nIntroduce his/her age: "), scanf("%d", &student->age);
    getchar();

    student->link = NULL;

    return student;
}

void show_student(node *student){
    printf("%s %s | AGE: %d\n", student->name, student->surname, student->age);
}

#endif