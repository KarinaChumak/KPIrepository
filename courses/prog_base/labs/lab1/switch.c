#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int exec(int, int, int);

int main() {
    int opval = -2, aval = 49, bval = 11;
    int resultVal;

    resultVal = exec(opval, aval, bval);

    printf("%i", resultVal);
    return 0;
    }

int exec (int op, int a, int b)
{
int result;
int c;
c=a;
if(op<0) {op=-op; a=b ; b=c;}
 switch (op)
 {case 0: return -a;
  case 1: return a+b;
  case 2: return a-b;
  case 3: return a*b;
  case 4: return a/b;
  case 5: return abs(a);
  case 6: return pow(a,b);
  case 7:
  case 13:
  case 77: return a%b;
  case 8: return a<b? b:a;/*ÿךשמ a<b - ןנאגהא, גטגוסעט b ,ÿךשמ ם³-a*/
  case 9: return a<b? a:b;
  case 10:
    switch ( abs(b)%8)
     {case 0: return abs(a)*sizeof(char);/* 1 byte */
      case 1: return abs(a)*sizeof(signed char);/*1 byte */
      case 2: return abs(a)*sizeof(short);/* 2 bytes*/
      case 3: return abs(a)*sizeof(unsigned int);/*4 bytes */
      case 4: return abs(a)*sizeof(long);/*4 bytes*/
      case 5: return abs(a)*sizeof(unsigned long long);/*8 bytes */
      case 6: return abs(a)*sizeof(float);/*4 bytes */
      case 7: return abs(a)*sizeof(double);/*8 bytes */
      }
 case 11: if(b==0)
 return 0;
 else return floor(M_PI*((a+b)%11)/b);
 default:
 if(op<100)
 return (op % abs(a + 1)) + (op % abs(b + 1));
 else return -1;
 }
 return result;

}
