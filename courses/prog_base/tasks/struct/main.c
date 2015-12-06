#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    char name[100];

    int length;
} Episode;
int count(int size, Episode arr[size])
{
    int i, count = 0;
    for(i = 0; i < size; i++)
        if(arr[i].length > 30)
            count++;
    return count;
}
void change(Episode * pVar, const char * newValue)
{
    strcpy(pVar->name, newValue);
}

void print(Episode * pVar)
{
    printf("Episode name: %s\nLength : %i\n", pVar->name,  pVar->length);
}
int main(void)
{
    int i;
    char buff[100];
    int status = 0;
    time_t t;
    system("mode con: lines=30");
    srand((unsigned) time(&t));
    Episode eps[3] = {{"How i met your mother",  rand()%60 + 1}, {"The Mentalist", rand()%60 + 1}, {"White collar",  rand()%60 + 1}};
    printf("There are %i episodes which are longer that 30 minutes\n\n", count(3, eps));
    puts("Episodes : \n");
    for(i = 0; i < 3; i++)
    {
        print(&eps[i]);
        puts("");
    }
    while(status!=1)
    {
        puts("\nEnter the index of the element which you want to change(0..2)");
        fgets(buff, 100, stdin);
        status = sscanf(buff, "%i", &i);
        if(i > 2 || i < 0)
            status--;
    }
    change(&eps[i], "Friends");
    puts("Changed episode : \n");
    print(&eps[i]);
    return EXIT_SUCCESS;
}
