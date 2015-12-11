
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char str2[50] ;
printf("Enter your string: ");
    gets(str2);
for(int i=0;i<strlen(str2);i++)

 if ( tolower(str2[i]) == str2[i] )
          str2[i] = toupper (str2[i]);
    else
          str2[i] = tolower(str2[i]);
printf (" %s \n", str2);
return 0;
}
