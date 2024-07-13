#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define max(a,b) (a>b)?a:b

int main(){

    int items,weight;
    printf("items  weight\n");
    scanf("%d %d",&items,&weight);
    printf("item_weight   item_value\n");
    int* item_weight = (int*)calloc(items+1,sizeof(int));
    int* item_value = (int*)calloc(items+1,sizeof(int));
    int** values = (int**)calloc(items+1,sizeof(int*)); //多一格用來代表沒有任何物品
    values[0] = (int*)calloc(weight+1,sizeof(int));   //沒有任何物品時，value皆為0
    for(int i=1; i<items+1; i++){
        scanf("%d %d",&item_weight[i],&item_value[i]);
        values[i] = (int*)calloc(weight+1,sizeof(int)); //初始化
    }

    for(int item=1; item < items+1; item++){
        for(int w =0; w<weight+1; w++){
            //當前背包容量不足以放下物品，values與item-1相同
            if(w < item_weight[item]){
                values[item][w] = values[item-1][w];
            }
            //容量足夠，判斷放入物品與不放入物品何者價值較高
            else{

               values[item][w] = max(values[item-1][w], item_value[item] + values[item-1][w-item_weight[item]]);
            }
        }
    }

    for(int i=0; i<items+1; i++){
        for(int j=0; j<weight+1; j++){
            printf("%d ",values[i][j]);
        }
        printf("\n");
    }


    free(values);
    free(item_weight);
    free(item_value);
    return 0;
}
