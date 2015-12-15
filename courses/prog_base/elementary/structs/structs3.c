#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//як викликати функц≥ю в main?? якщо пишу так,€к закоментовано, видаЇ помилку "conflicting types"
//double area (struct rectangular *rect);

struct koord {
    int x;
    int y;
};

struct rectangular {
    struct koord p1;
    int length;
    int height;
};


int main (){
    struct rectangular rect[3]={5,3,28,10,    8,6,21,9,   7,12,10,2};
    for(int i=0;i<3;i++){
    printf(" Coordinates of first point :(%i,%i), length:%i, height:%i\n" , rect[i].p1.x, rect[i].p1.y, rect[i].length, rect[i].height );
    }
/*int i;
area(&rect[i]);*/

double res;
 for(int i=0;i<3;i++){
 res=rect[i].length*rect[i].height;
 printf("%darea = %.0f; ", i+1, res );
 }
 double minArea=0;
 for(int i=1;i<3;i++){
     minArea=rect[0].length*rect[0].height;
    if (rect[i].length*rect[i].height<rect[0].length*rect[0].height)
        minArea=rect[i].length*rect[i].height;
 }
  printf("\nMinimal area = %.0f; ",  minArea );


  return 0;
}


/*double area (struct rectangular *rect){
 double res;
 for(int i=0;i<3;i++){
 res=rect[i].length*rect[i].height;
 printf("%darea = %.0f; ", i+1, res );


}*/

