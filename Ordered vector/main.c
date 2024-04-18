#include <stdio.h>

int main(){
    int num, aux;
    char key;

    do{
        printf("\nIntroduce the number of values to insert in your vector: "), scanf("%d", &num);
        getchar();

        int vec[num];

        for(int i = 0; i < num; i++){
            printf("\nvector[%d]: ", i + 1), scanf("%d", &vec[i]);
            getchar();
        }

        for(int i = 0; i < num; i++){
            for(int j = i + 1; j < num; j++){
                if(vec[i] < vec[j]){
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }

        printf("\nOrdered vector: ");
        for(int i = 0; i < num; i++){
            printf("%d | ", vec[i]);
        }
        printf("\n\nDo you want to continue? [S/N] "), scanf("%c", &key);
        getchar();

    }while(key == 's' || key == 'S');

    return 0;
}