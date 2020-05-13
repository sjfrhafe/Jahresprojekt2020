#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

#include <stdio.h>

void print_regeln(void);
void generate(int musterloesung[9][9], int spielfeld[9][9], int schwierigkeitsgrad);
void print_spielfeld(int spielfeld[9][9]);
int interpret_usereingabe(char eingabe[]);
int sudokuIsComplete(int musterloesung[9][9], int spielfeld[9][9], int schwierigkeitsgrad);

void main(void) {
	while (1) {
		//Spiel initiieren
		int schwierigkeitsgrad = 0;
		int musterloesung[9][9];
		int spielfeld[9][9];
		char usereingabe[80];

		//Wilkommensnachricht
		print_regeln();

		//Schwierigkeitsgrad einlesen
		scanf("%d", &schwierigkeitsgrad);

		//Spielfeld generieren
		generate(musterloesung, spielfeld, schwierigkeitsgrad);

		//GameLoop
		while (1) {
			//Spielfeld anzeigen
			print_spielfeld(spielfeld);

			//Usereingabe abwarten
			scanf("%s", usereingabe);

			//Usereingabe bearbeiten
			if (interpret_usereingabe(usereingabe) == 1) {
				break;
			}

			//checken, ob das sudoku gelöst ist
			if (sudokuIsComplete(musterloesung, spielfeld, schwierigkeitsgrad) == 1) {
				break;
			}
		}
	}
}

void print_regeln(void) {
	//Regeln printen
}

void generate(int musterloesung[9][9], int spielfeld[9][9], int schwierigkeitsgrad) {
	//musterloesung ertellen
	//spielfeld abhaengig vom schwierigkeitsgrad aus musterloesung erstellen
}

void print_spielfeld(int spielfeld[9][9]) {
	//spielfeld anzeigen
	//(mögliche eingaben anzeigen)
}

int interpret_usereingabe(char eingabe[]) {
	//usereingabe interpretieren
		//insert number
		//kandidaten anzeigen
		//spielregeln anzeigen
		//spiel abbrechen

	//bei abbruchwunsch return 1;
	return 0;
}

int sudokuIsComplete(int musterloesung[9][9], int spielfeld[9][9], int schwierigkeitsgrad) {
	//auf fertiges spiel prüfen
	//bei fertigem spiel bestenliste füllen, glueckwunsch printen und return 1
	return 0;
}