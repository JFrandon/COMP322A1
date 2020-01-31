#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int* checkLine(char a, char b, char c) {
	int data[3];
	if (a == 'X') data[1]++;
	else data[2]++;
	if (b == 'X') data[1]++;
	else data[2]++;
	if (c == 'X') data[1]++;
	else data[2]++;
	data[0] = 3 - data[1] - data[2];
	int* results = (int*)calloc(3, sizeof(int));
	for (int i = 0, *p = results; i < 3; i++, p++) *p = data[i];
	return results;
}

int** checkGrid(char grid[9], int phase) {
	int j = 0;
	int *checks[8]; //0to 2 is vertical 3to5 is horizontal6&7 in diagonal
	for (int i = 0; i < 3 && ((phase & 2) >> 1); i++) checks[j++] = checkLine(grid[i], grid[i + 3], grid[i + 6]); //check column
	for (int i = 0; i < 3 && ((phase & 4) >> 2); i++) checks[j++] = checkLine(grid[i*3], grid[i*3 + 1], grid[i*3 + 2]); //check row
	checks[6] = checkLine(grid[0], grid[4], grid[8]);
	checks[7] = checkLine(grid[2], grid[4], grid[6]);

	int** results = (int**)calloc(8, sizeof(int));
	for (int i = 0, **p = results; i < 8; i++, p++) *p = checks[i];
	return results;
}

void greetAndInstruct() {
	char input;
	// displays info about the game
	cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl
		<< "The board is numbered from 1 to 27 as per the following : " << endl << endl
		<< " 1 | 2 | 3     10 | 11 | 12     19 | 20 | 21" << endl
		<< "------------ ---------------- ----------------" << endl
		<< " 4 | 5 | 6     13 | 14 | 15     22 | 23 | 24" << endl
		<< "------------ ---------------- ----------------" << endl
		<< " 7 | 8 | 9     16 | 17 | 18     25 | 26 | 27" << endl << endl
		<< "Player starts first.Simply input the number of the cell you want to occupy. " << endl
		<< "Player's move is marked with X. Computer's move is marked with O." << endl;
	//ask to start the game
	cout << "Start ? (y / n) :";
	// gets the answer
	cin >> input;
	if (input != 'y') exit(0);
}

void displayBoard(char board[]) {
	for (int l = 0; l < 3; l++) {
		for (int b = 0; b < 3; b++) {
			for (int c = 0; c < 3; c++) {
				char cell = board[3 * l + 9 * b + c];
				if (!cell) cout << " " << setw(2) << (9 * b + 3 * l + c + 1) << " ";
				else cout << "  "  << board[3 * l + 9 * b + c] << " ";
				if (c == 2) cout << "  ";
				else cout << '|';
			}
		} 
		cout << endl;
		if (l < 2) cout << "-------------   -------------   -------------   " << endl;
	}
}

bool checkIfLegal(int cellNbre, char board[]) {
	if (cellNbre < 1 || cellNbre > 27) return false;
	cellNbre--;
	if (board[cellNbre] != ' ') return false;
	return true;
}

bool checkWinner(char board[]) { return false; }

void computerMove(char board[]) {}
