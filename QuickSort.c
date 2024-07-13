#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void quickSort(int* arrays,int length){

    int num = arrays[0];
    int left = 0;
    int right = length-1;

    if(length <= 1){return;}
    while(left < right){

        while(left < right &&  arrays[right] >= num){
            right--;
        }

        while(left < right && arrays[left] <= num){
            left++;

        }
        if(left < right){
            int temp = arrays[left];
            arrays[left] = arrays[right];
            arrays[right] = temp;
        }

    }

    arrays[0] = arrays[right];
    arrays[right] = num;

    quickSort(arrays,right);
    quickSort(arrays+right+1,length-right-1);

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
