#include <stdio.h>

int main(){
    int num;
    char key;

    do{

        printf("\nIntroduce a number: "), scanf("%d", &num);
        getchar();

        if(num % 2 == 0){
            printf("\n %d is an even number.\n", num);
        }
        else{
            printf("\n %d is an odd number.\n", num);
        }

        printf("\nDo you want to continue? [S/N] "), scanf("%c", &key);
        getchar();

    }while(key == 's' || key == 'S');

    printf("\nFinishing the program...\n");

    return 0;
}