#ifndef TICTACTOEDIALOG_H
#define TICTACTOEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

#include "TicTacToe.h"

class TicTacToeDialog : public QDialog
{
    Q_OBJECT

public:
    TicTacToeDialog(QWidget *parent = 0);
    ~TicTacToeDialog();

private:
    QPushButton* squares[3][3];
    QLabel* title;
    QLabel* instruction;
    QPushButton* resetButton;

    TicTacToe gameEngine;

    void endGame();

public slots:
    void buttonPressed();
    void restartGame();
};

#endif // TICTACTOEDIALOG_H
