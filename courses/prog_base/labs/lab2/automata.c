#include<math.h>
#include<stdio.h>
#include<stdlib.h>
enum state{EMPTY, BREAK, RETURN, POP, CONTINUE, REPEAT};
int run(int moves[], int movesLen, int res[], int resLen);


int main(){
int moves[] = {10,208,28,18};
int i;
int movesLen = sizeof(moves)/sizeof(int);
int resLen=movesLen, order;
int res[resLen];
order=run(moves, movesLen, res, resLen);
for (i = 0; i < movesLen; i++){
printf("%d ", moves[i]);}
printf("\n");
for (i = 0; i < resLen; i++){
printf("%d ", res[i]);}
printf("\n");
printf(" Result is  %d ", order);
return 0;
}


int run(int moves[], int movesLen, int res[], int resLen){
int i,j;
for (i=0; i<resLen; i++)
res[i] = 0;
i=0;
j=0;int curState=0;
int curMove;
int fault;
int resNumbers=0;
int arr1[4][4]={
            {11,55,101,CONTINUE},
            {BREAK,POP,1,BREAK},
            {POP,5,REPEAT,11},
            {BREAK,BREAK,BREAK,2}};
int arr2[4][4]={
        {1,2,3,0},
        {EMPTY,1,2,EMPTY},
        {0,3,1,2},
        {EMPTY,EMPTY,EMPTY,1}};


while (1){
        printf("");
switch(moves[j]){
    case 10: curMove = 0; break;
    case 18: curMove = 1;break;
    case 28: curMove = 2; break;
    case 208: curMove= 3; break;
    default : fault = -1;break;
}
if (fault == -1)return resNumbers;
switch (arr1[curState][curMove]){
    case BREAK: return resNumbers;break;
    case POP:
        if (i>0){
            res[i-1] = 0;
            i--;
            j++;
            resNumbers--;
            curState=arr2[curState][curMove];
         }
         else return resNumbers;
         break;
         if (fault=1){break;}
    case REPEAT:curState=arr2[curState][curMove];break;
    case CONTINUE: j++;curState=arr2[curState][curMove];break;
    default:
res[i] = arr1[curState][curMove];
i++;
j++;
resNumbers++;
curState = arr2[curState][curMove];
break;
        }
}
return resNumbers;
}
