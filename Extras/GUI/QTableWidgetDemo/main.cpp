#include <QApplication>
#include "TableDialog.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    TableDialog dlg;
    dlg.show();

    return app.exec();
}

