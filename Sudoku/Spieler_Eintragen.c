#define _CRT_SECURE_NO_WARNINGS 1
#define DATABASE_FILE "user.sqlite3"

#include "Spieler_Eintragen.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"

void save(int schwierigkeitsgrad, time_t startTime, time_t endTime, char user[40]) {

	sqlite3* db_handle;
	int rc;
	char* sql;
	char* table;
	char* errMsg;
	double gameTime;

	//Berechnung der Spielzeit
	gameTime = difftime(endTime, startTime);

	rc = sqlite3_open(DATABASE_FILE, &db_handle);

	//Speichern des Users mit Spielzeit in jeweilige Tabelle
	sql = sqlite3_mprintf("INSERT INTO userLevel%d(Username, Spielzeit) VALUES ('%s', '%f')", schwierigkeitsgrad, user, gameTime);

	rc = sqlite3_exec(db_handle, sql, NULL, NULL, &errMsg);

	if (rc != SQLITE_OK) {
		printf("Fehler: %s\n", errMsg);
		sqlite3_free(errMsg);
		sqlite3_free(db_handle);
	}
	else {
		printf("Eintrag erfolgreich!");
		sqlite3_close(db_handle);
	}
}