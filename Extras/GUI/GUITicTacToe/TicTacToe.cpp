#include "TicTacToe.h"
#include <iostream>
using namespace std;

//Debugging tool - allows recursive calls to indent print statements
int indent = 0;
void printIndent() {
    for(int j = 0; j < indent; j++){
        cout << "   ";
    }
}

TicTacToe::TicTacToe()
{
    currentPlayer = 'X';
	movesMade = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::reset() {
    currentPlayer = 'X';
    movesMade = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}


void TicTacToe::printBoard()
{
    for(int i = 0; i < 3; i++)
    {
        printIndent();  //for debugging recursion

        cout << "|";
        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];
        }
        cout << "|" << endl;
    }
    printIndent();  //for debugging recursion
    cout << endl;
}

char TicTacToe::getCurrentPlayer()
{
    return currentPlayer;
}

bool TicTacToe::gameDone()
{
	if(movesMade == 9 || getWinner() != ' ')
		return true;
	else
		return false;
}

char TicTacToe::getWinner()
{
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
			return board[i][0];
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
			return board[0][i];
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[0][0];

	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		return board[0][2];

    return ' ';
}

void TicTacToe::makeMove(int row, int col)
{
	if(board[row][col] == ' ') {
		movesMade++;
		board[row][col]= currentPlayer;
		if(currentPlayer == 'X')
			currentPlayer = 'O';
		else
			currentPlayer = 'X';
	}
}


char TicTacToe::getOwner(int row, int col)
{
	return board[row][col];
}

bool TicTacToe::isEmpty(int row, int col)
{
	return board[row][col] == ' ';
}


void TicTacToe::getAISuggestedMove(int& row, int& col)
{
    minMaxSearch(row, col);
}

//Process hypothetical state for current player
//Returns value in range -1 to 1 (-1 always lose, 1 always win)
//   Sets row/col to be move we should make
double TicTacToe::minMaxSearch(int& row, int& col)
{
    //-2 == no move, -1 == I lose always, range (-1,1) == more or less likely to win/lose, 1 == I win always
    double bestMoveScore = -2;  //no move is worst possible

    double totalScore = 0;  //store total value of possible moves we could make

    //used to store best move seen so far
    int tempRow = 1;
    int tempCol = 1;


    //look at all possible moves
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(isEmpty(i,j)) {
                indent++;  //debugging

                //try making this move on a copy of the board
                TicTacToe copyBoard = *this;
                copyBoard.makeMove(i, j);
                //copyBoard.printBoard();  //debugging

                //if that move ends the game, check to see if we can win
                if(copyBoard.gameDone()) {
                    char winner = copyBoard.getWinner();
                    if(winner == currentPlayer) {
                        row = i;
                        col = j;
                        indent--;   //debugging
                        return  1;  //we can win for sure... stop looking. Set row and col where move are and return 1 for win
                    } else if(winner == ' ') {
                        tempRow = i;
                        tempCol = j;
                        bestMoveScore = 0; //we can at least tie... keep looking but remember this move
                    } else {
                        //We lost - count this against our total value
                        totalScore -= 1;
                        //keep this result only if we don't have a move yet
                        if(bestMoveScore < -1 ) {
                            tempRow = i;
                            tempCol = j;
                            bestMoveScore = -1;
                        }
                    }
                } else {
                    //Game not done, let opponent move based on this new board
                    double otherGuyResult = copyBoard.minMaxSearch(row, col);

                    //Invert his result. -1 for him is 1 for us
                    double resultForMe = -otherGuyResult;
                    totalScore += resultForMe;
                    if(resultForMe >= bestMoveScore) {
                        tempRow = i;
                        tempCol = j;
                        bestMoveScore = resultForMe;
                    }
                }

                indent--;   //debugging
            }
        }
    }

    //use the best move we saw while analyzing possibilities
    row = tempRow;
    col = tempCol;

    //return the average value of all possible paths we saw
    int movesPossible = 9 - movesMade;
    double avgScore =  totalScore / movesPossible;
    return avgScore;
}







