#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef int (*IteratorCallback)(int);
int overCB(int number);
int underCB(int number);
int loop(IteratorCallback cb,  int number, int * size);
