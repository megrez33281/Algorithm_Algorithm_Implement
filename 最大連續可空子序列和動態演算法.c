#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define max(a,b) (a>b)?a:b



int main(){

    //相較於使用m[i]的演算法，去除掉了m[i]的記憶功能，使m隨著迴圈不斷跟新
    int N;
    scanf("%d",&N);
    int* arrays = (int*)calloc(N+1,sizeof(int));
    for(int i=1; i<=N; i++){
        scanf("%d",&arrays[i]);
    }

    int m = max(0,arrays[1]);
    int MCSS = m;   //由於m[i]帶表包含arrays[i]之最大連續數列和，故需要找到m[1]~m[9]之最大值及即MCSS
    printf("m = %d\n",m);
    printf("MCSS = %d\n",MCSS);
    for(int i=2; i<=N; i++){
        m = max(m + arrays[i], arrays[i]);
        m = max(m,0);   //與0比較，若m小於0，代表包含arrays[i]之連續最大子序列和<0，因此返回空子序列
        MCSS = max(MCSS,m);
        printf("#i = %d\n",i);
        printf("m[%d] = %d\n",i,m);
        printf("MCSS = %d\n",MCSS);
    }
    printf("\n\nMCSS = %d\n",MCSS);

    free(arrays);

	return 0;
}
