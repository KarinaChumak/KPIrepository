#ifndef DESIGNER_H_INCLUDED
#define DESIGNER_H_INCLUDED

typedef struct designer_s  designer_t;
designer_t * designer_new(void);
void designer_free(designer_t * self);
void designer_set(designer_t * self, int id, char * name, char * surname, char * employment_date,  double rating, int numOfCities, int salary);
char * designer_getName(designer_t * self);

#endif // DESIGNER_H_INCLUDED



