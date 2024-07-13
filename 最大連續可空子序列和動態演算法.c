#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define max(a,b) (a>b)?a:b



int main(){

    //�۸���ϥ�m[i]���t��k�A�h�����Fm[i]���O�Х\��A��m�H�۰j�餣�_��s
    int N;
    scanf("%d",&N);
    int* arrays = (int*)calloc(N+1,sizeof(int));
    for(int i=1; i<=N; i++){
        scanf("%d",&arrays[i]);
    }

    int m = max(0,arrays[1]);
    int MCSS = m;   //�ѩ�m[i]�a��]�tarrays[i]���̤j�s��ƦC�M�A�G�ݭn���m[1]~m[9]���̤j�ȤΧYMCSS
    printf("m = %d\n",m);
    printf("MCSS = %d\n",MCSS);
    for(int i=2; i<=N; i++){
        m = max(m + arrays[i], arrays[i]);
        m = max(m,0);   //�P0����A�Ym�p��0�A�N��]�tarrays[i]���s��̤j�l�ǦC�M<0�A�]����^�Ťl�ǦC
        MCSS = max(MCSS,m);
        printf("#i = %d\n",i);
        printf("m[%d] = %d\n",i,m);
        printf("MCSS = %d\n",MCSS);
    }
    printf("\n\nMCSS = %d\n",MCSS);

    free(arrays);

	return 0;
}
