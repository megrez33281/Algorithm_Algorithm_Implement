#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct point{
    int x;
    int y;
    int pivots;
};

void rank(struct point* points,int start, int end){
    /*此函式功能為將輸入的陣列依照x值由小到大排列後，將陣列依照x之中間值分成兩半
      並以y從低到高的順序對所有點進行遍歷：
      初始令count=0，若遇到的點小於中間值，則count+1
      若遇到的點大於等於間值，則將該點之秩加上count存回去
      故此函式之功能為將陣列依照中間值分成兩半，並計算右側陣列中值的秩
      由於遞迴的特性，所有值都會被計算到
    */

    if(start == end){
        return;
    }
    //依照x的大小由小到大排序
    for(int i=end; i>=start; i--){
        for(int j=start+1; j<= end; j++){
            if(points[j].x < points[j-1].x){
                swap(&points[j],&points[j-1]);
            }
        }
    }

    //得到中間值
    int mid = (start + end)/2;
    float midvalue = (end -start +1)%2 == 0?((float)points[mid].x + points[mid+1].x)/2:points[mid].x;
    rank(points,start,mid);
    rank(points,mid+1,end);

    //pointsy中放入points.y的由小到大之序號
    int* pointsy = (int*)calloc(end - start + 1,sizeof(int));
    for(int i= start; i<= end; i++){
        pointsy[i-start] = i;
    }

    //使得pointsy中的數字訪問points時可以依照points.y之大小由小到大排列
    //由於start不一定是0，訪問pointsy時需偏移j-start
    for(int i=end; i>=start; i--){
        for(int j=start+1; j<=i; j++){
            int indexI = pointsy[j-start];
            int indexII = pointsy[j-start-1];
            if(points[indexI].y < points[indexII].y){
                int temp = pointsy[j-start];
                pointsy[j-start] = pointsy[j-start-1];
                pointsy[j-start-1] = temp;
            }
        }
    }


    //此時透過pointsy依照points的y之值由小到大進行訪問
    int count = 0;
    for(int i=start; i<=end; i++){
        int index = pointsy[i-start];
        if(points[index].x < midvalue){
            count++;
        }
        else{
            points[index].pivots += count;
        }

    }
    free(pointsy);
}

void swap(struct point* point1, struct point* point2){
    struct point temp;
    temp.x = point1->x;
    temp.y = point1->y;
    temp.pivots = point1->pivots;
    point1->x = point2->x;
    point1->y = point2->y;
    point1->pivots = point2->pivots;
    point2 -> x = temp.x;
    point2 -> y = temp.y;
    point2 -> pivots = temp.pivots;

}

int main(){
    //(1, 4), (2, 2), (3, 5), (4, 8), (5, 6), (6, 3), (7, 9), (8, 7)
    //(1, 4), (2, 2), (3, 5), (4, 8)   (5, 6), (6, 3), (7, 9), (8, 7)
    //(1, 4), (2, 2)   (3, 5), (4, 8)   (5, 6), (6, 3)   (7, 9), (8, 7)
    //(1, 4)    (2, 2)    (3, 5)   (4, 8)    (5, 6)    (6, 3)   (7, 9)    (8, 7)
    //

    int length = 7;
    struct point points[length];
    int x[] = {1,2,3,4,5,6,8};
    int y[] = {4,2,5,8,6,3,7};
    for(int i=0; i<length; i++){
        points[i].x = x[i];
        points[i].y = y[i];
        points[i].pivots = 0;

    }

    printf("rank with conquer:\n");
    rank(points,0,length-1);
    for(int i=0; i<length; i++){
        printf("(%d, %d) rank=%d\n",points[i].x,points[i].y,points[i].pivots);

    }

    printf("\nrank:\n");
    for(int i=0; i<length; i++){
        int count = 0;
        for(int j=0; j<length; j++){
            if(points[i].x > points[j].x && points[i].y > points[j].y){
                count++;
            }

        }
        printf("(%d, %d) rank=%d\n",points[i].x,points[i].y,count);

    }




	return 0;
}
