#include<QKeyEvent>
#include<QGraphicsScene>
#include "myrect.h"
#include"bullet.h"
#include"enemy.h"

void Myrect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < 800)
        setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }

}

void Myrect::spawn()
{
    //create enenmy
    Enemy *enemy = new Enemy();
    scene() ->addItem(enemy);
}
