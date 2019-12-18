#include <QVBoxLayout>
#include <QGridLayout>
#include <iostream>

using namespace std;

#include "TicTacToeDialog.h"


TicTacToeDialog::TicTacToeDialog(QWidget *parent) :
    QDialog(parent)
{
    title = new QLabel("Tic-Tac-Toe");
    title->setFont( QFont("Arial", 24) );
    instruction = new QLabel("X goes first...");


    QGridLayout* buttonGrid = new QGridLayout;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            squares[i][j] = new QPushButton("");
            squares[i][j]->setStyleSheet("font-size: 24pt; padding: 0px;");

            squares[i][j]->setMinimumSize(75,75);
            buttonGrid->addWidget(squares[i][j], i, j);
            connect(squares[i][j],SIGNAL(clicked()), this, SLOT(buttonPressed()));
        }
    }

    resetButton = new QPushButton("Restart");
    resetButton->hide();
    connect(resetButton,SIGNAL(clicked()), this, SLOT(restartGame()));


    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(title);
    mainLayout->addLayout(buttonGrid);
    mainLayout->addWidget(instruction);
    mainLayout->addWidget(resetButton);

    setLayout(mainLayout);
}

void TicTacToeDialog::endGame() {
    if(gameEngine.getWinner() != ' ') {
        QString newText;
        newText.append(gameEngine.getWinner());
        newText.append(" wins");
        instruction->setText(newText);
    } else {
        instruction->setText("Tie game");
    }

    resetButton->show();

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            squares[i][j]->setEnabled(false);
        }
    }
}

void TicTacToeDialog::restartGame() {
    resetButton->hide();

    instruction->setText("X goes first...");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            squares[i][j]->setEnabled(true);
            squares[i][j]->setText("");
        }
    }
    gameEngine.reset();
}


void TicTacToeDialog::buttonPressed() {
    QObject* mySender = QObject::sender();
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(mySender);

    //Find which button that was...
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if( squares[i][j] == pressedButton ) {
                //Found the right one,
                //i and j give us the proper indexes for board
                if(gameEngine.isEmpty(i,j)) {
                    QString newText;
                    newText.append(gameEngine.getCurrentPlayer());
                    pressedButton->setText( newText );
                    gameEngine.makeMove(i, j);

                    if(gameEngine.gameDone()) {
                        endGame();
                    } else {
                        int r, c;
                        gameEngine.getAISuggestedMove(r, c);
                        QString newText2;
                        newText2.append(gameEngine.getCurrentPlayer());
                        squares[r][c]->setText( newText2 );
                        gameEngine.makeMove(r, c);

                        if(gameEngine.gameDone())
                            endGame();
                    }

                } else {
                    instruction->setText("Can't do that...");
                }
            }
        }
    }
}

TicTacToeDialog::~TicTacToeDialog()
{
    //Any components we have added
    // are automatically deleted
}
