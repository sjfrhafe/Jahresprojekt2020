#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Generator.h"
#include "Maximieren.h"
#include "Print.h"
#include "Check.h"
#include "Tabellen.h"
#include "Usereingaben.h"
#include "Bestenliste.h"
#include "Spieler_Registrieren.h"
#include "Spieler_Einloggen.h"

int interpret_usereingabe(char musterloesung[9][9], char spielfeld[9][9]);
int sudokuIsComplete(char musterloesung[9][9], char spielfeld[9][9], int schwierigkeitsgrad, time_t startTime, char user[40]);

void main(void) {
	while (1) {
		//Spiel initiieren
		time_t startTime;
		int auswahl = 0;
		char* username;
		char user[40];
		int schwierigkeitsgrad = 0;
		int kandidatenAktiviert = 1;
		char musterloesung[9][9];
		char spielfeld[9][9];
		char spielfeldMax[9][9][9];

		//Tabellen erstellen
		tabellen();

		//Wilkommensnachricht
		print_regeln();	

		//Auswahl 1 --> Spielstart 2 --> Einsicht in Bestenlisten --> Programm beenden
		do 
		{
			printf("Spiel starten --> 1\nBestenlisten --> 2\nRegistrieren --> 3\nEinloggen --> 4\n\nAuswahl: ");
			scanf("%d", &auswahl);

		} while (auswahl < 1 || auswahl > 4);
			
		if (auswahl == 1)
		{
			//Schwierigkeitsgrad einlesen 1 --> Leicht 2 --> Mittel 3 --> Schwer
			do
			{
				printf("\nSchwierigkeitsgrad\t1 --> Leicht 2 --> Mittel 3 --> Schwer\n\nAuswahl: ");
				scanf("%d", &schwierigkeitsgrad);

			} while (schwierigkeitsgrad < 1 || schwierigkeitsgrad > 3);

			//Spielfeld generieren
			generate(musterloesung, spielfeld, schwierigkeitsgrad);

			//Startzeit ermitteln
			startTime = time(0);

			//GameLoop
			while (1) {
				//Spielfeld anzeigen
				maximieren(spielfeld, spielfeldMax, kandidatenAktiviert);
				print_spielfeldMax(spielfeldMax);

				//Usereingabe bearbeiten
				if (interpret_usereingabe(musterloesung, spielfeld) == 1) break;

				//checken, ob das sudoku gelöst ist
				if (sudokuIsComplete(musterloesung, spielfeld, schwierigkeitsgrad, startTime, user) == 1) break;
			}
		}
		else if (auswahl == 2) 
		{
			//Anzeigen der Bestenlisten
			show();
		}
		else if (auswahl == 3)
		{
			//User registrieren
			registerUser();
		}

		else if (auswahl == 4)
		{
			//User einloggen
			username = loginUser();

			if (username != NULL)
			{
				strcpy(user, username);
			}
		}	
	}
}




