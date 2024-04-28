#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct stack{
    int size;
    node *head;
}stacks;

stacks *createStack(){
    stacks *stack = (stacks*)malloc(sizeof(stacks*));
    stack->head = NULL; stack->size = 0;
    return stack;
}

void push(stacks *stack, node *new_node){
    if(stack->head == NULL){
        stack->head = new_node;
    }
    else{
        new_node->link = stack->head;
        stack->head = new_node;
    }
    stack->size++;
}

void pop(stacks *stack){
    if(stack->head == NULL){
        printf("\nStack empty.\n");
        return;
    }

    node *aux = stack->head; stack->head = stack->head->link; stack->size--;
    printf("\nNode to eliminate: %d\n", aux->value); free(aux);
}

void show(stacks *stack){

    if(stack->head == NULL){
        printf("\nStack empty.\n");
        return;
    }

    node *aux = stack->head->link;


    printf("\nHEAD: %d \t SIZE: %d\n", stack->head->value, stack->size);
    for(int i = 0; i < stack->size && aux != NULL; i++){
        printf("\tNODE (%d) VALUE: ", stack->size - i); show_node(aux);
        aux = aux->link;
    }
}

void free_memory(stacks *stack){
    node *aux = stack->head;

    while(aux != NULL){
        node *temp = aux;
        aux = aux->link;
        free(temp);
    }
    free(aux); free(stack);
}

#endif