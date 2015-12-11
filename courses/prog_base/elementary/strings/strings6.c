#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char *p;
    char str[50] ;
    printf("Enter your string");
    gets(str);
    char space[] = " ";

    p = strtok(str, space);
    while(p != NULL){
        puts(p);
        p = strtok(NULL, space);
    }



return 0;
}

