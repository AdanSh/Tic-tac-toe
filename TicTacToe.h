#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();
    void play();

private:
    char square[10];
    int currentPlayer;

    int checkWin();
    void displayBoard();
};

#endif
