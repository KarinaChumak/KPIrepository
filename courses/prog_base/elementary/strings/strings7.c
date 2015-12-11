#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char *p;
    char str[50] ;
    printf("Enter your string");
    gets(str);
    char div[] = " ,.";

    p = strtok(str, div);
    while(p != NULL){
        puts(p);
        p = strtok(NULL, div);
    }


return 0;
}

