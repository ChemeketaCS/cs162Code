#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Make a plain widget to be top level container (window)
    QWidget* window = new QWidget;
    window->setWindowTitle("Enter Your Age");

    //Make two widgets
    QSpinBox* spinBox = new QSpinBox;
    spinBox->setRange(0, 130);
    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 130);

    //Hook spinBox changed up to set slider
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));

    //Hook slider changed up to set spinBox
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));

    //After connection formed so updating spinBox also sets slider
    spinBox->setValue(35);

    //Make a horizontal box to contain the spinbox and slider
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(spinBox);

    //Tell top level window to contain that layout
    window->setLayout(layout);

    window->show();

    return app.exec();
}

