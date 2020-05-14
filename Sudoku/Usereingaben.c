#include "Usereingaben.h"
#include <stdio.h>

int interpret_usereingabe(char musterloesung[9][9], char spielfeld[9][9]) {
	char user_input[80];
	fgets(user_input, 80, stdin);
	system("cls");

	//usereingabe 'userinput' interpretieren
		//insert number (fehler bei falscher nummer)
		//kandidaten anzeigen
		//spielregeln anzeigen
		//spiel abbrechen
		//bei abbruchwunsch return 1;
	//TODO

	return 0;
}