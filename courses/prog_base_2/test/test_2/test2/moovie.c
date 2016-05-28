#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "moovie.h"
#include "cJSON.h"

struct moovie_s
{
    char moovie[50];
    int year;
    char date[50];
};

moovie_t * moovie_new()
{
    moovie_t * self = malloc(sizeof(struct moovie_s));
    return self;
}

void moovie_free(moovie_t * self)
{
    free(self);
}

void moovie_set(moovie_t * self,char * moovie,int year)
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strcpy(self->moovie,moovie);
   self->year=year;
    char * time = asctime(timeinfo);
    time[strlen(time)-1] = '\0';
    strcpy(self->date,time);
}

char * moovie_toJSON(moovie_t * self)
{
    cJSON * jQuote = cJSON_CreateObject();
    cJSON_AddItemToObject(jQuote, "moovie", cJSON_CreateString(self->moovie));
    cJSON_AddItemToObject(jQuote, "year", cJSON_CreateNumber(self->year));
    cJSON_AddItemToObject(jQuote, "time", cJSON_CreateString(self->date));

    char * jsonString = cJSON_Print(jQuote);
    return jsonString;
}


