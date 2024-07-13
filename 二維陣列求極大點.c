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
    /*���禡�\�ର�N��J���}�C�̷�x�ȥѤp��j�ƦC��A�N�}�C�̷�x�������Ȥ�����b
      �åB�q�k�����}�C�����̤j��y��max�A�N�����}�C���Ҧ�y�Ȥp��max�̳]���^�O(���|�O���j�I)
      �ѩ󻼰j���S�ʡA�Ҧ��k�����I���I���|�Q�z��
    */

    if(start == end){
        return;
    }
    //�̷�x���j�p�Ѥp��j�Ƨ�
    for(int i=end; i >= start; i--){
        for(int j=start+1; j<= end; j++){
            if(points[j].x < points[j-1].x){
                swap(&points[j],&points[j-1]);
            }
        }
    }

    //�o�줤����
    int mid = (start + end)/2;
    rank(points,start,mid);
    rank(points,mid+1,end);

    //���k���}�C���̤j��y��
    int max=0; //��l�Ƭ��̤p��
    for(int i=mid+1; i<=end; i++){
        if(points[i].y > max){
            max = points[i].y;
        }
    }

    //�Y�����}�C�����I��y�Ȥp��}�C�k�������I���̤j��y�ȥN��䥲�w�|�Q�]�q�A�D���j�I
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
