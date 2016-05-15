#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QWidget>
//#include <QPushButton>
#include <QtWidgets>
#include <QLabel>
#include "result.h"
#include <QMediaPlayer>

namespace Ui {
class game;
}

class game : public  QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    int setxpos[16];
    void present();
    int score;
    ~game();

private slots:
    void movement();
    void countdown();
    void show_result();
    void resetGame();
private:
    Ui::game *ui;
    int pre_time;
    Result *resultWindow;
    game *newgamewindow;
    QMediaPlayer * music;
};

#endif // GAME_H
