#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct koord {
    int x;
    int y;
};

struct rect {
    struct koord p1;
    int length;
    int height;
};


int main(){
struct rect rect1={5,12,16,10}, rect2=rect1;


printf("P1 (%i, %i)",rect2.p1.x , rect2.p1.y);
 printf("\nP2 (%i, %i)",rect2.p1.x,(rect2.p1.y+rect2.height));
 printf("\nP3 (%i, %i)",(rect2.p1.x+rect2.length) , rect2.p1.y);
 printf("\nP4 (%i, %i)",(rect2.p1.x+rect2.length) , (rect2.p1.y+rect2.height));
 printf("\nLenght = %i", rect2.length);
  printf("\nHeight = %i", rect2.height);


}

