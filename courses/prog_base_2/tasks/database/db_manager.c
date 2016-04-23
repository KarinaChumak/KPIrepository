#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sqlite3.h>

#include "db_manager.h"
#include "designers.h"

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

int db_countDesigners(db_t * self) {
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM Designer;", -1, &stmt, 0);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select count\n");
        exit(1);
    }
    int count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return count;
}


static void _fillDesigner(sqlite3_stmt * stmt, designer_t * des) {
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    const unsigned char *  employment_date = sqlite3_column_text(stmt, 3);
    double rating = sqlite3_column_double(stmt, 4);
    int numOfCites = sqlite3_column_int(stmt, 5);
    int salary = sqlite3_column_int(stmt, 6);
    des->id = id;
    strcpy(des->name, (const char *)name);
    strcpy(des->surname, (const char *)surname);
    strcpy(des->employment_date, (const char *)employment_date);
    des->rating = rating;
    des->numOfCites = numOfCites;
    des->salary = salary;
}


int db_insertDesigner(db_t * self, designer_t * designer){
 int newDesignerId = -1;
   sqlite3_stmt * stmt = NULL;

   int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Designer  ( name, surname, employment_date, rating, numOfCites, salary) VALUES (?,?, ?, ?,?, ?);", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    //sqlite3_bind_int(stmt,1,designer->id);
    sqlite3_bind_text(stmt, 1,designer->name,strlen(designer->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2,designer->surname,strlen(designer->surname),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,designer->employment_date,strlen(designer->employment_date),SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,4,designer->rating);
    sqlite3_bind_int(stmt, 5,designer->numOfCites);
    sqlite3_bind_int(stmt, 6,designer->salary);
    ;
        rc = sqlite3_step(stmt);


    if (SQLITE_DONE != rc) {
        printf("Not inserted! %i\n", rc);
    }

     newDesignerId = (int) sqlite3_last_insert_rowid (self->db);
     sqlite3_finalize(stmt);
    return newDesignerId;
}



int db_getDesignersTask(db_t * self, int K, int P, designer_t * arr, int arrMax) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM Designer WHERE   numOfCites > ? AND salary < ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, K);
    sqlite3_bind_int(stmt, 2, P);
    int count = 0;
    while (1) {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            printf("ERROR\n");
            exit(1);
        } else if (SQLITE_DONE == rc) {
            break;
        } else {
            _fillDesigner(stmt, &arr[count]);
            count++;
        }
    }
    sqlite3_finalize(stmt);
    return count;
}

designer_t * db_getDesignerById(db_t * self, int id){
    designer_t * designer = malloc(sizeof(designer_t*));
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT * FROM Designer WHERE id = ?;", -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
     while (1)
    {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc)
        {
            printf("can't select designers\n");
            exit(1);
        }
        else if (SQLITE_DONE == rc)
        {   sqlite3_finalize(stmt);
            return designer;
}
        else
        {
            _fillDesigner(stmt,designer);
            return designer;
        }
    }
    sqlite3_finalize(stmt);
}

void db_updateDesigner(db_t * self, designer_t * designer, int id){
    sqlite3_stmt * stmt = NULL;
   int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"UPDATE Designer SET   name = ?, surname= ?, employment_date= ?, rating= ?, numOfCites= ?, salary= ? WHERE id = ?;", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }

    sqlite3_bind_text(stmt, 1,designer->name,strlen(designer->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2,designer->surname,strlen(designer->surname),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,designer->employment_date,strlen(designer->employment_date),SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,4,designer->rating);
    sqlite3_bind_int(stmt, 5,designer->numOfCites);
    sqlite3_bind_int(stmt, 6,designer->salary);
    sqlite3_bind_int(stmt,7,designer->id);

     if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not updated! %i\n", rc);
    }
     sqlite3_finalize(stmt);
}



void db_deleteDesigner(db_t * self, int id){
    sqlite3_stmt * stmt = NULL;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db, "DELETE FROM Designer WHERE id = ?;", -1, &stmt, 0)){
        printf("Not prepared!\n");
    }
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    if (SQLITE_DONE != rc) {
        printf("Not deleted! %i\n", rc);
    }
    sqlite3_finalize(stmt);
}

