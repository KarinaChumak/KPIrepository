#include <stdlib.h>
#include <stdio.h>

int SampleAddInt(int i1, int i2)
{
    printf("SampleAddInt called!");
    return i1 + i2;
}

void SampleFunction1(void)
{
    printf("SampleFunction1 called!");
}

int SampleFunction2(void)
{
    printf("SampleFunction2 called!");
    return 0;
}
