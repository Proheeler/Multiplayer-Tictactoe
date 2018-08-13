#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QToolButton>
#include <QPushButton>
class Button : public QPushButton
{
    Q_OBJECT

public:
    explicit Button(int number,QString XOR, QWidget *parent = 0);
    QString getText(){
        return XOR;
    }
    int getNumber(){
        return number;
    }
private:
    int number;
    QString XOR;
};

#endif // BUTTON_H
