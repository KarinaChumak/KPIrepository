#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include "vector.h"

typedef struct  matrix_s matrix_t;

matrix_t * matrix_new(int columns, int rows);
void matrix_free(matrix_t * self);
matrix_t * matrix_setMatrix(matrix_t * self);
void matrix_print(matrix_t * self);
matrix_t * matrix_setMatrix(matrix_t * self);//random initializer
void matrix_input(matrix_t * self);//user initialization

//operations
matrix_t * matrix_transpos(matrix_t * self);
matrix_t * matrix_add(matrix_t * self, matrix_t * this);
matrix_t * matrix_sub(matrix_t * self, matrix_t * this);
matrix_t * matrix_mult(matrix_t * self, matrix_t * this);
matrix_t * matrix_transpos(matrix_t * self);
matrix_t * matrix_mult_vector(matrix_t * self, vector_t * this);

//getters
int matrix_getColumns(matrix_t * self);
int matrix_getRows(matrix_t * self);
int matrix_getElementOfMatrix(matrix_t *self,int i, int j);//Unit-tests helper

matrix_t * matrix_test(int i, int j, int k,int l);//Unit-tests helper

#endif // MATRIX_H_INCLUDED

