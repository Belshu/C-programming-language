#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *right;
    struct node *left;
    struct node *father;
}node;

node *create_node(int value){
    node *new_node = (node*)malloc(sizeof(node));

    new_node->value = value;
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->father = NULL;

    return new_node;
}

#endif