#include <QApplication>
#include <QLabel>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel *label = new QLabel("Hello QT!");
    QString myStyle("font-size: 36pt; color: red;");
    label->setStyleSheet(myStyle);
    label->show();

    return app.exec();
}


//    QLabel *label = new QLabel("Hello <span style='color: red;'>Qt!</span>");

//    QString myStyle("font-size: 36pt; color: red;");
//    label->setStyleSheet(myStyle);
