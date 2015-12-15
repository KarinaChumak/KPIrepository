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
} ;


int main(){
struct rect rectangular = {2,3,7,4};
 printf("P1 (%i, %i)",rectangular.p1.x , rectangular.p1.y);
 printf("\nP2 (%i, %i)",rectangular.p1.x,(rectangular.p1.y+rectangular.height));
 printf("\nP3 (%i, %i)",(rectangular.p1.x+rectangular.length) , rectangular.p1.y);
 printf("\nP4 (%i, %i)",(rectangular.p1.x+rectangular.length) , (rectangular.p1.y+rectangular.height));
 printf("\nLenght = %i", rectangular.length);
  printf("\nHeight = %i", rectangular.height);
return 0;
}
