
#include <QApplication>
#include "ButtonArrayDialog.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    ButtonArrayDialog dlg;
    dlg.show();

    return app.exec();
}
