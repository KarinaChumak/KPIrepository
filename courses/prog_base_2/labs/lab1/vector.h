#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED


typedef struct  vector_s vector_t;

vector_t * vector_new(int dimension);
void vector_free(vector_t * self);
vector_t * vector_setVector(vector_t * self);//random init
void vector_print(vector_t * self);
vector_t * vector_test(int i, int j);//Unit tests helper
void vector_input(vector_t * self);//user init


vector_t * vector_add(vector_t * self, vector_t * this);
vector_t * vector_mult_byNumber(vector_t * self, int number);
int vector_scalar_product(vector_t * self, vector_t * this);
double vector_findLength(vector_t * self);
double vector_find_angle(vector_t * self, vector_t * this);

//getters
vector_t * vector_getVector(vector_t * self);
int vector_getCoord(vector_t * self , int i);
int vector_getDimension(vector_t * self);

#endif //VECTOR_H_INCLUDED

