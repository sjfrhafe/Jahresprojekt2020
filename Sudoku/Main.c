#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

#include <stdio.h>
#include "Generator.h"
#include "Maximieren.h"
#include "Print.h"
#include "Check.h"
#include "Usereingaben.h"

int interpret_usereingabe(char musterloesung[9][9], char spielfeld[9][9]);
int sudokuIsComplete(char musterloesung[9][9], char spielfeld[9][9], int schwierigkeitsgrad);

void main(void) {
	while (1) {
		//Spiel initiieren
		int schwierigkeitsgrad = 0;
		int kandidatenAktiviert = 1;
		char musterloesung[9][9];
		char spielfeld[9][9];
		char spielfeldMax[9][9][9];

		//Wilkommensnachricht
		print_regeln();

		//Schwierigkeitsgrad einlesen
		//TODO

		//Spielfeld generieren
		generate(musterloesung, spielfeld, schwierigkeitsgrad);

		//GameLoop
		while (1) {
			//Spielfeld anzeigen
			maximieren(spielfeld, spielfeldMax, kandidatenAktiviert);
			print_spielfeldMax(spielfeldMax);

			//Usereingabe bearbeiten
			if (interpret_usereingabe(musterloesung, spielfeld) == 1) break;

			//checken, ob das sudoku gelöst ist
			if (sudokuIsComplete(musterloesung, spielfeld, schwierigkeitsgrad) == 1) break;
		}
	}
}




