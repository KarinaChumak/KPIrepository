#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
char str[50];
char ch;
 char *pch=&ch;
printf("Enter your string: ");
gets (str);
printf("Enter your character: ");
ch=getchar();


pch=strchr(str,ch);
    if(pch==NULL)
        printf ("This string doesn`t contain such character");
    else
        printf ("This string contains such character");


return 0;




}

