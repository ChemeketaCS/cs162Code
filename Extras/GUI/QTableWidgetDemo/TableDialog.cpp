#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

#include <string>
using namespace std;

#include "TableDialog.h"

TableDialog::TableDialog(QWidget *parent) :
    QDialog(parent)
{
    //Setup textboxes and labels in a formlayout
    QLabel* binaryLabel = new QLabel("Data:");
    theTable = new QTableWidget(10,1);


    QPushButton* goButton = new QPushButton("Sum data");

    QLabel* sumLabel = new QLabel("Sum:");
    theResult = new QLineEdit();


    //Put two panes into main layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(binaryLabel);
    mainLayout->addWidget(theTable);
    mainLayout->addWidget(goButton);
    mainLayout->addWidget(sumLabel);
    mainLayout->addWidget(theResult);

    setLayout(mainLayout);

    //Connect signals
    connect(goButton, SIGNAL(clicked()),
            this, SLOT(sumData()));


}



//Add up all values in the table and put result into lineedit
void TableDialog::sumData() {

    int sum = 0;
    for(int i = 0; i < theTable->rowCount(); i++) {
        QTableWidgetItem* cellItem = theTable->item(i,0);

        //cells that have never had anything placed in them will have null values
        // not empty strings
        if(cellItem != nullptr) {
            //toInt on a QString returns 0 if it fails... relying on that behavior
            QString cellString = cellItem->text();
            int cellData = cellString.toInt();
            sum += cellData;
        }
    }

    theResult->setText( QString::number(sum) );
}

