#define _CRT_SECURE_NO_WARNINGS 1
#define DATABASE_FILE "user.sqlite3"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Spieler_Einloggen.h"
#include "sqlite3.h"

char* loginUser()
{
	sqlite3_stmt* stmt;
	sqlite3_stmt* stmt2;
	sqlite3* db_handle;
	int rc;
	char* sqlUsername;
	char* sqlPasswort;
	char username[40];
	char passwort[40];
	int eingabe = 0;
	char userPlaceholder[40];
	char* user = NULL;
	char passwortPlaceholder[40];
	int versuche = 0;

	rc = sqlite3_open(DATABASE_FILE, &db_handle);

	do
	{
		//Username einlesen
		printf("Username eingeben: ");
		scanf("%s", &username);

		//Username aus Tabelle entnehmen
		sqlUsername = sqlite3_mprintf("SELECT Username FROM Users WHERE Username = '%s'", username);
		rc = sqlite3_prepare_v2(db_handle, sqlUsername, strlen(sqlUsername), &stmt, NULL);

		while (sqlite3_step(stmt) == SQLITE_ROW) {

			const char* data = (const char*)sqlite3_column_text(stmt, 0);

			do
			{
				//Passwort einlesen
				printf("Passwort eingeben: ");
				scanf("%s", passwort);

				//Passwort aus Tabelle nehmen
				sqlPasswort = sqlite3_mprintf("SELECT Passwort FROM Users WHERE Username = '%s'", username);
				rc = sqlite3_prepare_v2(db_handle, sqlPasswort, strlen(sqlPasswort), &stmt2, NULL);

				while (sqlite3_step(stmt2) == SQLITE_ROW) {

					const char* passwortSql = (const char*)sqlite3_column_text(stmt2, 0);
					strcpy(passwortPlaceholder, passwortSql);

					//Passwort aus Tabelle mit Userinput vergleichen
					if (strcmp(passwortPlaceholder, passwort) == 0)
					{
						strcpy(userPlaceholder, data);
						user = &userPlaceholder[0];
						versuche = 3;
					}
					else
					{
						printf("Passwort ist falsch.\n");
						versuche++;

						if (versuche == 3)
						{
							//Login beenden nach 3 falschen Eingaben
							printf("Fehler: Zu viele Versuche.\n");
							sqlite3_finalize(stmt);
							sqlite3_finalize(stmt2);
							sqlite3_close(db_handle);
							return NULL;
						}
					}
				}

			} while (versuche < 3);

			sqlite3_finalize(stmt);
			sqlite3_finalize(stmt2);
			sqlite3_close(db_handle);
			return user;
		}

		printf("Username nicht gefunden.\n");
		eingabe++;

		//Login beenden nach 3 falschen Eingaben
		if (eingabe == 3)
		{
			printf("Fehler: Zu viele Versuche.\n");
			return NULL;
		}

	} while (eingabe < 3);
}