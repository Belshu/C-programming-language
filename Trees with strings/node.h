#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *name;
    struct node *father;
    struct node *right;
    struct node *left;
}node;

node *createNode(char *name){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->name = (char*)malloc(sizeof(char));

    new_node->father = NULL, new_node->right = NULL, new_node->left = NULL;
    strcpy(new_node->name, name);

    return new_node;    
}

void free_memory(node *aux){
    if(aux != NULL){
        node *temp = aux;

        if(aux->right != NULL){
            free_memory(aux->right);
        }

        if(aux->left != NULL){
            free_memory(aux->left);
        }

        free(temp);
    }
}

void show_nodes(node *aux){
    if(aux != NULL){
        printf("%s | ", aux->name);

        if(aux->right != NULL){
            show_nodes(aux->right);
        }

        if(aux->left != NULL){
            show_nodes(aux->left);
        }
    }
}

#endif