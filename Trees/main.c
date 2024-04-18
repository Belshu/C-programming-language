#include "tree.h"

int main(){
    trees *tree = create_tree();
    int num, value;

    printf("\nIntroduce the number of nodes for your tree: "), scanf("%d", &num);
    getchar();

    printf("\nThe first node will be the roof value.\n");
    for(int i = 0; i < num; i++){
        printf("\nIntroduce the value of the node %d: ", i + 1), scanf("%d", &value);
        getchar();
        introduce_node(tree, create_node(value));
    }

    show_tree(tree);

    int op;
    do{
        printf("\n- - - -- - - - -- - - MAIN MENU - - - - - - - - - -\n");
        printf("(0) Exit the program.\n");
        printf("(1) Introduce a new node to the tree.\n");
        printf("(2) Eliminate a node in the tree.\n");
        printf("(3) Show the tree or a side of the root.\n");
        printf("(4) Search a node in the tree.\n");
        printf("Select an option: "), scanf("%d", &op);
        getchar();

        switch(op){
            case 0:
            break;

            case 1:
            printf("\nIntroduce the value of the node: "), scanf("%d", &value);
            introduce_node(tree, create_node(value));
            break;

            case 2:
            eliminate_node(tree);
            break;

            case 3:
            show_tree(tree);
            break;

            case 4:
            search_node(tree);
            break;

            default:
            printf("\nERROR: not valid option...\n");
        }

    }while(op != 0);

    printf("\nFinishing the program...\n");

    return 0;
}