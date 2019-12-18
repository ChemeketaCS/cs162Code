#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

#include <string>
using namespace std;

#include "TempConversionDialog.h"

TempConversionDialog::TempConversionDialog(QWidget *parent) :
    QDialog(parent)
{
    //Setup textboxes and labels in a formlayout
    QLabel* binaryLabel = new QLabel("Fahrenheit:");
    QLabel* decimalLabel = new QLabel("Celsius:");
    editFahrenheit = new QLineEdit();
    editCelsius = new QLineEdit();

    QFormLayout* topPane = new QFormLayout;
    topPane->addRow(binaryLabel, editFahrenheit);
    topPane->addRow(decimalLabel, editCelsius);


    //Setup buttons in a HBoxLayout
    QPushButton* btnFToC = new QPushButton("Convert to F to C");
    QPushButton* btnCToF = new QPushButton("Convert to C to F");

    QHBoxLayout* bottomPane = new QHBoxLayout;
    bottomPane->addWidget(btnFToC);
    bottomPane->addWidget(btnCToF);


    //Put two panes into main layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topPane);
    mainLayout->addLayout(bottomPane);

    setLayout(mainLayout);

    //Connect signals
    connect(btnFToC, SIGNAL(clicked()),
            this, SLOT(convertFtoC()));

    connect(btnCToF, SIGNAL(clicked()),
            this, SLOT(convertCtoF()));

}


//Mostly using std::string
void TempConversionDialog::convertCtoF() {
    //Get QString and convert to std::string
    string CString = editCelsius->text().toStdString();
    try {
        //use string to double function from <string>
        double cTemp = stod(CString);

        //Ask "model" to do the actual mathematical work for us
        double fTemp = tempLogic.CelsiusToFahrenheit(cTemp);

        //and back to a string... but need a QString for putting in LineEdit
        QString FString = QString::number(fTemp);
        editFahrenheit->setText( FString );
    } catch (invalid_argument ex) {
        //if stod fails it will throw invalid_argument
        //Make and show an error message
        QMessageBox errMsg;
        errMsg.setText("That is not a number");
        errMsg.exec();
    }
}


//Mostly using QString
void TempConversionDialog::convertFtoC() {
    //Attempt to convert text of Line Edit to double
    bool ok;
    QString FString = editFahrenheit->text();
    double fTemp = FString.toDouble(&ok);

    if(ok) {

        //Ask "model" to do the actual mathematical work for us
        double cTemp = tempLogic.FahrenheitToCelsius(fTemp);

        //use static function to make string from double
        QString CString = QString::number(cTemp);
        //display answer
        editCelsius->setText( CString );
    } else {
        //Make and show an error message
        QMessageBox errMsg;
        errMsg.setText("That is not a number");
        errMsg.exec();
    }
}

