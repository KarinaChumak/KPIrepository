#include <stdio.h>
#include <stdlib.h>


int main(){
int *pa;
    int a[2][3]={103,26,99,4,5,8};
 printf("%d %d %d\n", a[0][0], a[0][1], a[0][2]);
  printf("%d %d %d\n", a[1][0], a[1][1], a[1][2]);
  getchar();
pa=&a;

   int max = a[0][0];
    for (int i = 0; i < 2; i++) {
            for (int j=0;j<3; j++)
        if (*(*(a+i)+j) > max) {

            max = a[i][j];}}

printf ("max= %d", max);
  return 0;
}
