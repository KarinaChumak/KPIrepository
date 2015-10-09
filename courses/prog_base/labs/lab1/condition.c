#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int satisfies(int, int, int);

int main() {
    int aval = 0, bval = 0, cval = 0;
    int resultVal;

    resultVal = satisfies(aval, bval, cval);

    printf("%i", resultVal);
    return 0;}


int satisfies(int a, int b, int c) {
int result;
int modmin, sum2;
int min, max;

if (a<0&&b<0&&c<0){
 if((a<b&&b<=c)||(a<c && c<=b))
{modmin=abs(a);
sum2=b+c;}

  else  if ((b<a&&a<=c)||(b<c&&c<=a))
{modmin=abs(b);
sum2=a+c;}

  else  if((c<b&&b<=a)||(c<a&&a<=b))
{modmin=abs(c);
sum2=b+a;}
   if (sum2 < -256 && (log2(modmin)%1)=0 && modmin<256)
    result 1;
   if (((abs(sum2)-modmin)<16)||(abs(sum2)<16))
    result 1;
}
if ((a<0 && b>=0 && c>=0 && a> -256)
    || (b<0 && a>=0 && c>=0 && b> -256 )
    || (c<0 && a>=0 && b>=0 && c> -256)
    ||(a<0 && b<0 && c>=0 && 9*(a+b)>-256)
    ||(a<0 && c<0 && b>=0 && 9*(a+c)>-256)
    ||(b<0 && c<0 && a>=0 && 9*(b+c)>-256))
   {result 1;}


if (a>b && b>c && c>=0)
    {max=a;
     min=c;}

if (b>a && a>c && c>=0)
{min=c;
max=b;}

if (c>a && a>b &&b>=0)
{max=c;
min=b;}

if (a>c && c>b && b>=0)
{min=b;
max=a;}

if (b>c && c>a && a>=0)
{min=a;
max=b;}

if (c>b && b>a && a>=0)
{min=a;
max=c;}

if (max%min=0)
 result 1;
if (min=0)
    result 0;
 else result 0;

   return result;
}




