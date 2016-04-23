#ifndef DESIGNERS_H_INCLUDED
#define DESIGNERS_H_INCLUDED


typedef struct designer_s {
    int id;
    char name[256];
    char surname[256];
    char employment_date[15];
    double rating;
    int numOfCites;
    int salary;
}designer_t;

void designer_print(designer_t * st);
void designer_printList(designer_t * arr, int len);

#endif // DESIGNERS_H_INCLUDED


