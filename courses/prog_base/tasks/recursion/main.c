#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
int checksVowels(char c)
{
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    else
        return 0;
}
int countsVowels(char * str, size_t stringLength)
{
    if(stringLength==0)
        return 0;
    else
        return checksVowels(*str) + countsVowels(str + 1, stringLength-1);
}
int main(void)
{
    char str[100];
    puts("Enter the string : ");
    gets(str);
    printf("Number of vowels:%i ", countsVowels(str, strlen(str)));
    return EXIT_SUCCESS;
}
