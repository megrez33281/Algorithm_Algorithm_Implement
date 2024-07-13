#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define max(a,b) (a>b)?a:b



int main(){

    int N;
    scanf("%d",&N);
    int* arrays = (int*)calloc(N+1,sizeof(int));
    for(int i=1; i<=N; i++){
        scanf("%d",&arrays[i]);
    }
    int* m = (int*)calloc(N+1,sizeof(int));   //m[i]arrays[i]ぇ程硈尿计㎝
    m[1] = arrays[1];
    int MCSS = m[1];   //パm[i]盿arrays[i]ぇ程硈尿计㎝珿惠璶тm[1]~m[9]ぇ程のMCSS
    printf("m[1] = %d\n",m[1]);
    printf("MCSS = %d\n",MCSS);
    for(int i=2; i<=N; i++){
        m[i] = max(m[i-1] + arrays[i], arrays[i]);
        MCSS = max(MCSS,m[i]);
        printf("#i = %d\n",i);
        printf("m[%d] = %d\n",i,m[i]);
        printf("MCSS = %d\n",MCSS);
    }
    printf("\n\nMCSS = %d\n",MCSS);

    free(arrays);
    free(m);
	return 0;
}
