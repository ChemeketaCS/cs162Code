#ifndef TABLEDIALOG_H
#define TABLEDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QLineEdit>


class TableDialog : public QDialog
{
    Q_OBJECT
public:
    TableDialog(QWidget *parent = 0);

signals:

public slots:
    void sumData();

private:
    QTableWidget* theTable;
    QLineEdit* theResult;

};

#endif // TABLEDIALOG_H
