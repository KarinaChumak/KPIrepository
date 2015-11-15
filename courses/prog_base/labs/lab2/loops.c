#include <math.h>
#include <stdlib.h>
#include "stdio.h"
double calc(int n, int m);
int main(){
    int n=0,m=0;
    printf("Enter n ");
    scanf("%d", &n);
    printf("Enter m ");
     scanf("%d", &m);
    printf("x = %f", calc(n,m));
}
double calc(int n, int m)
{
int i,j,x=0;
int n1=1;
    for (i=0; i<=n; i++){
  for (j=0; j<=m; j++)
  {
  x += sqrt(i+(n1+2)*j);
  }

    }
    return x;
}
