#ifndef DB_SQL_H
#define DB_SQL_H

#include "sql-api.h"

struct db_sql_settings {
	const char *driver;
	const char *connect;
	const char *password_query;
	const char *user_query;
	const char *update_query;
	const char *iterate_query;
	const char *default_pass_scheme;
};

struct db_sql_connection {
	struct db_sql_connection *next;

	pool_t pool;
	int refcount;

	char *config_path;
	struct db_sql_settings set;
	struct sql_db *db;
};

struct db_sql_connection *db_sql_init(const char *config_path);
void db_sql_unref(struct db_sql_connection **conn);

void db_sql_connect(struct db_sql_connection *conn);
void db_sql_success(struct db_sql_connection *conn);

#endif
