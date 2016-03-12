#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct list_s list_t;


list_t * list_new(void);//constructor
void list_free(list_t * this);//destructor

int list_getCount(list_t * this);//getter

int list_positive(list_t * this);
int list_negative(list_t * this);
int list_zeros(list_t * this);

void list_add(list_t * this,int index, int value);
void list_delete(list_t * this, int index);
#endif // LIST_H_INCLUDED
