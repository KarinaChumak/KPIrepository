#include <stdio.h>

typedef struct Designer designer;
designer * des_create();
void set_des(designer * d,char * name,char * surname, char * company, char * position,double rating);
void set_proj(designer * d,char * deadline,char * customer, int budget, int i);
void des_print(designer * d);
void des_free(designer * d);

