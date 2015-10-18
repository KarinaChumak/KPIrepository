#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (){
long long x; //number
short S, i; //i - counter, S-sign
double F, R; // F-fraction, R - result
int E; // E - exponent
printf("Enter the long long number ");
scanf("%lli", &x);

    if ((x >> 63)==0){
    S = 0;
    E = (x >> 52);
    }
        else {
        S=1;
        E = abs((x >> 52)+1);
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
