#ifndef MYRECT_H
#define MYRECT_H
#include<QGraphicsRectItem>
#include <QObject>

class Myrect: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};


#endif // MYRECT_H
