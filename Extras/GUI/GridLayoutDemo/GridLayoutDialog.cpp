#include "GridLayoutDialog.h"

#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QSizePolicy>


GridLayoutDialog::GridLayoutDialog(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;

    QLabel* infoLabel = new QLabel("Layout using a grid:");
    mainLayout->addWidget(infoLabel);

    //-----------------------------------------------------------
    //Grid of buttons
    QGridLayout* buttonGrid = new QGridLayout;

    QPushButton* btn1 = new QPushButton("1");
    btn1->setMinimumSize(75,75);
    //button 1 is at 0, 0
    buttonGrid->addWidget(btn1, 0, 0);

    QPushButton* btn2 = new QPushButton("2");
    btn2->setMinimumSize(75,75);
    //button 2 is allowed to expand horizontally but not vertically
    btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    //button 2 is at 0, 1 and spans 1 row and 2 columns
    buttonGrid->addWidget(btn2, 0, 1, 1, 2);

    QPushButton* btn3 = new QPushButton("3");
    btn3->setMinimumSize(75,75);
    //button 3 is at 1, 0
    buttonGrid->addWidget(btn3, 1, 0);

    QPushButton* btn4 = new QPushButton("4");
    btn4->setMinimumSize(75,75);
    //button 4 is allowed to expand vertically but not horizontally
    btn4->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    //button 4 is at 1, 1 and spans 2 rows and 1 column
    buttonGrid->addWidget(btn4, 1, 1, 2, 1);

    QPushButton* btn5 = new QPushButton("5");
    btn5->setMinimumSize(75,75);
    //button 5 is at 2, 0
    buttonGrid->addWidget(btn5, 2, 0);

    QPushButton* btn6 = new QPushButton("6");
    btn6->setMinimumSize(75,75);
    //button 6 is at 1, 2
    buttonGrid->addWidget(btn6, 1, 2);

    QPushButton* btn7 = new QPushButton("7");
    btn7->setMinimumSize(75,75);
    //button 7 is at 1, 2
    buttonGrid->addWidget(btn7, 2, 2);
    //-----------------------------------------------------------

    mainLayout->addLayout(buttonGrid);

    setLayout(mainLayout);


    //Wire up events:

    connect(btn1, SIGNAL(clicked()),
            this, SLOT(buttonPressed()));
    connect(btn2, SIGNAL(clicked()),
            this, SLOT(buttonPressed()));
    connect(btn3, SIGNAL(clicked()),
            this, SLOT(buttonPressed()));
    connect(btn4, SIGNAL(clicked()),
            this, SLOT(buttonPressed()));
    connect(btn5, SIGNAL(clicked()),
            this, SLOT(buttonPressed()));
    connect(btn6, SIGNAL(clicked()),
            this, SLOT(buttonPressed()));
    connect(btn7, SIGNAL(clicked()),
            this, SLOT(buttonPressed()));
}


void GridLayoutDialog::buttonPressed() {
    QObject* mySender = QObject::sender();

    //Know only QPushButtons are hooked to this - cast pointer as that
    QPushButton* pressedButton = dynamic_cast<QPushButton*>(mySender);

    if(pressedButton != nullptr) {

        QString s = pressedButton->styleSheet();
        //If stylesheet is empty - change it to have a color
        if(s.size() == 0)
            pressedButton->setStyleSheet("background-color: red;");
        else
            pressedButton->setStyleSheet("");  //reset it
    }
}
