#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
public:
    TicTacToe();
    char getCurrentPlayer();
    bool gameDone();
    char getWinner();
    void makeMove(int row, int col);
    char getOwner(int row, int col);
    bool isEmpty(int row, int col);
    void printBoard();
    void reset();

    //sets row and col to a move
    void getAISuggestedMove(int& row, int& col);

private:
    int movesMade;
    char currentPlayer;
    char board[3][3];

    //AI helper functions
    double minMaxSearch(int& row, int& col);
};

#endif
