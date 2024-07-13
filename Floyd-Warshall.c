#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b)?a:b

int main() {

    char node[5] = {'1','2','3','4','5'};//節點
    int n;
    scanf("%d",&n);
    int** dis = (int**)calloc(n,sizeof(int*));
    char** pre = (char**)calloc(n,sizeof(char*));
    for(int i=0; i<n; i++){
        dis[i] = (int*)calloc(n,sizeof(int));
        pre[i] = (char*)calloc(n,sizeof(char));
    }
    //讀取陣列
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&dis[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && dis[i][j] != 99){
                pre[i][j] = node[i];
            }
            else{
                pre[i][j] = 'x';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c ",pre[i][j]);}
        printf("\n");
    }
    printf("\n");
    for(int k=0; k<n; k++){//以中間節點之順序來比較
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                    pre[i][j] = pre[k][j];  //i->k->j
                }
            }
        }
        printf("middle node=%c\n",node[k]);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d ",dis[i][j]);}
            printf("\n");
        }
        printf("\n");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%c ",pre[i][j]);}
        printf("\n");
    }
    printf("\n");
    }
    //印出all ot all距離
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",dis[i][j]);}
        printf("\n");
    }
    printf("\n");

    //印出路徑
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c ",pre[i][j]);}
        printf("\n");
    }
    printf("\n");
    free(dis);
    free(pre);
    return 0;
}
