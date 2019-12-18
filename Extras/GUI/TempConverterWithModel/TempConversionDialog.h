#ifndef TEMPCONVERSIONDIALOG_H
#define TEMPCONVERSIONDIALOG_H

#include <QDialog>
#include <QLineEdit>

//Include our model
#include "TempConverter.h"

class TempConversionDialog : public QDialog
{
    Q_OBJECT

public:
    TempConversionDialog(QWidget *parent = 0);\

signals:

public slots:
    void convertFtoC();
    void convertCtoF();

private:
    QLineEdit* editFahrenheit;
    QLineEdit* editCelsius;

    //The "model" that implements actual conversion logic for the GUI
    TempConverter tempLogic;
};

#endif // TEMPCONVERSIONDIALOG_H
