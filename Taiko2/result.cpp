#include "result.h"
#include "ui_result.h"
Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    QFont font;
    font.setPointSize(16);
    ui->show_score->setFont(font);
    ui->show_score->setStyleSheet("QLabel { color : black; }");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(restart()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));  //exit the game
}

Result::~Result()
{
    delete ui;
}

void Result::setscore(int number)
{
    ui->show_score->setText("Your Score:"+QString::number(number));
}

void Result::restart()
{
    emit reset();
}
