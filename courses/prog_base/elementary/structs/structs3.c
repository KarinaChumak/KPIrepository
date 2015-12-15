#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct koord {
    int x;
    int y;
};

struct rectangular {
    struct koord p1;
    int length;
    int height;
};

double area (struct rectangular *rect,int size);
int main (){
    struct rectangular rect[3]={5,3,28,10,    8,6,21,9,   7,12,10,2};
    for(int i=0;i<3;i++){
    printf(" Coordinates of first point :(%i,%i), length:%i, height:%i\n" , rect[i].p1.x, rect[i].p1.y, rect[i].length, rect[i].height );
    }


printf("Minimum area: %.0f", area(rect,3));
  return 0;
}

double area (struct rectangular *rect, int size){

 double minArea=0;
 double tmpArea=0;
 minArea=rect[0].length*rect[0].height;
 for(int i=1;i<size;i++){
     tmpArea=rect[i].length*rect[i].height;
    if (tmpArea<minArea)
        minArea=tmpArea;
 }
  return minArea;}
