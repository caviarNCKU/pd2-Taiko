#include <QObject>
#include "game.h"
#include "ui_game.h"
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>
#include <QLabel>
#include <time.h>
#include <QWidget>

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    score = 0;
    pre_time = 30;

    /*set background music*/
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/bgm/mus/bgm-30s.mp3"));
    music->play();

    /*set text size*/
    QFont font;
    font.setPointSize(16);
    ui->score->setText("Score:"+QString::number(score));
    ui->score->setFont(font);
    ui->score->setGeometry(410,30,90,40);
    ui->score->setStyleSheet("QLabel { color : black; }");

    ui->pre_time->setText("Time:"+QString::number(pre_time));
    ui->pre_time->setFont(font);
    ui->pre_time->setGeometry(40,30,90,40);
    ui->pre_time->setStyleSheet("QLabel { color : black; }");


    /*load drum picture*/
    srand(time(NULL));
    QPixmap B(":/picture/pic/blue_drum.png");
    QPixmap R(":/picture/pic/red_drum.png");
    ui->bluedrum_1->setPixmap(B);
    ui->bluedrum_2->setPixmap(B);
    ui->bluedrum_3->setPixmap(B);
    ui->bluedrum_4->setPixmap(B);
    ui->bluedrum_5->setPixmap(B);
    ui->bluedrum_6->setPixmap(B);
    ui->bluedrum_7->setPixmap(B);
    ui->bluedrum_8->setPixmap(B);
    ui->reddrum_1->setPixmap(R);
    ui->reddrum_2->setPixmap(R);
    ui->reddrum_3->setPixmap(R);
    ui->reddrum_4->setPixmap(R);
    ui->reddrum_5->setPixmap(R);
    ui->reddrum_6->setPixmap(R);
    ui->reddrum_7->setPixmap(R);
    ui->reddrum_8->setPixmap(R);


    /*set drum position*/
    for(int i=0 ; i<16 ;i++){
        setxpos[i] = (rand()%5000)+520;
    }
    ui->bluedrum_1->setGeometry(setxpos[0],130,61,61);
    ui->bluedrum_2->setGeometry(setxpos[1],130,61,61);
    ui->bluedrum_3->setGeometry(setxpos[2],130,61,61);
    ui->bluedrum_4->setGeometry(setxpos[3],130,61,61);
    ui->bluedrum_5->setGeometry(setxpos[4],130,61,61);
    ui->bluedrum_6->setGeometry(setxpos[5],130,61,61);
    ui->bluedrum_7->setGeometry(setxpos[6],130,61,61);
    ui->bluedrum_8->setGeometry(setxpos[7],130,61,61);
    ui->reddrum_1->setGeometry(setxpos[8],130,61,61);
    ui->reddrum_2->setGeometry(setxpos[9],130,61,61);
    ui->reddrum_3->setGeometry(setxpos[10],130,61,61);
    ui->reddrum_4->setGeometry(setxpos[11],130,61,61);
    ui->reddrum_5->setGeometry(setxpos[12],130,61,61);
    ui->reddrum_6->setGeometry(setxpos[13],130,61,61);
    ui->reddrum_7->setGeometry(setxpos[14],130,61,61);
    ui->reddrum_8->setGeometry(setxpos[15],130,61,61);

    /*move the drum*/
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movement()));
    timer->start(25);
    present();     //call countdown fcn

}

game::~game()
{
    delete ui;
}

void game::movement(){

     for(int i=0 ; i<16 ;i++){
        setxpos[i] = setxpos[i]-5;
    }
     ui->bluedrum_1->setGeometry(setxpos[0],130,61,61);
     ui->bluedrum_2->setGeometry(setxpos[1],130,61,61);
     ui->bluedrum_3->setGeometry(setxpos[2],130,61,61);
     ui->bluedrum_4->setGeometry(setxpos[3],130,61,61);
     ui->bluedrum_5->setGeometry(setxpos[4],130,61,61);
     ui->bluedrum_6->setGeometry(setxpos[5],130,61,61);
     ui->bluedrum_7->setGeometry(setxpos[6],130,61,61);
     ui->bluedrum_8->setGeometry(setxpos[7],130,61,61);
     ui->reddrum_1->setGeometry(setxpos[8],130,61,61);
     ui->reddrum_2->setGeometry(setxpos[9],130,61,61);
     ui->reddrum_3->setGeometry(setxpos[10],130,61,61);
     ui->reddrum_4->setGeometry(setxpos[11],130,61,61);
     ui->reddrum_5->setGeometry(setxpos[12],130,61,61);
     ui->reddrum_6->setGeometry(setxpos[13],130,61,61);
     ui->reddrum_7->setGeometry(setxpos[14],130,61,61);
     ui->reddrum_8->setGeometry(setxpos[15],130,61,61);


     this->setFocus();                  //setFocus to the game ui
                                        //make the keyevent work

     for(int i=0 ; i<16 ;i++){
        if(setxpos[i]<-40)
            setxpos[i] = (rand()%2500)+520;
    }

}

void game::present(){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(countdown()));
    timer->start(1000);
}

void game::countdown(){
    pre_time = pre_time-1;
    ui->pre_time->setText("Time:"+QString::number(pre_time));
    if(pre_time == 0)
        show_result();
}

/*show the game result ui and close the game ui
    also set signal&slot if the receive the reset signal call resetgame fcn*/
void game::show_result()
{
    resultWindow = new Result();\
    resultWindow->setscore(score);
    resultWindow->show();
    this->close();
    connect(resultWindow,SIGNAL(reset()),this,SLOT(resetGame()));
}

/*delete the gamewindow and create a new one, and also delete the
    result window*/
void game::resetGame()
{
    //delete resultWindow;
    if(this!=NULL){
        delete this;
    }

    newgamewindow = new game();
    newgamewindow->show();
    if(resultWindow!=NULL){
        delete resultWindow;
    }
}


void game::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_K){
       for(int i=0;i<8;i++){
            if(setxpos[i]>=20&&setxpos[i]<=40){
                setxpos[i] = (rand()%5000)+520;
                score+=1;                           //eliminate blue drum get 1 point
                ui->score->setText("Score:"+QString::number(score));
                event->accept();
            }
       }
    }

    if(event->key() == Qt::Key_J){
       for(int i=8;i<16;i++){
            if(setxpos[i]>=20&&setxpos[i]<=40){
                setxpos[i] = (rand()%5000)+520;
                score+=2;                           //eliminte red drum get 2 points
                ui->score->setText("Score:"+QString::number(score));
                event->accept();
            }
       }
    }
}




