#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>

#include <cmocka.h>


#include "matrix.h"
#include "vector.h"

/*
int main(void)
{


printf("\n");
     vector_t * vec1 = vector_test(3,4);
    vector_print(vec1);

    printf("\n");



    vector_t * vec2 = vector_test(3,4);
    vector_print(vec2);


  printf("\n");
  printf("%f\n",vector_find_angle(vec1,vec2));
vector_free(vec1);
vector_free(vec2);


}*/

//matrix_new
static void matrix_new_fourColumnsAndThreeRows_fourCountColumnsThreeCountRows(void **state)
{
    matrix_t * mat1 = matrix_new(4,3);
    assert_int_equal(matrix_getColumns(mat1), 4);
    assert_int_equal(matrix_getRows(mat1), 3);
    matrix_free(mat1);
}
//matrix_add
static void matrix_add_TwoMatrixesWithElementsOneTwoThreeFour_MatrixWithElementsTwoFourSixEight(void ** state)
{
    matrix_t * mat1 =matrix_test(1,2,3,4);
    matrix_t * mat2 =matrix_test(1,2,3,4);
    assert_int_equal(matrix_getElementOfMatrix(matrix_add(mat1,mat2),0,0),2);
    assert_int_equal(matrix_getElementOfMatrix(matrix_add(mat1,mat2),0,1),4);
    assert_int_equal(matrix_getElementOfMatrix(matrix_add(mat1,mat2),1,0),6);
    assert_int_equal(matrix_getElementOfMatrix(matrix_add(mat1,mat2),1,1),8);

    matrix_free(mat1);
    matrix_free(mat2);
}
//matrix_sub
static void matrix_sub_TwoMatrixesWithElementsSixTenTwoElevenAndOneTwoThreeFour_MatrixWithElementsFiveEightMinusOneSeven(void ** state)
{
    matrix_t * mat1 = matrix_test(6,10,2,11);
    matrix_t * mat2 = matrix_test(1,2,3,4);
    assert_int_equal(matrix_getElementOfMatrix(matrix_sub(mat1,mat2),0,0),5);
    assert_int_equal(matrix_getElementOfMatrix(matrix_sub(mat1,mat2),0,1),8);
    assert_int_equal(matrix_getElementOfMatrix(matrix_sub(mat1,mat2),1,0),-1);
    assert_int_equal(matrix_getElementOfMatrix(matrix_sub(mat1,mat2),1,1),7);

    matrix_free(mat1);
    matrix_free(mat2);
}


//multiplication of two matrixes
static void matrix_mult_TwoMatrixesWithElementsOneTwoThreeFour_TwoMatrixesWithElementsSevenTenFifteenTwentytwo(void ** state)
{
    matrix_t * mat1 = matrix_test(1,2,3,4);
    matrix_t * mat2 = matrix_test(1,2,3,4);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult(mat1,mat2),0,0),7);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult(mat1,mat2),0,1),10);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult(mat1,mat2),1,0),15);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult(mat1,mat2),1,1),22);

    matrix_free(mat1);
    matrix_free(mat2);

}

//multiplication matrix on number
static void matrix_mult_byNumber_MatrixWithElementsFiveTenFifteenTwenty(void**state)
{


    matrix_t * mat1 = matrix_test(1,2,3,4);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_byNumber(mat1,5),0,0),5);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_byNumber(mat1,5),0,1),10);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_byNumber(mat1,5),1,0),15);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_byNumber(mat1,5),1,1),20);


    matrix_free(mat1);
}
//multiplication matrix on vector
static void matrix_mult_vector_MatrixWithElementsSixTenTwoElevenVectorWithCoordinatesFiveSeven_MatrixWithElementsThirtyFiftyFourteenSeventyseven(void ** state)
{

    matrix_t * mat1 =  matrix_test(6,10,2,11);
    vector_t * vec1 = vector_test(5,7);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_vector(mat1,vec1),0,0),30);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_vector(mat1,vec1),0,1),50);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_vector(mat1,vec1),1,0),14);
    assert_int_equal(matrix_getElementOfMatrix(matrix_mult_vector(mat1,vec1),1,1),77);
    matrix_free(mat1);
    vector_free(vec1);
}


//transposed matrix
static void matrix_transpos_MatrixWithElementsFiveTenFifteenTwenty_matrixWithElementsFiveFifteenTenTwenty(void ** state)
{
    matrix_t * mat1 =  matrix_test(5,10,15,20);

    assert_int_equal(matrix_getElementOfMatrix(matrix_transpos(mat1),0,0),5);
    assert_int_equal(matrix_getElementOfMatrix(matrix_transpos(mat1),1,0),10);
    assert_int_equal(matrix_getElementOfMatrix(matrix_transpos(mat1),0,1),15);
    assert_int_equal(matrix_getElementOfMatrix(matrix_transpos(mat1),1,1),20);

    matrix_free(mat1);
}

