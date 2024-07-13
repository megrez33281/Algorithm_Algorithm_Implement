#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define max(a,b) (a>b)?a:b

int main(){

    char a[100];
    char b[100];
    scanf("%s %s", a+1, b+1);
    int lena = strlen(a+1);
    int lenb = strlen(b+1);
    int** arrays = (int**)calloc(lena+1,sizeof(int*));
    int** direct = (int**)calloc(lena+1,sizeof(int*));
    for(int i=0; i<lena+1; i++){
        arrays[i] = (int*)calloc(lenb+1,sizeof(int));
        direct[i] = (int*)calloc(lenb+1,sizeof(int));
    }

    for(int i=1; i<lena+1; i++){
        for(int j=1; j<lenb+1; j++){
            if(a[i] == b[j]){
                arrays[i][j] = arrays[i-1][j-1] + 1;
                direct[i][j] = 3; //表示從左上方過來
            }
            else{
                if(arrays[i-1][j] > arrays[i][j-1]){
                    arrays[i][j] = arrays[i-1][j];
                    direct[i][j] = 1; //表示從上方過來
                }
                else{
                    arrays[i][j] = arrays[i][j-1];
                    direct[i][j] = 2; //表示從左邊過來
                }
            }
        }
    }

    printf("The longest subset is：%d\n",arrays[lena][lenb]);
    int indexa = lena;
    int indexb = lenb;
    int* a_stack = (int*)calloc(lena,sizeof(int));
    int index = 0;
    while(indexa > 0 && indexb > 0){
        if(direct[indexa][indexb] == 3){
            a_stack[index++] = indexa;
            indexa--;
            indexb--;
        }
        else if(direct[indexa][indexb] == 2){
            indexb--;
        }
        else if(direct[indexa][indexb] == 1){
            indexa--;
        }


    }
    for(int i=index-1; i>=0; i--){
        int index_a = a_stack[i];
        printf("%c",a[index_a]);
    }
    printf("\n");

    free(a_stack);
    free(direct);
    free(arrays);
    return 0;
}
