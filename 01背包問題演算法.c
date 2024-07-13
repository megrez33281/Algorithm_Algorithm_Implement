#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define max(a,b) (a>b)?a:b



int main(){
    //使用動態規畫計算出所有C[i][j],1<=i<=物品數,0<=j<=最大承受重量
    //此時C[i][j]代表在有i件物品，承受重量為j的情況下能放的最高價值

    int W;  //能承受的重量
    printf("Input the largest weight：");
    scanf("%d",&W);
    int item_amount;  //物品數量
    printf("Input the items amount：");
    scanf("%d", &item_amount);
    int* item_weight = (int*)calloc(item_amount+1,sizeof(int));
    int* item_value = (int*)calloc(item_amount+1,sizeof(int));

    printf("w v\n");
    //讀取物品
    for(int i=1; i<item_amount+1; i++){
        scanf("%d %d",&item_weight[i],&item_value[i]);
    }

    //建立一個row數量為item_amount+1，column數量為W+1之表格C
    //C[i,w]表示i個物品，重量限制為w下之最大價值
    int** C = (int**)calloc(item_amount+1,sizeof(int*));
    int** Choose = (int**)calloc(item_amount+1,sizeof(int*));
    for(int i=0; i<item_amount+1; i++){
        C[i] = (int*)calloc(W+1,sizeof(int));
        Choose[i] = (int*)calloc(W+1,sizeof(int));
    }

    //令所有C[0,w]皆為0(沒有物品可以選擇，不管重量限制為多少價值皆為0)
    for(int i=0; i<W+1; i++){
        C[0][i] = 0;
    }

    //從左到右，上到下開始填表格
    for(int i=1; i<item_amount+1; i++){ //由於i=0處已經填過，從i=1處開始填
        for(int j=0; j<W+1; j++){
            //C[i][j]代表i個物品可以放入，重量限制為j

            //物品重量小於重量限制之情形
            if(item_weight[i] <= j){

                //此時選取取或不取時之最大利益
                C[i][j] = max(C[i-1][j],C[i-1][j-item_weight[i]] + item_value[i]);
                //用C[i-1][j-item_weight[i]] + item_value[i]來計算是因為必須空出足夠重量使得物件i可以放入，所以選擇C[i-1][j-(物件i之重量)]的值來加上物件i之價值可以確保物件i是放進去的狀態
                //以物件i已經被放入為前提，再加上剩下的1~i-1件物品放入背包，重量限制為j-(物件i之重量)，即C[i-1][j-(物件i之重量)]
                if(C[i-1][j] < C[i-1][j-item_weight[i]] + item_value[i]){//選則物品i
                    Choose[i][j] = 1;//代表在C[i][j]的情形下物品i有被選擇到
                }
            }

            else{   //物品重量大於重量限制時無法放入
                //此時C[i][j]之值會和物品只有i-1時相同
                C[i][j] = C[i-1][j];
            }

        }

    }

    printf("W  ");
    for(int i=0; i<W+1; i++){
        if( i!= 0 && i < 10 ){
            printf("   ");
            }
        else if( i==0 || i < 100){
            printf("  ");
            }
        else if(i < 1000){
            printf(" ");
        }

        printf("%d",i);
    }
    printf("\n");

    for(int i=0; i<item_amount+1; i++){
        printf("x%d",i);
        for(int j=0; j<W+1; j++){

            if(C[i][j] < 10){
                printf("   ");
            }
            else if(C[i][j] < 100){
                printf("  ");
            }
            else if(C[i][j] < 1000){
                printf(" ");
            }
            printf("%d",C[i][j]);
        }

        printf("\n");

    }
    printf("\nChoose：\n");
    printf("W   ");
    for(int i=0; i<W+1; i++){
        if( i!= 0 && i < 10 ){
            printf("   ");
            }
        else if( i==0 || i < 100){
            printf("  ");
            }
        else if(i < 1000){
            printf(" ");
        }
        printf("%d",i);
    }
    printf("\n");
    for(int i=1; i<item_amount+1; i++){
        printf("   ");
        for(int j=0; j<W+1; j++){
            printf("   %d",Choose[i][j]);
        }
        printf("\n");
    }

    printf("\nChoose item："); //輸出選擇的物品
    int k = W;
    for(int i=item_amount; i>=1; i--){
        if(Choose[i][k] == 1){//若C[i][k]有被選擇，代表物件i有被選擇
            k -= item_weight[i]; //重量限制剩下k-item_weight[i];
            printf("x%d ",i);
        }

    }
    printf("\n");

    free(Choose);
    free(C);
    free(item_weight);
    free(item_value);
	return 0;
}
