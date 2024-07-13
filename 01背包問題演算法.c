#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define max(a,b) (a>b)?a:b



int main(){
    //�ϥΰʺA�W�e�p��X�Ҧ�C[i][j],1<=i<=���~��,0<=j<=�̤j�Ө����q
    //����C[i][j]�N��b��i�󪫫~�A�Ө����q��j�����p�U��񪺳̰�����

    int W;  //��Ө������q
    printf("Input the largest weight�G");
    scanf("%d",&W);
    int item_amount;  //���~�ƶq
    printf("Input the items amount�G");
    scanf("%d", &item_amount);
    int* item_weight = (int*)calloc(item_amount+1,sizeof(int));
    int* item_value = (int*)calloc(item_amount+1,sizeof(int));

    printf("w v\n");
    //Ū�����~
    for(int i=1; i<item_amount+1; i++){
        scanf("%d %d",&item_weight[i],&item_value[i]);
    }

    //�إߤ@��row�ƶq��item_amount+1�Acolumn�ƶq��W+1�����C
    //C[i,w]���i�Ӫ��~�A���q���w�U���̤j����
    int** C = (int**)calloc(item_amount+1,sizeof(int*));
    int** Choose = (int**)calloc(item_amount+1,sizeof(int*));
    for(int i=0; i<item_amount+1; i++){
        C[i] = (int*)calloc(W+1,sizeof(int));
        Choose[i] = (int*)calloc(W+1,sizeof(int));
    }

    //�O�Ҧ�C[0,w]�Ҭ�0(�S�����~�i�H��ܡA���ޭ��q����h�ֻ��ȬҬ�0)
    for(int i=0; i<W+1; i++){
        C[0][i] = 0;
    }

    //�q����k�A�W��U�}�l����
    for(int i=1; i<item_amount+1; i++){ //�ѩ�i=0�B�w�g��L�A�qi=1�B�}�l��
        for(int j=0; j<W+1; j++){
            //C[i][j]�N��i�Ӫ��~�i�H��J�A���q���j

            //���~���q�p�󭫶q�������
            if(item_weight[i] <= j){

                //���ɿ�����Τ����ɤ��̤j�Q�q
                C[i][j] = max(C[i-1][j],C[i-1][j-item_weight[i]] + item_value[i]);
                //��C[i-1][j-item_weight[i]] + item_value[i]�ӭp��O�]�������ťX�������q�ϱo����i�i�H��J�A�ҥH���C[i-1][j-(����i�����q)]���Ȩӥ[�W����i�����ȥi�H�T�O����i�O��i�h�����A
                //�H����i�w�g�Q��J���e���A�A�[�W�ѤU��1~i-1�󪫫~��J�I�]�A���q���j-(����i�����q)�A�YC[i-1][j-(����i�����q)]
                if(C[i-1][j] < C[i-1][j-item_weight[i]] + item_value[i]){//��h���~i
                    Choose[i][j] = 1;//�N��bC[i][j]�����ΤU���~i���Q��ܨ�
                }
            }

            else{   //���~���q�j�󭫶q����ɵL�k��J
                //����C[i][j]���ȷ|�M���~�u��i-1�ɬۦP
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
    printf("\nChoose�G\n");
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

    printf("\nChoose item�G"); //��X��ܪ����~
    int k = W;
    for(int i=item_amount; i>=1; i--){
        if(Choose[i][k] == 1){//�YC[i][k]���Q��ܡA�N����i���Q���
            k -= item_weight[i]; //���q����ѤUk-item_weight[i];
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
