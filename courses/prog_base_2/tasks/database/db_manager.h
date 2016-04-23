
#ifndef DB_MANAGER_H_INCLUDED
#define DB_MANAGER_H_INCLUDED

#include "designers.h"

typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);

int db_insertDesigner(db_t * self, designer_t * designer);
int db_getDesignersTask(db_t * self, int K, int P, designer_t * arr, int arrMax);
void db_deleteDesigner(db_t * self, int id);
void db_updateDesigner(db_t * self, designer_t * designer, int id);
int db_countDesigners(db_t * self);

designer_t * db_getDesignerById(db_t * self, int id);


#endif // DB_MANAGER_H_INCLUDED
