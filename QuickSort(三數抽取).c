#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void swap(int* a ,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
void quickSort(int* arrays,int length){

    if(length == 2 && arrays[0] > arrays[1]){
        swap(&arrays[0],&arrays[1]);
    }
    if(length <=2 ){return;}
    int middle = length/2;
    //將最大值放到最右邊
    if(arrays[middle] > arrays[length-1] && arrays[middle] > arrays[0]){
        swap(&arrays[middle],&arrays[length-1]);
    }
    if(arrays[0] > arrays[middle] && arrays[0] > arrays[length-1]){
        swap(&arrays[0],&arrays[length-1]);
    }
    //將中間的值放到中間，左邊的值放到左邊
    if(arrays[middle] < arrays[0]){
        swap(&arrays[middle],&arrays[0]);
    }
    //此時arrays的左、中、右已按照大小排序
    //將中間與右邊左側元數交換
    swap(&arrays[middle],&arrays[length-2]);
    if(length <= 3){return;}

    int pivot = arrays[length-2];
    int left = 0;
    int right = length-2;
    while(left < right){
        while(left < right && arrays[left] <= pivot){
            left++;
        }
        while(left < right && arrays[right] >= pivot){
            right--;
        }

        if(left < right){
            swap(&arrays[left],&arrays[right]);
        }

    }
    swap(&arrays[left],&arrays[length-2]);

    quickSort(arrays, left);
    quickSort(arrays+left+1, length-left-1);

}


int main(){

    int N;
    scanf("%d",&N);
    int arrays[10000] = {0};
    int index = 0;
    while(N--){
        scanf("%d",&arrays[index++]);
    }
    quickSort(arrays,index);
    for(int i=0; i<index; i++){
        printf("%d ",arrays[i]);

    }
    printf("\n");

	return 0;
}
