#include "menu.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include "widget.h"
menu::menu()
{
    QVBoxLayout *layout=new QVBoxLayout;
    QPushButton *smbtn = new QPushButton("Single mode");

    QPushButton *mp1btn = new QPushButton("Host Game");
    QPushButton *mp2btn = new QPushButton("Connect to Game");

    QPushButton *helpbtn = new QPushButton("About");
    QPushButton *quitbtn = new QPushButton("Quit");
    layout->addWidget(smbtn);
    layout->addWidget(mp1btn);
    layout->addWidget(mp2btn);
    layout->addWidget(helpbtn);
    layout->addWidget(quitbtn);
    setLayout(layout);
    this->setFixedSize(350,350);

    Widget *w = new Widget;

    connect(quitbtn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(smbtn,SIGNAL(clicked(bool)),w,SLOT(ShowGame()));
    connect(w,SIGNAL(closeMenu()),this,SLOT(close()));
    connect(helpbtn,SIGNAL(clicked(bool)),this,SLOT(ShowHelp()));

    mb1=new QMessageBox;
    mb1->setText("This game was created by Viacheslav Reshetnikov \n 2018");
    //mb->exec();



}

void menu::ShowHelp()
{
    mb1->exec();

}

