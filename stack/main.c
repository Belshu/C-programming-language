// stack: LIFO struct

#include "stack.h"

int main(){
    int num;
    stacks *stack = createStack();
    printf("\nIntroduce the number of nodes to include: "), scanf("%d", &num);
    getchar();

    for(int i = 0; i < num; i++){
        printf("Node %d: ", i + 1), push(stack, createNode());
    }

    printf("\n\n"); show(stack);

    int op;

    do{
        printf("\n\n(0) Exit the program.\n");
        printf("(1) Push.\n");
        printf("(2) Pop.\n");
        printf("(3) Show.\n");
        printf("Select an option: "), scanf("%d", &op);
        getchar();

        switch (op){
            case 0:  
            break;

            case 1:
            printf("\nIntroduce the value of the new node: ");
            push(stack, createNode());
            break;

            case 2:
            pop(stack);
            break;

            case 3:
            printf("\n\n"); show(stack); printf("\n\n");
            break;

            default:
            printf("\nERROR: invalid option...\n");
            break;
        }
    }while(op != 0);

    printf("\nFinishing the program...\n"); free_memory(stack);
    return 0;
}