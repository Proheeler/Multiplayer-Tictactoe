#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QWidget>
#include <widget.h>
#include <QGridLayout>

class menu:public QWidget
{
    Q_OBJECT
public:
    menu();
    Widget *w;
    QMessageBox *mb1;


public slots:
    void ShowHelp();
};

#endif // MENU_H
