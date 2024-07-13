#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


#define max(a,b) (a>b)?a:b

void PrintPath(char** arrays,int i, int j,char* str1, char* str2){
    if(i==0 || j==0){
        return;
    }

    if(arrays[i][j] == 'b'){ //'b'為both，表示當前str1[i] = str2[j]，為相同字元，需要輸出
        PrintPath(arrays,i-1,j-1,str1,str2);
        printf("%c ",str1[i]);
    }
    else if(arrays[i][j] == 'l'){
        PrintPath(arrays,i,j-1,str1,str2);
    }
    else if(arrays[i][j] == 'u'){
        PrintPath(arrays,i-1,j,str1,str2);

    }




}

int main(){
    char str1[100] = {};
    char str2[100] = {};

    //str1與str2的[0]表示從該字串選取之子字串長度為1
    str1[0] = 'X';
    str2[0] = 'X';

    gets(str1+1);
    gets(str2+1);
    int** lens = (int**)calloc(strlen(str1),sizeof(int*));
    for(int i=0; i<strlen(str1); i++){
        lens[i] = (int*)calloc(strlen(str2),sizeof(int));
    }
    char** direct = (char**)calloc(strlen(str1),sizeof(char*));
    for(int i=0; i<strlen(str1); i++){
        direct[i] = (char*)calloc(strlen(str2),sizeof(char));
    }
    for(int i=0; i<strlen(str1); i++){
        lens[i][0] = 0;
    }
    for(int i=0; i<strlen(str2); i++){
        lens[0][i] = 0;
    }
    //lens[i][j]表示字串1長度為i，字串2長度為j，兩字串的最長共同子序列
    //故當字串1的第i個字元 = 字串2的第j個字元，其len為 lens[i-1][j-1] + 1
    //若不等於，則lens[i][j]為lens[i-1][j]和lens[i][j-1]中最大者
    for(int i=1; i<strlen(str1); i++){
        for(int j=1; j<strlen(str2); j++){
            if(str1[i] == str2[j]){
                lens[i][j] = lens[i-1][j-1] + 1;
                direct[i][j] = 'b';

            }
            else if(lens[i][j-1] > lens[i-1][j]){
                lens[i][j] = lens[i][j-1];
                direct[i][j]='l';
            }
            else{
                lens[i][j] = lens[i-1][j];
                direct[i][j] = 'u';
            }

        }

    }
    printf("  ");
    for(int i=0; i<strlen(str2); i++){
        printf("%c ",str2[i]);
    }
    printf("\n");
    int index=0;
    for(int i=0; i<strlen(str1); i++){
        printf("%c ",str1[index++]);
        for(int j=0; j<strlen(str2); j++){
            printf("%d ",lens[i][j]);

        }
        printf("\n");
    }
    int i=strlen(str1)-1;
    int j=strlen(str2)-1;
    printf("\nThe longest length of substring is %d\n\n",lens[i][j]);

    //輸出最長共同子序列
    printf("The longest substring is ( ");
    PrintPath(direct,i,j,str1,str2);
    printf(")\n");

    free(direct);
    free(lens);

	return 0;
}
