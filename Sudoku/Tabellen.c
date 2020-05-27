#define _CRT_SECURE_NO_WARNINGS 1
#define DATABASE_FILE "user.sqlite3"

#include <stdio.h>
#include "sqlite3.h"
#include "Tabellen.h"

void tabellen()
{
	sqlite3* db_handle;
	int rc;
	char* sql;
	char* table;
	char* errMsg;

	rc = sqlite3_open(DATABASE_FILE, &db_handle);

	//Erstellung der Bestenlisten falls nicht vorhanden
	for (int i = 1; i <= 3; i++)
	{
		table = sqlite3_mprintf("CREATE TABLE IF NOT EXISTS userLevel%d('Username' TEXT, 'Spielzeit' NUMERIC, FOREIGN KEY(Username) REFERENCES Users(Username))", i);
		rc = sqlite3_exec(db_handle, table, NULL, NULL, &errMsg);
	}

	//Erstellung der Usertabelle falls nicht vorhanden
	table = "CREATE TABLE IF NOT EXISTS Users('Username' TEXT PRIMARY KEY, 'Passwort' TEXT NOT NULL)";
	rc = sqlite3_exec(db_handle, table, NULL, NULL, &errMsg);
}
