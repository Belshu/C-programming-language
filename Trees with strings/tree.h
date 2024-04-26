#ifndef TREE_H
#define TREE_H

#include "node.h"

#define N 100

typedef struct trees{
    int size_right, size_left;
    node *root;
}trees;

trees *createTree(){
    trees *tree = (trees*)malloc(sizeof(trees));

    tree->root = NULL, tree->size_left = 0, tree->size_right = 0;

    return tree;
}

void introduce_node(trees *tree, node *new_node){
    node *aux = tree->root;
    node *prev = aux;

    while(aux != NULL){
        prev = aux;

        if(strcmp(new_node->name, aux->name) > 0){
            aux = aux->right;
        }
        else{
            aux = aux->left;
        }
    }

    new_node->father = prev;

    if(strcmp(new_node->name, prev->name) > 0){
        prev->right = new_node;
        tree->size_right++;
    }
    else{
        prev->left = new_node;
        tree->size_left++;
    }
    printf("Node '%s' succesfully introduced!\n", new_node->name);
}

void eliminate_node(trees *tree){
    char *name = (char*)malloc(sizeof(char));

    printf("\nIntroduce the name of the node to remove: "), fgets(name, N, stdin);
    name[strcspn(name, "\n")] = 0;

    node *aux = tree->root;

    if(strcmp(name, tree->root->name) == 0){
        printf("\nThis node is the root of the tree and cannot be remove.\n");
        return;   
    }

    while(strcmp(name, aux->name) != 0 && aux != NULL){
        if(strcmp(name, aux->name) > 0){
            aux = aux->right;
        }
        else{
            aux = aux->left;
        }
    }

    if(aux == NULL){
        printf("\nERROR: node not founded...\n");
        return;   
    }

    if(aux->right != NULL){
        aux->right->father = aux->father;

        if(strcmp(aux->right->name, aux->father->name) > 0){
            aux->father->right = aux->right;
        }
        else{
            aux->father->left = aux->left;
        }
    }

    if(aux->left != NULL){
        aux->left->father = aux->father;

        if(strcmp(aux->left->name, aux->father->name) > 0){
            aux->father->right = aux->left;
        }
        else{
            aux->father->left = aux->left;
        }
    }
}

void show_tree(trees *tree){
    printf("\nTREE: %s | RIGHT SIZE: %d | LEFT SIZE: %d\n", tree->root->name, tree->size_right, tree->size_left);
    printf("\tNODES AT THE RIGHT OF THE ROOT: \n");
    show_nodes(tree->root->right);
    printf("\n\tNODES AT THE LEFT OF THE ROOT: \n");
    show_nodes(tree->root->left);
}

void search_node(trees *tree, char *name){
    node *aux = tree->root;

    if(strcmp(tree->root->name, name) == 0){
        printf("\nThe name '%s' is the root of the tree.");

        if(tree->root->right != NULL){
            printf("\nIt has the node '%s' at the right side.", tree->root->right->name);
        }

        if(tree->root->left != NULL){
            printf("\nIt has the node '%s' at the left side.", tree->root->left->name);
        }

        return;
    }

    while(aux != NULL && strcmp(aux->name, name) != 0){
        if(strcmp(name, aux->name) > 0){
            aux = aux->right;
        }
        else{
            aux = aux->left;
        }
    }

    if(aux == NULL){
        printf("\nERROR: node not found.\n");
        return;
    }

    printf("\nThe father's node of '%s' is: %s.\n", aux->name, aux->father->name);

    if(aux->right != NULL){
        printf("\nIt has a node '%s' linked on the right side.", aux->right->name);
    }

    if(aux->left != NULL){
        printf("\nIt has a node '%s' linked on the left side.", aux->left->name);
    }

    printf("\n");
}

#endif