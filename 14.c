#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {
    int *count = (int*)data;
    *count = atoi(argv[0]);
    return 0;
}


int main() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    rc = sqlite3_open(":memory:", &db);
    char *sql = "CREATE TABLE Users(Id INT, Name TEXT);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    sql = "INSERT INTO Users(Id, Name) VALUES(1, 'Alice')";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    int rowCount = 0;
    sql = "SELECT COUNT(*) FROM Users;";
    rc = sqlite3_exec(db, sql, callback, &rowCount, &err_msg);
    if (rowCount !=1) exit(1);     



    char user_input[256];
    printf("Enter a SQL command: ");
    fgets(user_input, 256, stdin);
    user_input[strcspn(user_input, "\n")] = 0;
    rc = sqlite3_exec(db, user_input, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Executed SQL command successfully\n");
        if (sqlite3_table_column_metadata(db, NULL, "Users", NULL, NULL, NULL, NULL, NULL, NULL) == SQLITE_ERROR) {
            printf("The table was dropped successfully.\n");
        }
    }

    sqlite3_close(db);
    return 0;
}
