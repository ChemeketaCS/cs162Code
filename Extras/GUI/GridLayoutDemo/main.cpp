#include <iostream>
#include <QApplication>

#include "GridLayoutDialog.h"

using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GridLayoutDialog demo;
    demo.show();

    return app.exec();
}

