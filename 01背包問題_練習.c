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
    int** values = (int**)calloc(items+1,sizeof(int*)); //�h�@��ΨӥN��S�����󪫫~
    values[0] = (int*)calloc(weight+1,sizeof(int));   //�S�����󪫫~�ɡAvalue�Ҭ�0
    for(int i=1; i<items+1; i++){
        scanf("%d %d",&item_weight[i],&item_value[i]);
        values[i] = (int*)calloc(weight+1,sizeof(int)); //��l��
    }

    for(int item=1; item < items+1; item++){
        for(int w =0; w<weight+1; w++){
            //��e�I�]�e�q�����H��U���~�Avalues�Pitem-1�ۦP
            if(w < item_weight[item]){
                values[item][w] = values[item-1][w];
            }
            //�e�q�����A�P�_��J���~�P����J���~��̻��ȸ���
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
