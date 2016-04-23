#include <stdlib.h>
#include <stdio.h>

#include "designers.h"

void designer_print(designer_t * des) {
 printf("%i\n %s %s\n Employment date:%s\nRating:\t%f\n Number of sites:%i\nSalary:%i\n\n",
                des->id, des->name, des->surname, des->employment_date,  des->rating, des->numOfCites, des->salary);
}

void designer_printList(designer_t * arr, int len) {
    for (int i = 0; i < len; i++) {
        designer_print(&arr[i]);
    }
}
