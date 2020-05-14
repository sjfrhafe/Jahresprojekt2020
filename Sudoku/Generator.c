#include "Generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomize(int arr[], int n);
void swap(int* a, int* b);

void generate(char musterloesung[9][9], char spielfeld[9][9], int schwierigkeitsgrad) {
	int x = 0, y = 0, deletreq = 10 + (schwierigkeitsgrad * 12);

	srand(time(NULL));

	int template_line[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	randomize(template_line, 9);

	for (x = 0; x < 9; x++) {
		musterloesung[x][0] = template_line[x];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][1] = template_line[(x + 3)%9];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][2] = template_line[(x + 6) % 9];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][3] = template_line[(x + 1) % 9];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][4] = template_line[(x + 4) % 9];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][5] = template_line[(x + 7) % 9];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][6] = template_line[(x + 2) % 9];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][7] = template_line[(x + 5) % 9];
	}

	for (x = 0; x < 9; x++) {
		musterloesung[x][8] = template_line[(x + 8) % 9];
	}

	for (x = 0; x < 9; x++) {
		for (y = 0; y < 9; y++) {
			 spielfeld[x][y] = musterloesung[x][y];
		}
	}

	while (deletreq > 0) {
		x = rand() % 9;
		y = rand() % 9;
		if (spielfeld[x][y] == ' ') {
			continue;
		}
		else {
			spielfeld[x][y] = ' ';
			deletreq--;
		}
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void randomize(int arr[], int n) {
	srand(time(NULL));
	int i;
	for (i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}
}