#define _CRT_SECURE_NO_WARNINGS 1
#define DATABASE_FILE "user.sqlite3"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Spieler_Registrieren.h"
#include "sqlite3.h"

void registerUser()
{
	sqlite3* db_handle;
	int rc;
	char* sql;
	char* table;
	char* errMsg;
	char username[40];
	char passwort[40];
	char eingabe;
	int success = 0;

	do
	{
		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		//Username und Passwort einlesen
		printf("Username eingeben: ");
		scanf("%s", &username);
		printf("\nPasswort eingeben: ");
		scanf("%s", &passwort);

		//Eintrag in Tabelle
		sql = sqlite3_mprintf("INSERT INTO Users(Username, Passwort) VALUES ('%s', '%s')", username, passwort);
		rc = sqlite3_exec(db_handle, sql, NULL, NULL, &errMsg);

		if (rc != SQLITE_OK) {
			printf("Fehler: %s\n", errMsg);
			printf("Username bereits vorhanden.\n");
			sqlite3_free(errMsg);
			sqlite3_free(db_handle);
			success = -1;
		}
		else {
			printf("Registrierung erfolgreich!");
			sqlite3_close(db_handle);
			success = 0;
		}

		if (success == -1)
		{
			printf("\n\nRegistrierung wiederholen? y/n\n");
			scanf(" %c", &eingabe);

			if (tolower(eingabe) == 'n')
			{
				success = 0;
			}
			else if (tolower(eingabe) == 'y')
			{
				success = -1;
			}
		}

	} while(success != 0);
}