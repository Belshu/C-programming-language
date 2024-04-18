#include <stdio.h>

int main(){
    int num;
    char key;

    do{
        printf("\nIntroduce a number: "), scanf("%d", &num);
        getchar();

        if(num <= 1){
            printf("\n %d is not a prime number.\n", num);
        }

        for(int i = 2; i <= num; i++){
            if(num % i == 0){
                printf("\n %d is not a prime number.\n", num);
                break;
            }
            else{
                printf("\n %d is a prime number.\n", num);
                break;
            }
        }

        printf("\nDo you want to continue? [S/N] "), scanf("%c", &key);
        getchar();
    }while(key == 's' || key == 'S');

    printf("\nFinishing the program...\n");

    return 0;
}