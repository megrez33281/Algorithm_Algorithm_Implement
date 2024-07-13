#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int MaxSet(int* array, int start, int end){

    if(start == end){
        return array[start];
    }

    //¤À³Î
    int mid = (end+start)/2;
    int leftMax = MaxSet(array,start,mid);
    int rightMax = MaxSet(array,mid+1,end);

    //Ãä»Ú§PÂ_
    //¥ª°¼
    int left = -99999;
    int index = mid;
    int sum =  0;
    while(index >= start){
        sum += array[index--];
        if(sum > left){
            left = sum;
        }
    }

    //¥k°¼
    int right = -99999;
    index = mid+1;
    sum = 0;
    while(index <= end){
        sum += array[index++];
        if(sum > right){
            right = sum;
        }

    }

    int middle = left + right;

    if(leftMax > rightMax && leftMax > middle){
        return leftMax;
    }
    else if(rightMax > leftMax && rightMax > middle ){
        return rightMax;
    }
    else{
        return middle;
    }
}

int main(){

    int len = 9;
    int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sum = MaxSet(array,0,len-1);

    printf("%d\n",sum);

    return 0;
}
