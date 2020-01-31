#pragma once
void displayBoard(char board[]);
void greetAndInstruct();
bool checkIfLegal(int cellNbre, char board[]);
bool checkWinner(char board[]);
void computerMove(char board[]);