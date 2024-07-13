#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


int main(){

    int len = 9;
    int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int m=0;
    int max = -999999;
    for(int i=1; i<9; i++){
        m = (m + array[i] > array[i])?m + array[i]:array[i];
        if(m > max){
            max = m;
        }

    }
    printf("%d\n",max);


    return 0;
}
