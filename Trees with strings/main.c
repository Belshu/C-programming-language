#include "tree.h"

int main(){
    int num;
    char *name = (char*)malloc(sizeof(char));
    trees *tree = createTree();

    printf("\nIntroduce the name of the root: "), gets(name);
    node *aux = createNode(name);
    tree->root = aux;

    printf("\nIntroduce the number of nodes to introduce: "), scanf("%d", &num);
    getchar();

    free(name);
    name = (char*)malloc(sizeof(char));

    for(int i = 0; i < num; i++){
        printf("NODE %d: ", i + 1), gets(name);
        introduce_node(tree, createNode(name));
    }

    show_tree(tree);
    printf("\n\n");

    int op;
    do{
        printf("\n- - - - - - - - - - - - - - - - MAIN MENU - - - - - - - - - - - - -\n");
        printf("(0) Exit the program.\n");
        printf("(1) Introduce a new node to the tree.\n");
        printf("(2) Eliminate a node in the tree.\n");
        printf("(3) Show all the tree.\n");
        printf("(4) Search a node.\n");
        printf("Select an option: "), scanf("%d", &op);
        getchar();

        switch(op){
            case 0:
            break;

            case 1:
            printf("\nIntroduce the name of the new node: "), gets(name);
            introduce_node(tree, createNode(name));
            break;

            case 2:
            eliminate_node(tree);
            break;

            case 3:
            show_tree(tree);
            printf("\n\n");
            break;

            case 4:
            printf("\nIntroduce the name of the node to search: "), gets(name);
            search_node(tree, name);
            break;

            default:
            printf("\nERROR: not valid option...\n");
        }
    }while(op != 0);

    printf("\nFinishing the program...\n");

    free_memory(tree->root);
    free(tree);
    return 0;
}