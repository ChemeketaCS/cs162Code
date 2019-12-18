#include <iostream>

#include <QApplication>


#include "TicTacToeDialog.h"


using namespace std;



int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    TicTacToeDialog td;
    td.show();

    return app.exec();
}

