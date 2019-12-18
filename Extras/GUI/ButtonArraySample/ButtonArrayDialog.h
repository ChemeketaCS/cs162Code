#ifndef BUTTONARRAYDIALOG_H
#define BUTTONARRAYDIALOG_H

#include <QDialog>

#include <QPushButton>
#include <QLineEdit>


class ButtonArrayDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ButtonArrayDialog(QWidget *parent = 0);

signals:

public slots:
    //Function to handle any of the buttons being pressed
    void buttonPressed();

private:
    QLineEdit* editBox;
    const static int NUM_BUTTONS = 5;
    //array of button pointers
    QPushButton* buttonArray[NUM_BUTTONS] = {0};

};

#endif // BUTTONARRAYDIALOG_H
