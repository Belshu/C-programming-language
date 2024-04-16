#include <stdio.h>
#include<stdlib.h>

//NODE STRUCTURE
typedef struct node{
	int value;
	struct node *link;
}node;


//NODE CREATION CODE
node *create_node(int value){
	node *new = (node*)malloc(sizeof(node));

	new->value = value;
	new->link = NULL;

	return new;
}

