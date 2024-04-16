#include "cell.h"

//FUNCTION: prints all the values in order
void show(cells *cell){
	node *aux = cell->head;
	while(aux != NULL){
		printf(" %d | ", aux->value);
		aux = aux->link;
	}
}


int main(){
	int num, value;

	cells *cell = create_cell();

	printf("Introduce the number of nodes in your cell: "), scanf("%d", &num);

	for(int i = 0; i < num; i++){
		printf("Node %d: ", i + 1), scanf("%d", &value);
		introduce_node(cell, create_node(value));
	}

	printf("\n");
	show(cell);
	printf("\n");

	int op, op2;

	do{
		printf("\n- - - - - - - MAIN MENU - - - - -- - - \n");
		printf("(0) Exit the program.\n");
		printf("(1) Introduce a new node at the end of the cell.\n");
		printf("(2) Introduce a new node at the start of the cell.\n");
		printf("(3) Eliminate the last node of the cell.\n");
		printf("(4) Eliminate the first node of the cell.\n");
		printf("(5) Eliminate a node inside of the cell.\n");
		printf("\nSelect an option: "), scanf("%d", &op);
		getchar();

		switch(op){
			case 0:
			break;

			case 1:
			printf("\nIntroduce the value of the new node: "), scanf("%d", &value);
			getchar();
			introduce_node(cell, create_node(value));
			printf("\nNode succesfully created and introduced!\n");
			break;

			case 2:
			printf("\nIntroduce the value of the new node: "), scanf("%d", &value);
			getchar();
			introduce_node_start(cell, create_node(value));
			printf("\nNode succesfully created and introduced!\n");
			break;

			case 3:
			eliminate_node_end(cell);
			printf("\nNode succesfully remove!\n");
			break;

			case 4:
			eliminate_node_start(cell);
			printf("\nNode succesfully remove!\n");
			break;

			case 5:
			printf("\nIntroduce the value of the node to remove: "), scanf("%d", &value);
			getchar();
			eliminate_node(cell, value);
			break;

			default:
			printf("\n ERROR: %d is not a valid option.\n", op);
		}

	}while(op != 0);

	printf("\nLeaving the program...\n");

	return 0;
}
		
