#include <stdio.h>
#include <stdlib.h>

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


//NODE CREATION CODE
node *create_node(int value){
	node *new = (node*)malloc(sizeof(node));

	new->value = value;
	new->link = NULL;

	return new;
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


//FUNCTION: prints all the values in order
void show(cells *cell){
	node *aux = cell->head;
	while(aux->link != NULL){
		printf(" %d | ", aux->value);
		aux = aux->link;
	}
}


int main(){
	int num, value;

	cells *cell = create_cell();

	printf("Introduce the number of nodes in your cell: "), scanf("%d", &num);

	for(int i = 0; i < num; i++){
		printf("\nNode %d: "), scanf("%d", &value);
		introduce_node(cell, create_node(value));
	}

	printf("\n");
	show(cell);

	return 0;
}
		
