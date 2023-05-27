#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>

TicTacToe::TicTacToe()
{
    for (int i = 1; i < 10; i++)
        square[i] = '0' + i;

    currentPlayer = 1;
}

void TicTacToe::play()
{
    int choice;
    char mark;
    int gameStatus;

    do
    {
        displayBoard();
        currentPlayer = (currentPlayer % 2) ? 1 : 2;

        std::cout << "Player " << currentPlayer << ", enter a number: ";
        std::cin >> choice;

        mark = (currentPlayer == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
            square[choice] = mark;
        else
        {
            std::cout << "Invalid move! Please try again.\n";
            continue;
        }

        gameStatus = checkWin();
        currentPlayer++;

    } while (gameStatus == -1);

    displayBoard();

    if (gameStatus == 1)
        std::cout << "Player " << (currentPlayer - 1) << " wins!\n";
    else
        std::cout << "It's a draw!\n";
}

int TicTacToe::checkWin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void TicTacToe::displayBoard()
{
    system("clear");
    std::cout << "\n\n\tTic Tac Toe\n\n";
    std::cout << "Player 1 (X)  -  Player 2 (O)\n\n";

    std::cout << "     |     |     \n";
    std::cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "\n";
    std::cout << "_____|_____|_____\n";

    std::cout << "     |     |     \n";
    std::cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "\n";
    std::cout << "_____|_____|_____\n";

    std::cout << "     |     |     \n";
    std::cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "\n";
    std::cout << "     |     |     \n\n";
}