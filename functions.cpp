#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int* checkLine(char a, char b, char c) {
	int* data = new int[3];
	if (a == 'X') data[1]++;
	else if (b == 'O') data[2]++;
	if (b == 'X') data[1]++;
	else if (b == 'O') data[2]++;
	if (c == 'X') data[1]++;
	else if (b == 'O') data[2]++;
	data[0] = 3 - data[1] - data[2];
	return data;
}

int** checkGrid(char grid[9], int phase) {
	int j = 2;
	int **checks = new int*[8]; //0to1 diagonal 2to 5 is vertical 5to7 is horizontal
	for (int i = 0; i < 3 && (phase & 1) ; i++) checks[j++] = checkLine(grid[i], grid[i + 3], grid[i + 6]); //check column
	for (int i = 0; i < 3 && ((phase & 2) >> 1); i++) checks[j++] = checkLine(grid[i*3], grid[i*3 + 1], grid[i*3 + 2]); //check row
	checks[0] = checkLine(grid[0], grid[4], grid[8]);
	checks[1] = checkLine(grid[2], grid[4], grid[6]);
	return checks;
}

int** checkBoard(char grid[27]) {
	char* c = grid;
	int** result = new int* [43];
	int** p = result;
	for (int i = 0; i < 27; i += 9) {
		int **xgrid = checkGrid((grid + i), 3);
		for (int** a = xgrid; p < (result + ((i/9)+1)*8); a++, p++) *p = *a;
		delete xgrid;
	}
	for (int i = 0; i < 9; i += 3) {
		char g[9] = { c[i], c[i + 1], c[i + 2], c[i + 9], c[i + 11], c[i + 12], c[i + 18], c[i + 19], c[i + 20] };
		int** ygrid = checkGrid(g, 1);
		for (int** a = ygrid; p < (result + ((i/3) + 1) * 5 + 24); a++, p++) {
			*p = *a;
			cout << (p - result) << " " << *result[(p - result)] << endl;
		}
		delete ygrid;
	}
	{char g[9] = { c[0], c[3],c[6],c[10],c[13],c[16], c[20], c[23],c[26] };
	int** xygrid = checkGrid(g, 0);
	*(p++) = *(xygrid);
	*(p++) = *(xygrid+1);
	delete xygrid;
	}
	{char g[9] = { c[2], c[5],c[8],c[10],c[13],c[16], c[18], c[21],c[24] };
	int** xygrid = checkGrid(g, 0);
	*(p++) = *(xygrid);
	*(p) = *(xygrid + 1);
	delete xygrid;
	}
	for (int i = 0; i < 42; i++) {
		cout << *(result[i]) << " " << endl;
	}
	cout << endl;
	return result;
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
	return (board[--cellNbre]=='\0');
}

bool checkWinner(char board[]) {
	int** results = checkBoard(board);
	for (int i = 0; i < 43; i++) {
		if (max((results[i])[1], (results[i])[2]) == 3) return true;
	}
	return false; 
}

void computerMove(char board[]) {
	
}
