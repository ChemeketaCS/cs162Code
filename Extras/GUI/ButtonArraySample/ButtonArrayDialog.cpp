#include "ButtonArrayDialog.h"


#include <QBoxLayout>

ButtonArrayDialog::ButtonArrayDialog(QWidget *parent) :
    QDialog(parent)
{
    //Make a box to hold the buttons
    QVBoxLayout* buttonBox = new QVBoxLayout;

    //Make the buttons
    for(int i = 0; i < NUM_BUTTONS; i++) {
        QString buttonLabel = QString::fromStdString((std::to_string(i)));
        buttonArray[i] = new QPushButton(buttonLabel);

        //Add to the button box so it is deisplayed
        buttonBox->addWidget(buttonArray[i]);

        //Hook button to our slot function
        connect(buttonArray[i], SIGNAL(clicked()),
                this, SLOT(buttonPressed()));
    }

    //Line edit and box to hold it
    QVBoxLayout* rightBox = new QVBoxLayout;
    editBox = new QLineEdit;
    rightBox->addWidget(editBox);
    rightBox->addStretch();         //push line edit to top

    //Setup main layout using the two boxes
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(buttonBox);
    mainLayout->addLayout(rightBox);
    this->setLayout(mainLayout);
}

//Handles any of our buttons being pressed - they all do the same thing
void ButtonArrayDialog::buttonPressed() {
    //sender() gets pointer to thing that sent signal... know it is a QPushButton so cast it
    QPushButton* senderButton = dynamic_cast<QPushButton*>(sender());
    //set line edit's text box to inclue text from button
    editBox->setText( "I see you pressed " + senderButton->text() );
}
