#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define min(a,b) (a>b)?b:a

struct nearpoint{
    int loca;
    int locb;
    int d;
    int size;
};

struct nearpoint* nearest(int* points,int start, int end){
    if(end - start +1 <= 3){
        struct nearpoint near;
        if(end-start +1 == 2){
            struct nearpoint* nearest_list = (struct nearpoint*)calloc(1,sizeof(struct nearpoint));
            near.loca = points[start];
            near.locb = points[end];
            near.d = abs(points[start]-points[end]);
            near.size = 1;
            nearest_list[0] = near;
            return nearest_list;
        }
        else{
            int d = min(abs(points[start]-points[start+1]),min(abs(points[start]-points[start+2]), abs(points[start+1]-points[start+2])));
            struct nearpoint* nearest_list = (struct nearpoint*)calloc(3,sizeof(struct nearpoint));
            int index = 0;
            for(int i=start; i<=end; i++){
                for(int j=i+1; j<=end; j++){
                    if(abs(points[i]-points[j]) == d){
                        struct nearpoint near;
                        near.loca = points[i];
                        near.locb = points[j];
                        near.d = d;
                        nearest_list[index++] = near;
                    }
                }
            }
            nearest_list[0].size = index;
            return nearest_list;
        }
    }
    int middle = (end + start)/2;

    struct nearpoint* al = nearest(points,start,middle);
    struct nearpoint* ar = nearest(points,middle+1,end);
    int d = min(al[0].d,ar[0].d);
    struct nearpoint* TheNearest = (struct nearpoint*)calloc((al[0].size + ar[0].size+1),sizeof(struct nearpoint));
    //邊界判斷
    int mid_distance;
    struct nearpoint middle_near;
    mid_distance = abs(points[middle] - points[middle+1]); //由於points已經經過排列，points[middle]與points[middle+1]會為橫跨陣列之最近點對
    middle_near.loca = points[middle];
    middle_near.locb = points[middle+1];
    middle_near.d = mid_distance;
    middle_near.size = 1;
    if(mid_distance < d){

        TheNearest[0] = middle_near;
        free(al);
        free(ar);
        return TheNearest;
    }
    int index = 0;
    if(al[0].d == d){
        for(int i=0; i<al[0].size; i++){
            struct nearpoint near;
            near.d = al[i].d;
            near.loca = al[i].loca;
            near.locb = al[i].locb;
            near.size = al[i].size;
            TheNearest[index++] = near;
        }
    }
    if(ar[0].d == d){
        for(int i=0; i<ar[0].size; i++){
            struct nearpoint near;
            near.d = ar[i].d;
            near.loca = ar[i].loca;
            near.locb = ar[i].locb;
            near.size = ar[i].size;
            TheNearest[index++] = near;
        }
    }
    if(d == mid_distance){
        struct nearpoint near;
        near.d = middle_near.d;
        near.loca = middle_near.loca;
        near.locb = middle_near.locb;
        near.size = middle_near.size;
        TheNearest[index++] = near;
    }
    TheNearest[0].size = index;

    free(ar);
    free(al);

    return TheNearest;

}

int main(){

    int amounts;
    scanf("%d",&amounts);
    int* points = (int*)calloc(amounts,(sizeof(int)));
    for(int i=0; i<amounts; i++){
        int loc;
        scanf("%d",&loc);
        int j = i-1;
        while(j >= 0 && points[j] > loc){
            points[j+1] = points[j];
            j--;
        }
        points[j+1] = loc;
    }

    struct nearpoint* near = nearest(points,0,amounts-1);
    printf("distance=%d\n",near[0].d);
    for(int i=0; i<near[0].size; i++){
        printf("(%d,%d) ",near[i].loca,near[i].locb);
    }
    printf("\n");

    free(near);
    free(points);
    return 0;
}
