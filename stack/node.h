#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *link;
}node;

node *createNode(){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->link = NULL;
    
    scanf("%d", &new_node->value);
    getchar();

    return new_node;
}

void show_node(node *new_node){
    if(new_node != NULL){
        printf("%d\n", new_node->value);
    }
}

#endif