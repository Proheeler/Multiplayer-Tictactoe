#include "widget.h"
#include "button.h"
#include <QGridLayout>
#include <QMessageBox>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout();
    for(int i= 1;i<=9;i++){
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        Button *cell = new Button(i,"");
        const QSize BUTTON_SIZE = QSize(100, 100);
        cell->setMinimumSize(BUTTON_SIZE);
        cell->setStyleSheet("border: 1px solid black; background: white;");
        connect(cell,SIGNAL(clicked(bool)),this,SLOT(ButtonClicked()));
        layout->addWidget(cell ,row, column);
        mb=new QMessageBox;




    }
    setLayout(layout);
    this->setFixedSize(350,350);
    counter=0;
}

Widget::~Widget()
{

}

int Widget::CheckForWinner(char spaces[9])
{
    //Check rows
    if((spaces[0] == 'X' && spaces[1] == 'X' && spaces[2] == 'X' )||
       (spaces[3] == 'X' && spaces[4] == 'X' && spaces[5] == 'X') ||
       (spaces[6] == 'X' && spaces[7] == 'X' && spaces[8] == 'X')
            ) return 1;
    if((spaces[0] == 'O' && spaces[1] == 'O' && spaces[2] == 'O' )||
       (spaces[3] == 'O' && spaces[4] == 'O' && spaces[5] == 'O') ||
       (spaces[6] == 'O' && spaces[7] == 'O' && spaces[8] == 'O')
            ) return 2;
    //Check columns
    if((spaces[0] == 'X' && spaces[3] == 'X' && spaces[6] == 'X' )||
       (spaces[1] == 'X' && spaces[4] == 'X' && spaces[7] == 'X') ||
       (spaces[2] == 'X' && spaces[5] == 'X' && spaces[8] == 'X')
            ) return 1;
    if((spaces[0] == 'O' && spaces[3] == 'O' && spaces[6] == 'O' )||
       (spaces[1] == 'O' && spaces[4] == 'O' && spaces[7] == 'O') ||
       (spaces[2] == 'O' && spaces[5] == 'O' && spaces[8] == 'O')
            ) return 2;
    //check diags
    if((spaces[0] == 'X' && spaces[4] == 'X' && spaces[8] == 'X' )||
       (spaces[2] == 'X' && spaces[4] == 'X' && spaces[6] == 'X')
            ) return 1;
    if((spaces[0] == 'O' && spaces[4] == 'O' && spaces[8] == 'O' )||
       (spaces[2] == 'O' && spaces[4] == 'O' && spaces[6] == 'O')
            ) return 2;
    if((spaces[0] == 'O'||spaces[0] == 'X')&&(spaces[1] == 'O'||spaces[1] == 'X')&&
       (spaces[2] == 'O'||spaces[2] == 'X')&&(spaces[3] == 'O'||spaces[3] == 'X')&&
        (spaces[4] == 'O'||spaces[4] == 'X')&&(spaces[5] == 'O'||spaces[5] == 'X')&&
        (spaces[6] == 'O'||spaces[6] == 'X')&&(spaces[7] == 'O'||spaces[7] == 'X')&&
        (spaces[8] == 'O'||spaces[8] == 'X'))
        return 3;
    else
        return 0;


}

void Widget::endOfGame(int check)
{
    int result=check;
    switch( result )
    {
    case 1:
        mb->setText("End of game \n Player 1 has won!!!");
        mb->exec();
        this->close();
        break;
    case 2:
        mb->setText("End of game \n Player 2 has won!!!");
        mb->exec();
        this->close();
        break;
    case 3:
        mb->setText("End of game \n Spair!!!");
        mb->exec();
        this->close();
        break;
    default:
        break;
    }

}

void Widget::ButtonClicked()
{

       Button *clickedButton = qobject_cast<Button *>(sender());

       if(clickedButton->text()==""){
           if(counter%2==0 || counter==0){
               clickedButton->setText("X");
               values[clickedButton->getNumber()-1]='X';
                counter++;
           endOfGame( CheckForWinner(values));}
           else{
               clickedButton->setText("O");
               values[clickedButton->getNumber()-1]='O';


               counter++;
               endOfGame( CheckForWinner(values));
           }

       }


}

void Widget::ShowGame()
{
    this->show();
    emit closeMenu();

}

