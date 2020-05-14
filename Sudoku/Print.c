#include <stdio.h>
#include "Print.h"

void print_regeln(void) {
	//Regeln printen
	//TODO
}

void print_spielfeldMax(char spielfeldMax[9][9][9]) {
	char rend[27][27];
	int x, y, z;

	//spielfeldMax in 2D rendern
	for (x = 0; x < 9; x++) {
		for (y = 0; y < 9; y++) {
			rend[x * 3]			[y * 3] = spielfeldMax[x][y][0];
			rend[x * 3]			[y * 3 + 1] = spielfeldMax[x][y][1];
			rend[x * 3]			[y * 3 + 2] = spielfeldMax[x][y][2];
			rend[x * 3 + 1]		[y * 3] = spielfeldMax[x][y][3];
			rend[x * 3 + 1]		[y * 3 + 1] = spielfeldMax[x][y][4];
			rend[x * 3 + 1]		[y * 3 + 2] = spielfeldMax[x][y][5];
			rend[x * 3 + 2]		[y * 3] = spielfeldMax[x][y][6];
			rend[x * 3 + 2]		[y * 3 + 1] = spielfeldMax[x][y][7];
			rend[x * 3 + 2]		[y * 3 + 2] = spielfeldMax[x][y][8];
		}
	}

	//2D in Console ausgeben
	printf(" -----------------------------------------------------------------------\n");
	for (y = 0; y < 27; y++) {
		printf("| ");
		for(x = 0; x < 27; x++) {
			printf("%c ", rend[x][y]);
			if (x == 2 || x == 5 || x == 11 || x == 14 || x == 20 || x == 23) printf("| ");
			if (x == 8 || x == 17) printf("||");
		}
		printf("|\n");

		if (y == 2 || y == 5 || y == 11 || y == 14 || y == 20 || y == 23) printf("|-----------------------------------------------------------------------|\n");
		if (y == 8 || y == 17) printf("|=======================================================================|\n");
	}
	printf(" -----------------------------------------------------------------------\n");
}