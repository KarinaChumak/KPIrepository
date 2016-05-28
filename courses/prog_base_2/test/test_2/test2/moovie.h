
#ifndef quote_H_INCLUDED
#define quote_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct moovie_s moovie_t;

moovie_t * moovie_new();
void moovie_free(moovie_t * self);
void moovie_set(moovie_t * self,char * moovie,int year);
char * moovie_toJSON(moovie_t * self);
#endif // quote_H_INCLUDED