//new vector
static void vector_new_TwoDimensionalVector_DimensionEqualstwo(void**state){
    vector_t * vec1 = vector_new(2);
    assert_int_equal(vector_getDimension(vec1),2);
    vector_free(vec1);


}



//add vectors
static void vector_add_VectorsWithCoordinatesFourAndFive_VectorWithCoordEigthAndTen(void ** state)
{
    vector_t * vec1 = vector_test(4,5);
    vector_t * vec2 = vector_test(4,5);

    assert_int_equal(vector_getCoord(vector_add(vec1,vec2),0),8);
    assert_int_equal(vector_getCoord(vector_add(vec1,vec2),1),10);
    vector_free(vec1);
    vector_free(vec2);

}

//find angles between vectors
static void vector_find_angle_VectorWithCoordThreeAndFourAndVectorsWithCoordinatesFourAndFive_notMinusOne(){
    vector_t * vec1 = vector_test(3,4);
    vector_t * vec2 = vector_test(4,5);
    assert_int_not_equal(vector_find_angle(vec1,vec2),-1);
     vector_free(vec1);
    vector_free(vec2);
}


//find length of vector
static void vector_findLength_VectorWithCoordThreeAndFour_IntegerFive(void ** state)
{
    vector_t * vec1 = vector_test(3,4);
    assert_int_equal(vector_findLength(vec1),5);
    vector_free(vec1);
}


//multiplication vector and number
static void vector_mult_byNumber_VectorWithCoordTenAndTwentyIntegerTwo_VectorWithCoordTwentyAndForty(void ** state){
    vector_t * vec1 = vector_test(10,20);
    assert_int_equal(vector_getCoord(vector_mult_byNumber(vec1,2),0),20);
        assert_int_equal(vector_getCoord(vector_mult_byNumber(vec1,2),1),40);

        vector_free(vec1);
}

//scalar products of vectors
static void vector_scalar_product_TwoVectorsWithCoordinatesFourAndFive_IntegerFourtyOne(void ** state){
    vector_t * vec1 = vector_test(4,5);
    vector_t * vec2 = vector_test(4,5);
    assert_int_equal(vector_scalar_product(vec1,vec2),41);
    vector_free(vec1);
    vector_findLength(vec2);

}


int main(void)
{
    const struct CMUnitTest tests[] =
    {

        cmocka_unit_test(matrix_new_fourColumnsAndThreeRows_fourCountColumnsThreeCountRows),
        cmocka_unit_test(matrix_add_TwoMatrixesWithElementsOneTwoThreeFour_MatrixWithElementsTwoFourSixEight),
        cmocka_unit_test(matrix_mult_TwoMatrixesWithElementsOneTwoThreeFour_TwoMatrixesWithElementsSevenTenFifteenTwentytwo),

        cmocka_unit_test( matrix_mult_byNumber_MatrixWithElementsFiveTenFifteenTwenty),
        cmocka_unit_test (matrix_transpos_MatrixWithElementsFiveTenFifteenTwenty_matrixWithElementsFiveFifteenTenTwenty),
        cmocka_unit_test(matrix_mult_vector_MatrixWithElementsSixTenTwoElevenVectorWithCoordinatesFiveSeven_MatrixWithElementsThirtyFiftyFourteenSeventyseven),
        cmocka_unit_test(matrix_sub_TwoMatrixesWithElementsSixTenTwoElevenAndOneTwoThreeFour_MatrixWithElementsFiveEightMinusOneSeven),
        cmocka_unit_test(vector_add_VectorsWithCoordinatesFourAndFive_VectorWithCoordEigthAndTen),
        cmocka_unit_test(vector_findLength_VectorWithCoordThreeAndFour_IntegerFive),
        cmocka_unit_test(vector_mult_byNumber_VectorWithCoordTenAndTwentyIntegerTwo_VectorWithCoordTwentyAndForty),
        cmocka_unit_test(vector_scalar_product_TwoVectorsWithCoordinatesFourAndFive_IntegerFourtyOne),
        cmocka_unit_test(vector_new_TwoDimensionalVector_DimensionEqualstwo),
        cmocka_unit_test(vector_find_angle_VectorWithCoordThreeAndFourAndVectorsWithCoordinatesFourAndFive_notMinusOne),

    };
    return cmocka_run_group_tests(tests, NULL, NULL);

}
