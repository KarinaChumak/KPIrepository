#ifndef DB_MANAGER_H_INCLUDED
#define DB_MANAGER_H_INCLUDED

#include "sqlite3.h"
#include "list.h"
#include "designer.h"


typedef struct db_s db_t;
db_t * db_new(const char * dbFile);
void db_free(db_t * self);
int db_getDesignersTask(db_t * self,  list_t * designers);


#endif // DB_MANAGER_H_INCLUDED
