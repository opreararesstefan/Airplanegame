#include "bullet.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QList>
#include<typeinfo>
#include"score.h"
#include"enemy.h"
#include "game.h"

extern game * gam;

void Bullet::amove(){
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i< n; i++){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
        //increase the score

          gam->score->increase();   //when i  use this line, and a bullet hit an enemy,
                                   //my program is stop working, "the process has unexpectedly finished"

            // remove them both
            scene() -> removeItem(colliding_items[i]);
            scene() ->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
        return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y()+rect().height()  < 0){
        scene()->removeItem(this);
        delete this;
    }
}

Bullet::Bullet(){
    setRect(50, 0, 10, 50);
    //connect
    QTimer * timer= new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(amove()));
    timer->start(50);
}

