#include "Check.h"
#include "Spieler_Eintragen.h"
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

int sudokuIsComplete(char musterloesung[9][9], char spielfeld[9][9], int schwierigkeitsgrad, time_t startTime, char user[40]) {

	time_t endTime;
	bool gridIsValid = false;
	
	//auf fertiges spiel prüfen
	if (musterloesung == spielfeld) {
		gridIsValid = true;
	}
	
	//bei fertigem spiel bestenliste füllen, glueckwunsch printen und return 1
	if (gridIsValid == true) 
	{
		endTime = time(0);
		printf("Herzlichen Glückwunsch! Du hast das Sudoku korrekt ausgefüllt!\n");

		if (user != NULL) 
		{
			save(schwierigkeitsgrad, startTime, endTime, user);
		}
		else
		{
			printf("Du musst eingeloggt sein um dich in die Bestenliste einzutragen");
		}

		return 1;
	}

	return 0;
}
