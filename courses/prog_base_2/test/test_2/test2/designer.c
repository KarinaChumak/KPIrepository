
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "designer.h"

struct designer_s {
     int id;
    char name[256];
    char surname[256];
    char employment_date[15];
    double rating;
    int numOfCites;
    int salary;
};

designer_t * designer_new(void) {
    return malloc(sizeof(struct designer_s));
}

void designer_free(designer_t * self) {
    free(self);
}

void designer_set(designer_t * self, int id, char * name, char * surname, char * employment_date,  double rating, int numOfCities, int salary) {
    self->id = id;
    strcpy(self->name, name);
    strcpy(self->surname, surname);
    strcpy(self->employment_date, employment_date);
    self->rating = rating;
    self->numOfCites = numOfCities;
    self->salary = salary;
}


char * designer_getName(designer_t * self)
{
    return self->name;
}
