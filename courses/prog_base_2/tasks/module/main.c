#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


int main()
{
list_t * list1 = list_new();
list_add(list1,0,5);
list_add(list1,1,-5);
list_add(list1,2,6);
list_add(list1,3,13);
list_add(list1,4,-56);
list_add(list1,5, 89);
list_add(list1,6,19);
list_add(list1,7,0);

list_delete(list1,4);
list_delete(list1,0);

printf("Negative:%d\n",list_negative(list1));
printf("Positive:%d\n",list_positive(list1));
printf("Zero:%d\n",list_zeros(list1));
printf("Count:%d\n",list_getCount(list1));


list_free(list1);
return 0;}
