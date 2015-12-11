#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
char str1[50];
char *pstr1=&str1;
char str2[50];
char *pstr2=&str2;
char *pres;

printf("Enter first string: ");
gets(str1);
printf("Enter second string: ");
gets(str2);
pres=strstr(pstr1,pstr2);

    if(pres==NULL){
                printf ("\nSecond string isn`t a substring of the first one");}
    else{    printf ("\nSecond string is a substring of the first one \n");

}
int counter=1;
while(1){
    if(pres!=NULL)
        counter++;

    break;
}  printf("Number of entering : %i",counter);


return 0;




}

