#include "enemy.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>

Enemy::Enemy(){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);
    setRect(10, 0, 100, 100);
    //connect
    QTimer * timer= new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(amove()));
    timer->start(50);
}

void Enemy::amove()
{
    setPos(x(),y()+5);
    if(pos().y()+rect().height()  > 600){
        scene()->removeItem(this);
        delete this;
    }
}
