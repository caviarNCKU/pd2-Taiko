#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QObject>
#include <QKeyEvent>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->showFullScreen();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(start()));       //change to game_ui
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));     //exit the game
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start(){
    gamewindow = new game();
    gamewindow->show();
    this->hide();
}

