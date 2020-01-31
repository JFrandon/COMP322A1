#include "functions.h"
#include <iostream>

int main()
{
    char winner = '\0';
    int plays = 0;
    char hello[27];
    int choice = 0;
    for (int i = 0; i < 27; i++) hello[i] = '\0';
    greetAndInstruct();
    do {
        displayBoard(hello);
        std::cin >> choice;
        if (!checkIfLegal(choice, hello)) continue;
        hello[choice - 1] = 'X';
        if (checkWinner(hello)) {
            winner = 'X';
            break;
        }
        computerMove(hello);
        if (checkWinner(hello)) {
            winner = 'O';
            break;
        }
        plays += 2;
    } while (plays < 27);
    std::cout << winner;

    return 0;
}