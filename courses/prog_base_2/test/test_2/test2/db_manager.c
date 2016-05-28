
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sqlite3.h>
#include "db_manager.h"

struct db_s {
    sqlite3 * db;
};

db_t * db_new(const char * dbFile) {
    db_t * self = malloc(sizeof(struct db_s));
    int rc = sqlite3_open(dbFile, & self->db);
    if (SQLITE_ERROR == rc) {
        printf("can't open database\n");
        exit(1);
    }
    return self;
}

void db_free(db_t * self) {
    sqlite3_close(self->db);
    free(self);
}

int db_getDesignersTask(db_t * self,  list_t * designers) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM Designer";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);

    while (1) {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            printf("ERROR\n");
            exit(1);
        } else if (SQLITE_DONE == rc) {
            break;
        } else {
               int id = sqlite3_column_int(stmt, 0);
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    const unsigned char *  employment_date = sqlite3_column_text(stmt, 3);
    double rating = sqlite3_column_double(stmt, 4);
    int numOfCites = sqlite3_column_int(stmt, 5);
    int salary = sqlite3_column_int(stmt, 6);

       designer_t * des = designer_new();
            designer_set(des, id, name, surname, employment_date, rating, numOfCites,salary);
            list_add(designers, des);
            designer_free(des);
            puts(designer_getName(list_get(designers, 0)));
        }
    }
    sqlite3_finalize(stmt);

}



