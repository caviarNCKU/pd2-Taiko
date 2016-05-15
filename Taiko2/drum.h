#ifndef DRUM_H
#define DRUM_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class drum
{
    Q_OBJECT
public:
    drum();
    QLabel *label_4;
public slots:
    void movement();
};

#endif // DRUM_H
