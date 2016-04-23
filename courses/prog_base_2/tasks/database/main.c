#include <stdio.h>
#include <stdlib.h>

#include "db_manager.h"
#include "designers.h"

int main(void) {
    const char * dbFile = "test.db";
    designer_t designerList[100];
    db_t * db = db_new(dbFile);

    int filterCites = 20;
    int filterSalary = 18000;
    int count = db_getDesignersTask(db, filterCites, filterSalary, designerList, 100);
    printf("Designers with Number of sites > %i and Salary < %i: %i\n\n", filterCites, filterSalary, count);
    designer_printList(designerList, count);

   db_insertDesigner(db,&designerList[count-1]);
    db_updateDesigner(db,&designerList[count-1],8);
    db_deleteDesigner(db,24);
    int countAllDesigners = db_countDesigners(db);
    printf("Designers total: %i\n\n", countAllDesigners);
    designer_t * designer = db_getDesignerById(db,8);
    designer_print(designer);

    db_free(db);
    return 0;
}

