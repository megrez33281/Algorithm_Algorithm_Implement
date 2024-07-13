#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int MCSS(int* arrays, int start, int end){

    //找到陣列最大和之連續子序列
    if(start == end){
        //陣列長度為1時，其本身即為最大值
        return arrays[start];
    }
    //分割
    int mid = (start + end)/2;
    //左邊連續子序列和
    int left = MCSS(arrays,start,mid);
    //右邊
    int right = MCSS(arrays,mid+1,end);
    //此時已經得到陣列中左半部分陣列的最大和與右半部分陣列的最大和
    //從中間開始往左找最大的連續子序列和連續子序列和
    int midleft = -999;
    int sum = 0;
    for(int i=mid-1; i>=start; i--){
        sum += arrays[i];
        if(sum > midleft){
            midleft = sum;
        }
    }

    int midright = -999;
    sum = 0;
    for(int i=mid; i<=end; i++){
        sum += arrays[i];
        if(sum > midright){
            midright = sum;

        }

    }

    if(midright + midleft > left && midright + midleft > right){
        return midright + midleft;

    }
    else if(left > right){
        return left;
    }
    else{
        return right;
    }

}


int main(){

	int length = 9;

    int arrays[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max = MCSS(arrays,0,8);
    printf("%d\n",max);

	return 0;
}
