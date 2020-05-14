#include "Maximieren.h"

void maximieren(char spielfeld[9][9], char spielfeldMax[9][9][9], int kandidatenAktiviert) {
	int x, y, z;

	//spielfeldMax auf ' ' setzen
	for (x = 0; x < 9; x++) {
		for (y = 0; y < 9; y++) {
			for (z = 0; z < 9; z++) {
				spielfeldMax[x][y][z] = ' ';
			}
		}
	}
	
	//spielfeld in spielfeldMax kopieren und eventuell kandidaten hinzufügen
	for (x = 0; x < 9; x++) {
		for (y = 0; y < 9; y++) {
			if (spielfeld[x][y] != ' ') {
				spielfeldMax[x][y][4] = spielfeld[x][y];
			}
			else if(kandidatenAktiviert == 1){
				//TODO Timo
				//kandidaten für spielfeld[x][y] finden und in das array hinter spielfeldMax[x][y] einfuegen
				//z.b.  spielfeldMax[x][y][0] = '8';
			}
		}
	}
}