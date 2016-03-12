#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>


#include <cmocka.h>

#include "list.h"


static void new_void_zeroCount(void **state)
{
    list_t * list1 = list_new();
    assert_int_equal(list_getCount(list1), 0);
    list_free(list1);
}



static void add_oneValue_countOne(void **state){
    list_t * list1 = list_new();
    list_add(list1,0,5);
    assert_int_equal(list_getCount(list1), 1);
    list_free(list1);

}


static void add_fourValues_countFour(void **state){
    list_t * list1 = list_new();
    list_add(list1,0,5);
    list_add(list1,1,-5);
    list_add(list1,2,6);
    list_add(list1,3,13);
    assert_int_equal(list_getCount(list1), 4);
    list_free(list1);

}

static void delete_fourAddedValues_countThree(void **state){
   list_t * list1 = list_new();
    list_add(list1,0,5);
    list_add(list1,1,-5);
    list_add(list1,2,6);
    list_add(list1,3,13);
    list_delete(list1,4);
    assert_int_equal(list_getCount(list1), 3);
    list_free(list1);
}

static void positive_ThreePositiveNumbersAndTwoNegative_countThree(void ** state){
    list_t * list1 = list_new();
    list_add(list1,0,5);
    list_add(list1,1,-5);
    list_add(list1,2,6);
    list_add(list1,3,13);
    list_add(list1,4,-53);
    assert_int_equal(list_positive(list1), 3);
    list_free(list1);

}



static void negative_ThreePositiveNumbersAndTwoNegative_countTwo(void ** state){
    list_t * list1 = list_new();
    list_add(list1,0,5);
    list_add(list1,1,-5);
    list_add(list1,2,6);
    list_add(list1,3,13);
    list_add(list1,4,-53);
    assert_int_equal(list_negative(list1), 2);
    list_free(list1);

}


static void zeros_threeNonZeroElementsAndOneZero_countOne(void ** state){
    list_t * list1 = list_new();
    list_add(list1,0,5);
    list_add(list1,1,-5);
    list_add(list1,2,6);
    list_add(list1,3,0);
    assert_int_equal(list_zeros(list1), 1);
    list_free(list1);

}

int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_void_zeroCount),
        cmocka_unit_test(add_oneValue_countOne),
        cmocka_unit_test(add_fourValues_countFour),
        cmocka_unit_test(delete_fourAddedValues_countThree),
        cmocka_unit_test(positive_ThreePositiveNumbersAndTwoNegative_countThree),
        cmocka_unit_test(negative_ThreePositiveNumbersAndTwoNegative_countTwo),
        cmocka_unit_test(zeros_threeNonZeroElementsAndOneZero_countOne),


    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
