#include "drum.h"

drum::drum()
{
    QPixmap B(":/picture/pic/blue_drum.png");
    QPixmap R(":/picture/pic/red_drum.png");
    a=(rand()%2)+1;
    if(a==1)
       ui->label_4->setPixmap(B);
    else{
       ui->label_4->setPixmap(R);
    }
    ui->label_4->setGeometry(520,130,61,61);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movement()));

    timer->start(50);
}

void drum::movement()
{
    int x = ui->label_4->x();
    int y = ui->label_4->y();

    ui->label_4->move(QPoint(x-5,y));
    ui->label_4->setFocus();
}
