#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qtcore>
#include <QtGui>
#include <QtWidgets>
#include "game.h"
#include "result.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    game *gamewindow;

private slots:
    void start();
};

#endif // MAINWINDOW_H
