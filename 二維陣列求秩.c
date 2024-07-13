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
    /*���禡�\�ର�N��J���}�C�̷�x�ȥѤp��j�ƦC��A�N�}�C�̷�x�������Ȥ�����b
      �åHy�q�C�찪�����ǹ�Ҧ��I�i��M���G
      ��l�Ocount=0�A�Y�J�쪺�I�p�󤤶��ȡA�hcount+1
      �Y�J�쪺�I�j�󵥩󶡭ȡA�h�N���I�����[�Wcount�s�^�h
      �G���禡���\�ର�N�}�C�̷Ӥ����Ȥ�����b�A�íp��k���}�C���Ȫ���
      �ѩ󻼰j���S�ʡA�Ҧ��ȳ��|�Q�p���
    */

    if(start == end){
        return;
    }
    //�̷�x���j�p�Ѥp��j�Ƨ�
    for(int i=end; i>=start; i--){
        for(int j=start+1; j<= end; j++){
            if(points[j].x < points[j-1].x){
                swap(&points[j],&points[j-1]);
            }
        }
    }

    //�o�줤����
    int mid = (start + end)/2;
    float midvalue = (end -start +1)%2 == 0?((float)points[mid].x + points[mid+1].x)/2:points[mid].x;
    rank(points,start,mid);
    rank(points,mid+1,end);

    //pointsy����Jpoints.y���Ѥp��j���Ǹ�
    int* pointsy = (int*)calloc(end - start + 1,sizeof(int));
    for(int i= start; i<= end; i++){
        pointsy[i-start] = i;
    }

    //�ϱopointsy�����Ʀr�X��points�ɥi�H�̷�points.y���j�p�Ѥp��j�ƦC
    //�ѩ�start���@�w�O0�A�X��pointsy�ɻݰ���j-start
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


    //���ɳz�Lpointsy�̷�points��y���ȥѤp��j�i��X��
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
