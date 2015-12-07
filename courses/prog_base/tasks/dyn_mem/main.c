#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    char * buff = (char *)malloc(sizeof(char) * 100);
    int * n = (int *)malloc(sizeof(int));
    char * fSymbol = (char *)malloc(sizeof(char));
    char * fNumber = (char *)malloc(sizeof(char));
    char * sSymbol = (char *)malloc(sizeof(char));
    char * sNumber = (char *)malloc(sizeof(char));
    *n= 100;
    *fSymbol = -1;
    puts("Enter your string");
    fgets(buff, *n, stdin);
    for(*n = 0; *n < strlen(buff) - 1; (*n)++)
        if((isalpha(buff[*n]) && tolower(buff[*n])<='f' && tolower(buff[*n])>='a') || (isdigit(buff[*n])  && buff[*n]>='0' && buff[*n]<='9'))
        {
            *sSymbol = *n;
            if(*fSymbol==-1)
                *fSymbol = *n;
        }
    if(*fSymbol!=-1)
    {
        *fSymbol = tolower(buff[*fSymbol]);
        *sSymbol = tolower(buff[*sSymbol]);
        *fNumber = isdigit(*fSymbol) ? (*fSymbol - '0') : (10 + (*fSymbol) -  'a');
        *sNumber = isdigit(*sSymbol) ? (*sSymbol - '0') : (10 + (*sSymbol) -  'a');
        printf("The greatest number from %c(%i) and %c(%i) is %i", *fSymbol, *fNumber, *sSymbol, *sNumber, *fNumber > *sNumber ? *fNumber : *sNumber);
    }
    else
        puts("There is no 16-based symbols");
    free(buff);
    free(n);
    free(fSymbol);
    free(sSymbol);
    free(fNumber);
    free(sNumber);
    return EXIT_SUCCESS;
}
