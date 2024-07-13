#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>



int main(){

    char a[100] = {0};
    char b[100] = {0};
    scanf("%s %s",a,b);

    if(strlen(a) > strlen(b)){
        printf("false!\n");
    }
    else{
        int ptra = 0;
        int ptrb = 0;
        while(ptra != strlen(a) && ptra != strlen(b)){
            if(a[ptra] == b[ptrb]){
                ptra++;
                ptrb++;
            }
            else{
                ptrb++;
            }

        }
        printf("%d\n",ptra);
        if(ptra == strlen(a)){
            printf("true!\n");
        }
        else{
            printf("false!\n");
        }

    }
    return 0;
}
