#include <stdlib.h>
#include "matrix.h"
#include "vector.h"

struct matrix_s{
  int columns;//number of rows and columns;
  int rows;
  int **matrix;
};


int matrix_getColumns(matrix_t * self){
    return self->columns;

}
int matrix_getRows(matrix_t * self){
    return self->rows;
}


int matrix_getElementOfMatrix(matrix_t *self,int i, int j){

return self->matrix[i][j];

}

matrix_t * matrix_new(int columns, int rows){
    matrix_t * M = malloc(sizeof(struct matrix_s));
    M->matrix =  (int **)malloc(columns * sizeof(int *));
        for(int i=0; i<columns ;i++){
    M->matrix[i] = malloc(sizeof(int)*rows);
    }
    M->columns = columns;
    M->rows = rows;
    return M;
}


void matrix_free(matrix_t * self) {
    if(self==NULL)
        return;
    free(self->matrix);
    free(self);
}




matrix_t * matrix_setMatrix(matrix_t * self){
        srand(time(NULL));
    for(int i = 0; i<self->columns; i++)
    {
        for(int j=0; j<self->rows; j++)
        {
            self->matrix[i][j] = rand()%10-2;
        }
    }
    return self;
}



void matrix_print(matrix_t * self) {
    if(self == NULL)
{
    return 1;
}

else{
        int i, j;
    for (i = 0; i < self->rows; i++)
     {
        printf("\n{");
        for (j = 0; j < self->columns; j++) {
            printf("%3i, ",self->matrix[i][j]);
        }
        printf("}");
    }
    return 0;}
}


matrix_t * matrix_add(matrix_t * self, matrix_t * this){

     if ((self->columns != this->columns)||(self->rows != this->rows)){
       printf("Error. Wrong dimension of matrix");
        return NULL;
     }
     else{
        matrix_t * res = matrix_new(self->columns,self->rows);
   for (int i = 0; i<self->columns; i++){
    for (int j = 0; j<self->rows; j++)
        res->matrix[i][j] = self->matrix[i][j] + this->matrix[i][j];

   }

     return res;
     }
}


matrix_t * matrix_sub(matrix_t * self, matrix_t * this){

     if ((self->columns != this->columns)||(self->rows != this->rows)){
       printf("Error. Wrong dimension of matrix");
        return NULL;
     }
     else{
        matrix_t * res = matrix_new(self->columns,self->rows);
   for (int i = 0; i<self->columns; i++){
    for (int j = 0; j<self->rows; j++)
        res->matrix[i][j] = self->matrix[i][j] - this->matrix[i][j];

   }


     return res;
     }
}

matrix_t * matrix_mult(matrix_t * self, matrix_t * this){
     if (self->rows != this->columns){
       printf("Error. Wrong dimension of matrix");
        return NULL;
     }
     else {
            matrix_t * res = matrix_new(self->columns,self->rows);

    for (int i = 0; i<self->columns; i++){
    for (int j = 0; j<this->rows; j++){
            res->matrix[i][j] = 0;
    for (int k = 0; k < self->rows; k++)
        res->matrix[i][j] += self->matrix[i][k] * this->matrix[k][j];

     }}
     return res;

}}


matrix_t * matrix_mult_byNumber(matrix_t * self, int number){

        matrix_t * res = matrix_new(self->columns,self->rows);
        for (int i = 0; i<self->columns; i++)
    for (int j = 0; j<self->rows; j++)
        res->matrix[i][j] = self->matrix[i][j]*number;
        return res;

}

matrix_t * matrix_transpos(matrix_t * self){
 matrix_t * res = matrix_new(self->rows, self->columns);
  for (int i = 0; i< self->rows; i ++){
    for (int j = 0; j<self->columns; j++){
        res->matrix[i][j] = self->matrix[j][i];
    }

  }
    res->columns = self->rows;
    res->rows = self->columns;
    return res;

}



matrix_t * matrix_mult_vector(matrix_t * self, vector_t * this){
    int dimension = vector_getDimension(this);
    if(self->rows != dimension){
        printf("Impossible to multiply");
        return NULL;
    }
else{
    matrix_t * res = matrix_new(self->rows, self->columns);
   int * vec = vector_getVector(this);
    for (int i = 0; i<self->rows;i++)
    for(int j = 0;j<self->columns;j++){
        res->matrix[i][j] = self->matrix[i][j]*vec[i];
    }
    return res;}
}


void matrix_input(matrix_t * self){
    for(int i = 0 ;i<self->rows;i++)
    for (int j = 0; j<self->columns; j++){
        printf("Enter element on position [%i][%i]",i,j );
        scanf("%i",&self->matrix[i][j]);}
}

matrix_t * matrix_test(int i, int j, int k,int l){
   matrix_t * tmp = matrix_new(2,2);
    tmp->matrix[0][0]=i;
    tmp->matrix[0][1]=j;
    tmp->matrix[1][0]=k;
    tmp->matrix[1][1]=l;
return tmp;
}

