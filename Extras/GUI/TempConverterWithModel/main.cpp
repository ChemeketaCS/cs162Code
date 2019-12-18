#include <QApplication>
#include "TempConversionDialog.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    TempConversionDialog dlg;
    dlg.show();

    return app.exec();
}

