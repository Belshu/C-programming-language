#ifndef TREE_H
#define TREE_H

#include "node.h"

typedef struct trees{
    int size_left, size_right;
    node *root;
}trees;

trees *create_tree(){
    trees *tree = (trees*)malloc(sizeof(trees*));

    tree->root = NULL;
    tree->size_left = 0;
    tree->size_right = 0;

    return tree;
}

void introduce_node(trees *tree, node *new_node){
    if(tree->root == NULL){
        tree->root = new_node;
    }
    else{
        node *aux = tree->root;
        node *prev = aux;
        
        while(aux != NULL){
            prev = aux;
            if(new_node->value > aux->value){
            aux = aux->right;
            }
            else{
                aux = aux->left;
            }
        }

        new_node->father = prev;

        if(new_node->value >= prev->value){
            prev->right = new_node;
            tree->size_right++;
        }
        else{
            prev->left = new_node;
            tree->size_left++;
        }
    }
    printf("\nNode %d succesfully introduced! \n", new_node->value);
}

void eliminate_node(trees *tree){
    int value;

    printf("\nIntroduce the value of the node to remove: "), scanf("%d", &value);
    getchar();

    if(value >= tree->root->value){
        node *aux = tree->root->right;

        for(int i = 0; i < tree->size_right; i++){
            if(aux->value == value){
                break;
            }
            
            if(value >= aux->value){
                aux = aux->right;
            }
            else{
                aux = aux->left;
            }
        }

        if(aux == NULL){
            printf("\nNode not found.\n");
        }
        else{
            node *prev = aux->father;

            if(aux->right != NULL){
                node *post = aux->right;

                post->father = prev;

                if(post->value >= prev->value){
                    prev->right = post;
                }
                else{
                    prev->left = post;
                }
            }
            else if(aux->left != NULL){
                node *post = aux->left;

                post->father = prev;

                if(post->value >= prev->value){
                    prev->right = post;
                }
                else{
                    prev->left = post;
                }
            }
            else{
                if(aux->value >= prev->value){
                    prev->right = NULL;
                }
                else{
                    prev->left = NULL;
                }
            }
            free(aux);
            printf("\nNode %d succesfully eliminated!\n", value);
        }
        tree->size_right--;
    }
    else{
        node *aux = tree->root->left;

        for(int i = 0; i < tree->size_right; i++){
            if(aux->value == value){
                break;
            }
            
            if(value >= aux->value){
                aux = aux->right;
            }
            else{
                aux = aux->left;
            }
        }

        if(aux == NULL){
            printf("\nRoot nor found.\n");
        }
        else{
            node *prev = aux->father;

            if(aux->right != NULL){
                node *post = aux->right;

                post->father = prev;

                if(post->value >= prev->value){
                    prev->right = post;
                }
                else{
                    prev->left = post;
                }
            }
            else{
                node *post = aux->left;

                post->father = prev;

                if(post->value >= prev->value){
                    prev->right = post;
                }
                else{
                    prev->left = post;
                }
            }
            free(aux);
            printf("\nNode %d succesfully eliminated!\n", value);
        }
        tree->size_left--;
    }
}

void show_node(node *new_node){
    if(new_node != NULL){
        printf("%d | ", new_node->value);
        show_node(new_node->right);
        show_node(new_node->left);
    }
}

void show_tree(trees *tree){
    node *right = tree->root->right;
    node *left = tree->root->left;

    printf("\n\nRoot value: %d\n", tree->root->value);
    printf("\nRight size: %d    | Left size: %d", tree->size_right, tree->size_left);
    
    printf("\nNodes at the right of the roof: \n");
    show_node(right);
    printf("\n\nNodes at the left of the root: \n");
    show_node(left);
}

void search_node(trees *tree){
    int value, num_aux = 0;

    printf("\nIntroduce the value of the node to search: "), scanf("%d", &value);
    getchar();

    if(value >= tree->root->value){
        node *aux = tree->root->right;
        for(int i = 0; i < tree->size_right && num_aux == 0; i++){
            if(value == aux->value){ 
                num_aux = 1;
                break;
            }
            
            if(value >= aux->value){
                aux = aux->right;
            }
            else{
                aux = aux->left;
            }
        }

        if(num_aux == 0){
            printf("\nNode not found.\n");
        }
        else{
            if(aux->value >= aux->father->value){
                printf("\nNode %d found in the right side of the node %d.", aux->value, aux->father->value);
            }
            else{
                printf("\nNode %d found in the right side of the node %d.", aux->value, aux->father->value);
            }

            if(aux->right != NULL){
                printf(" A node linked in the right side is %d", aux->right->value);

                if(aux->left != NULL){
                    printf(" and in the left side is %d.\n", aux->left->value);
                }
                else{
                    printf(".\n");
                }
            }
            else if(aux->left != NULL){
                printf(" A node linked in the left side of it is %d", aux->left->value);
            }

            if(aux->right != NULL){
                printf(" and in the right side is %d.\n", aux->right->value);
            }
                else{
                printf(".\n");
            }
        }
    }
    else{
        node *aux = tree->root->left;

        for(int i = 0; i < tree->size_left && num_aux == 0; i++){
            if(value == aux->value){
                num_aux = 1;
                break;
            }

            if(value >= aux->value){
                aux = aux->right;
            }
            else{
                aux = aux->left;
            }
        }

        if(num_aux == 0){
            printf("\nNode not found.\n");
        }
        else{
            if(aux->value >= aux->father->value){
                printf("\nNode %d found in the right side of the node %d.", aux->value, aux->father->value);
            }
            else{
                printf("\nNode %d found in the right side of the node %d.", aux->value, aux->father->value);
            }

            if(aux->right != NULL){
                printf(" A node linked in the right side is %d", aux->right->value);

                if(aux->left != NULL){
                    printf(" and in the left side is %d.\n", aux->left->value);
                }
                else{
                    printf(".\n");
                }
            }
            else if(aux->left != NULL){
                printf(" A node linked in the left side of it is %d", aux->left->value);
            }

            if(aux->right != NULL){
                printf(" and in the right side is %d.\n", aux->right->value);
            }
                else{
                printf(".\n");
            }
        }
    }
}

#endif