#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    int N;
    scanf("%d",&N);
    int* array = (int*)calloc(N,sizeof(int));
    for(int i=0; i<N; i++){
        scanf("%d",&array[i]);
    }
    int* binary = (int*)calloc(N,sizeof(int));
    for(int i=0; i<pow(2,N); i++){
        printf("{ ");
        for(int j=0; j<N; j++){
            if(binary[j]){
                printf("%d ",array[j]);             }
        }
        int index=0;
        while(binary[index]){
            binary[index] = 0;
            index++;
        }

        printf(" }\n");
        if(index == N){
            break;}
        else{
            binary[index] = 1;
        }


    }
    free(array);
    free(binary);




    return 0;
}
