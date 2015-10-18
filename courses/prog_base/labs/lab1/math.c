#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc(double, double, double);

int main() {
    double xval = 5, yval = 2, zval = 1;
    double result;

    result = calc(xval, yval, zval);

    printf("%.12f", result);
    return 0;
}
double calc(double x, double y, double z)
 {
   double a;
   if((x!=y)&&(z!=0)&&(x!=0)&&(sin(y)!=0)&&(x>y))
    return  a=(pow(x,y+1))/(pow(x-y,1/z))+8*y+z/x+pow(x+1,1/fabs(sin(y)));
   else
      return NAN;
}
