#include<string.h>
#include <stdio.h>
#include <stdlib.h>
char *myStrncpy( char *dest, const char *src, size_t count );
int main (){
char str1[50];
printf("Enter your string: ");
gets(str1);
size_t size;
printf("Enter size of new string: ");
scanf("%",&size);
char str2[50];
printf("Your new string is: %s", myStrncpy(str2,str1,size));

}

char *myStrncpy(char *dest, const char *src, size_t size)
{
        int i;
        for (i = 0 ; i < size && src[i] != '\0' ; i++)
                dest[i] = src[i];
        if (i < size)
                dest[i] = '\0';
        return dest;
}


