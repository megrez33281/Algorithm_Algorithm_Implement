#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct point{
    int x;
    int y;
    int max;
};

void rank(struct point* points,int start, int end){
    /*此函式功能為將輸入的陣列依照x值由小到大排列後，將陣列依照x之中間值分成兩半
      並且從右側的陣列中找到最大的y值max，將左側陣列中所有y值小於max者設為淘汰(不會是極大點)
      由於遞迴的特性，所有右側有點的點都會被篩選
    */

    if(start == end){
        return;
    }
    //依照x的大小由小到大排序
    for(int i=end; i >= start; i--){
        for(int j=start+1; j<= end; j++){
            if(points[j].x < points[j-1].x){
                swap(&points[j],&points[j-1]);
            }
        }
    }

    //得到中間值
    int mid = (start + end)/2;
    rank(points,start,mid);
    rank(points,mid+1,end);

    //找到右側陣列中最大的y值
    int max=0; //初始化為最小值
    for(int i=mid+1; i<=end; i++){
        if(points[i].y > max){
            max = points[i].y;
        }
    }

    //若左側陣列中的點之y值小於陣列右側中的點之最大之y值代表其必定會被包裹，非極大點
    for(int i=start; i<=mid; i++){
        if(points[i].y < max){
            points[i].max = -1;

        }

    }
}

void swap(struct point* point1, struct point* point2){
    struct point temp;
    temp.x = point1->x;
    temp.y = point1->y;
    temp.max = point1->max;
    point1->x = point2->x;
    point1->y = point2->y;
    point1->max = point2->max;
    point2 -> x = temp.x;
    point2 -> y = temp.y;
    point2 -> max = temp.max;

}

int main(){
    //(1, 4), (2, 2), (3, 5), (4, 8), (5, 6), (6, 3), (7, 9), (8, 7)
    //(1, 4), (2, 2), (3, 5), (4, 8)   (5, 6), (6, 3), (7, 9), (8, 7)
    //(1, 4), (2, 2)   (3, 5), (4, 8)   (5, 6), (6, 3)   (7, 9), (8, 7)
    //(1, 4)    (2, 2)    (3, 5)   (4, 8)    (5, 6)    (6, 3)   (7, 9)    (8, 7)
    //

    int length = 8;
    struct point points[length];
    int x[] = {1,2,3,4,5,6,7,8};
    int y[] = {4,2,5,8,6,3,9,7};
    for(int i=0; i<length; i++){
        points[i].x = x[i];
        points[i].y = y[i];
        points[i].max = 1;

    }

    printf("max with conquer:\n");
    rank(points,0,length-1);
    for(int i=0; i<length; i++){
        if(points[i].max == 1){
            printf("(%d, %d )",points[i].x,points[i].y);
        }

    }
    printf("\n");

    printf("\nmax:\n");
    for(int i=0; i<length; i++){
        int count = 0;
        for(int j=0; j<length; j++){
            if(points[i].x < points[j].x && points[i].y < points[j].y){
                count++;
            }

        }
        if(count == 0){
            printf("(%d, %d) ",points[i].x,points[i].y,count);}
    }
    printf("\n");




	return 0;
}
