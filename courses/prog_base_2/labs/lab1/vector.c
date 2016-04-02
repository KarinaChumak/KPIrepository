
#include "vector.h"
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

struct vector_s{
  int dimension;//dimension of vector
   int *vector;
};

vector_t * vector_new(int  dimension){
    vector_t * V = malloc(sizeof(struct vector_s));
    V->vector =  (int *)malloc(dimension * sizeof(int));//?????????///
   V->dimension = dimension;
    return V;
}

vector_t * vector_getVector(vector_t * self){

    return self->vector;
}

int vector_getCoord(vector_t * self , int i){
return self->vector[i];
}

int vector_getDimension(vector_t * self){

    return self->dimension;
}


void vector_free(vector_t * self){
 if(self==NULL)
        return;
    free(self->vector);
    free(self);
}


vector_t * vector_test(int i, int j){
  vector_t * tmp = vector_new(2);
    tmp->vector[0]=i;
    tmp->vector[1]=j;

return tmp;
}

vector_t * vector_setVector(vector_t * self){
  for (int i = 0; i< self->dimension; i++){
    self->vector[i] = rand()%19-10;
  }
  return self;

}

void vector_print(vector_t * self){

  for (int i = 0; i< self->dimension; i ++)
  printf ("%4i,\n", self->vector[i]);

}

void vector_input(vector_t * self){
    for(int i = 0 ;i<self->dimension;i++){
        printf("Enter element on position [%i]",i );
        scanf("%i",&self->vector[i]);}
}

vector_t * vector_add(vector_t * self, vector_t * this){
    if (self->dimension != this->dimension){
        printf("Wrong dimension");
        return NULL;
    }
  else{
       vector_t * res = vector_new(self->dimension);
       for(int i=0; i <self->dimension; i++){
        res->vector[i] = self->vector[i] + this->vector[i];
       }

       return res;
  }
}


vector_t * vector_mult_byNumber(vector_t * self, int number){

        vector_t * res = vector_new(self->dimension);
        for(int i=0; i <self->dimension; i++){
        res->vector[i] = self->vector[i] * number;
       }

       return res;
}


int vector_scalar_product(vector_t * self, vector_t * this){
       if (self->dimension != this->dimension){
        printf("Wrong dimension");
        return 0;
    }

    else {
      int res = 0;
    for (int i = 0; i < self->dimension; i++){
            res += self->vector[i]*this->vector[i];

    }
    return res;
    }
}



double vector_findLength(vector_t * self){
    double res;
    for(int i = 0 ; i<self->dimension; i++)
    res += pow(self->vector[i],2);

    return sqrt(res);

}

double vector_find_angle(vector_t * self, vector_t * this){
    if (self->dimension != this->dimension){
        printf("Wrong dimension\n");
        return -1;
    }

    else {
    double angle = 0;
    angle = acos(vector_scalar_product(self, this)/(vector_findLength( self)*vector_findLength(this)));
return angle;
}
}

