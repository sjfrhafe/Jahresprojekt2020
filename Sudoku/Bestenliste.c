#define _CRT_SECURE_NO_WARNINGS 1
#define DATABASE_FILE "user.sqlite3"

#include "Bestenliste.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"

void show() {

	int auswahl = 0;
	int schwierigkeitsgrad = 0;
	sqlite3* db_handle;
	int rc;
	char* sql;
	sqlite3_stmt* stmt;

	do 
	{
		//Auswahl Bestenliste --> 1 Hauptmenü --> 2
		do 
		{
			printf("Bestenliste --> 1\nHauptmenu --> 2\n\nAuswahl: ");
			scanf("%d", &auswahl);

		} while (auswahl != 1 && auswahl != 2);

		if (auswahl == 1) {

			//Auswahl Bestenliste
			do
			{
				printf("\nSchwierigkeitsgrad der Bestenliste\t1 --> Leicht 2 --> Mittel 3 --> Schwer\n\nAuswahl: ");
				scanf("%d", &schwierigkeitsgrad);

			} while (schwierigkeitsgrad != 1 && schwierigkeitsgrad != 2 && schwierigkeitsgrad != 3);

			//Anpassung SQL
			sql = sqlite3_mprintf("Select Username, Spielzeit from userLevel%d order by Spielzeit", schwierigkeitsgrad);
			rc = sqlite3_open(DATABASE_FILE, &db_handle);
			rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

			int cols = sqlite3_column_count(stmt);

			//Spaltennamen ausgeben

			printf("\n\n");
			for (int col = 0; col < cols; col++)
			{
				printf("%10s\t", (const char*)sqlite3_column_name(stmt, col));
			}
			printf("\n----------------------------------------------\n");

			//Werte der Spalten ausgeben  

			while (sqlite3_step(stmt) == SQLITE_ROW) {

				const char* data = (const char*)sqlite3_column_text(stmt, 0);

				for (int col = 0; col < cols; col++)
				{
					if (col == 0)
					{
						data = (const char*)sqlite3_column_text(stmt, col);
						printf("%10s\t", data);
					}

					if (col == 1)
					{
						data = (const char*)sqlite3_column_text(stmt, col);
						double timePlaceholder = atof(data);
						int seconds;

						//Anpassen der Zeit

						if (timePlaceholder < 60)
						{
							printf("%5.2f sek.", timePlaceholder);
						}
						else if (timePlaceholder >= 60) {
							seconds = (int)timePlaceholder % 60;
							timePlaceholder /= 60;
							printf("%5.0f min. & %d sek.", timePlaceholder, seconds);
						}

						printf("\n");
					}
				}
			}

			printf("\n");
			sqlite3_free(sql);
			sqlite3_finalize(stmt);
			sqlite3_close(db_handle);
		}

	} while (auswahl != 2);
}