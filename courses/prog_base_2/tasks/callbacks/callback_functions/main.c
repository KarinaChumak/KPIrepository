#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

#include "callbacks.h"



int overCB(int number){
    printf("%i >K \n", number);
    return number;
}

int underCB(int number){
    printf("%i <L\n", number);
    return number;
}

int loop(IteratorCallback cb,  int number, int * size){
    (*size)++;
    return cb(number);
}

int main(){
    int N,L,K;
    int * over;
    int * under;
    int x=0, y=0;

    over = &x;
    under = &y;

     printf("Press any button to exit the loop \n");

    srand(time(NULL));
    printf("Enter positive integer N : ");
    scanf("%i", &N);


    if (N<0){
        printf("Error: N < 0");
        return 1;
    }

    printf("Enter positive integer K, which is less than N : ");
    scanf("%i", &K);

    if (K<0){
        printf("Error: K < 0");
        return 1;
    }

    if (K>N){
        printf("Error: K > N");
        return 1;
    }

    printf("Enter positive integer L which is less than K : ");
    scanf("%i", &L);

    if (L<0){
        printf("Error: L < 0");
        return 1;
    }
    if (L>K){
        printf("Error: L > K");
        return 1;
    }

    int number;
    while(kbhit()==0){
        number = (rand() % (2*N)- 0) - N;

        if (number<L){
            loop(underCB, number, under);
        }

        if (number>K){
            loop(overCB, number, over);
        }

    }


    printf("\nOver: %i\n Under: %i \n", *over, *under);
    system("pause");
    return 0;
}
