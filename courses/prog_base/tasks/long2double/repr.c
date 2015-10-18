#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double long2double (long long);
int main (){
long long x; //x
printf("%.325llf",long2double(x));
}

double long2double (long long x)
{
short S,j, i; //i - counter, S-sign
double F=0, R, E=0; // F-fraction, R - result,E - exponent

printf("Enter the long long number ");
scanf("%lli", &x);

   S=(x>>63)&1;
for (j=52;j<63;++j) {
        E+=((x>>j)&1)*(pow(2,(j-52)));
        }
for (i = 51; i >= 0; i--) {
F+=((( x >> i)&1)*(pow(2, i - 52)));
}
    if ((E == 2047) && (F!=0.0)) return printf ("NaN");
    if ((E == 2047) && (F == 0.0) && (S == 1) )return printf ("-Infinity");
    if ((E == 2047) && (F == 0.0) && (S == 0))return printf (" Infinity");
    if ((E > 0) && (E <2047)) {R = (pow(-1,S)* pow(2,E-1023)*(1+F));
    printf("%.20llf", R);}
    if ((E == 0) && (F !=0.0)) {R = (pow(-1, S)* pow(2, -1022)*(F));
    printf("%.325llf", R);}
    if ((E == 0) && (F == 0.0) && (S == 1))return printf("-0");
    if ((E == 0) && (F == 0.0) && (S == 0)) return printf (" 0");

    }
