#include <stdio.h>
#include "Designers.h"

struct Project{
char deadline[15];
char customer[60];
int budget;
};
struct Designer{
char  name[15];
char  surname[15];
char  company[15];
char  position[15];
double rating;
struct Project design[2];
};

designer * des_create(){
designer * d = malloc(sizeof(struct Designer));
return d;
}


void set_des(designer * d,char * name,char * surname, char * company, char * position,double rating){
strcpy(d->name,name);
strcpy(d->surname,surname);
strcpy(d->company,company);
strcpy(d->position,position);
d->rating = rating;
}

void set_proj(designer * d,char * deadline,char * customer, int budget, int i){
strcpy(d->design[i].deadline,deadline);
strcpy(d->design[i].customer,customer);
d->design[i].budget = budget;
}

void des_print(designer * d){
printf("Name: %s, Surname: %s, Company: %s, Position: %s, Rating: %f ",d->name,d->surname,d->company,d->position,d->rating);
for (int i =0 ;i < 2; i++){
    printf("\nProject #%i, Deadline: %s, Customer: %s,  Budget: %d ",i+1,d->design[i].deadline,d->design[i].customer,d->design[i].budget);
}
printf("\n\n");
}

void des_free(designer * d){
free(d);
}


