#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct point{
    int x;
    int y;
    int min;
};

struct pair{

    struct point A;
    struct point B;
    float d;

};

struct pair* nearlest(struct point* points,int start, int end){
    /*���禡�\�ର�N��J���}�C�̷�x�ȥѤp��j�ƦC��A�N�}�C�̷�x�������Ȥ�����b
      �åB�q�k�����}�C�����Z���̤p������I��Jpair���A�q�����}�C�����Z���̤p������I��Jpair��
      ���۹�񥪰��B�k���A���X�Z�����p��near
      �q�}�C������x�Ȧ�m���k�Unear.d���Z�����x�Ȧb��d�򤺤��I�A���ˬd�o���I���O�_���p��near.d�̡A�Y���h�Nnear�令�{�b�����I

    */

    if(end - start + 1 == 2){
        struct pair* near = (struct pair*)malloc(1*sizeof(struct pair));
        near->A.x = points[start].x;
        near->A.y = points[start].y;
        near->B.x = points[end].x;
        near->B.y = points[end].y;
        near->d = (float)pow((points[start].x - points[end].x)*(points[start].x - points[end].x) +  (points[start].y - points[end].y)*(points[start].y - points[end].y),0.5);
        //printf("(%d, %d) (%d, %d) d= %f\n",near->A.x,near->A.y,near->B.x,near->B.y,near->d);
        return near;
    }
    //�̷�x���j�p�Ѥp��j�Ƨ�
    for(int i=end; i >= start; i--){
        points[i].min = -1;
        for(int j=start+1; j<= end; j++){
            if(points[j].x < points[j-1].x){
                swap(&points[j],&points[j-1]);
            }
        }
    }

    //�o��x������
    int mid = (start + end)/2;
    float middle = ((end - start +1)%2 == 0)?(points[mid].x + points[mid+1].x)/2:points[mid].x;
    struct pair* Nleft = nearlest(points,start,mid);
    struct pair* Nright = nearlest(points,mid+1,end);
    struct pair* near;
    if(Nleft->d < Nright->d){
        near = Nleft;

    }
    else{
        near = Nright;
    }

    //���}�C�����O�_���̤p��
    int count = 0; //����x�ȶZ�������Ȥp���d��
    for(int i=start; i<=end; i++){
        if(abs(points[i].x - middle) <= near->d){
            points[i].min = 1;
        }
    }
    struct point** ptr = (struct points**)malloc(count*sizeof(struct point*));
    int index = 0;
    for(int i=start; i<end; i++){
        if(points[i].min == 1){
            ptr[index] = &points[i];
        }
    }
    //�ˬd�O�_����p���Z��
    for(int i=0; i<index; i++){
        for(int j=i+1; j<index; j++){
            float distance = (float)pow(((ptr[i]->x - ptr[j]->x)*(ptr[i]->x - ptr[j]->x) + (ptr[i]->y - ptr[j]->y)*(ptr[i]->y - ptr[j]->y)),0.5);
            if(distance < near->d){
                near->d = distance;
                near->A.x = ptr[i]->x;
                near->A.y = ptr[i]->y;
                near->B.x = ptr[j]->x;
                near->B.y = ptr[j]->y;
            }
        }

    }

    free(ptr);

    return near;
}

void swap(struct point* point1, struct point* point2){
    struct point temp;
    temp.x = point1->x;
    temp.y = point1->y;
    temp.min = point1->min;
    point1->x = point2->x;
    point1->y = point2->y;
    point1->min = point2->min;
    point2 -> x = temp.x;
    point2 -> y = temp.y;
    point2 -> min = temp.min;

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
        points[i].min = 0;

    }

    printf("min with conquer:\n");
    struct pair* near = nearlest(points,0,length-1);
    printf("(%d, %d) (%d, %d) distance=%f\n",near->A.x,near->A.y,near->B.x,near->B.y,near->d);
    printf("\n");

    printf("\nmax:\n");
    float distance = 999999;
    for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            float dis = (float)pow((points[i].x - points[j].x)*(points[i].x - points[j].x) +  (points[i].y - points[j].y)*(points[i].y - points[j].y),0.5);
            if(dis < distance){
                distance = dis;
            }
        }

    }

    printf("%f\n",distance);



    free(near);
	return 0;
}
