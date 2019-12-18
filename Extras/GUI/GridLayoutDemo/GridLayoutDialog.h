#ifndef GRIDLAYOUTDIALOG
#define GRIDLAYOUTDIALOG

#include <QDialog>


class GridLayoutDialog : public QDialog
{
    Q_OBJECT

public:
    GridLayoutDialog(QWidget *parent = 0);

private:
    //Don't need to maintain named pointers to any components

public slots:
    void buttonPressed();
};


#endif // GRIDLAYOUTDIALOG

