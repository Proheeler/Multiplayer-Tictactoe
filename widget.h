#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    int counter;
    char values[9];
    QMessageBox *mb;
    int CheckForWinner(char spaces[]);
    void endOfGame(int check);
public slots:
    void ButtonClicked();
    void ShowGame();
signals:
    void closeMenu();


};

#endif // WIDGET_H
