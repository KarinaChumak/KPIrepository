#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
char str[50] ;
    printf("Enter your string: ");
    gets(str);
int counter=0;
for(int i=0;i<strlen(str);i++){
if(isdigit(str[i]))
counter++;
}
printf("%i",counter);}
