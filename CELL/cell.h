#ifndef CELL_H
#define CELL_H

#include "node.h"

//CELL STRUCTURE
typedef struct cells{
	int size;
	node *head;
}cells;


//CELL CREATION CODE
cells *create_cell(){
	cells *cell = (cells*)malloc(sizeof(cells));

	cell->size = 0;
	cell->head = NULL;

	return cell;
}


//FUNCTION: introduce nodes to the cell
void introduce_node(cells *cell, node *new){
	if(cell->head == NULL){
		cell->head = new;
	}
	else{
		node *aux = cell->head;
		while(aux->link != NULL){
			aux = aux->link;
		}
		aux->link = new;
    }
    cell->size++;
}


//FUNCTION: introduce nodes at the start of the cell
void introduce_node_start(cells *cell, node *new){    
    new->link = cell->head;
    cell->head = new;
    cell->size++;
}


void eliminate_node_start(cells *cell){
    node *aux = cell->head;
    cell->head = cell->head->link;

    free(aux);
    cell->size--;
}

void eliminate_node_end(cells *cell){
    node *aux = cell->head;
    node *prev = aux;

    for(int i = 0; i < cell->size; i++){
        prev = aux;
        aux = aux->link;
    }

    prev->link = NULL;
    free(aux);
    cell->size--;
}

void eliminate_node(cells *cell, int value){
    node *aux = cell->head;
    node *prev = aux;

    while(aux->value != value){
        prev = aux;
        aux = aux->link;
    }    
    prev->link = aux->link;
    free(aux);
}

#endif
