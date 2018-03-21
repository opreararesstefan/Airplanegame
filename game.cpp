#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QApplication>
#include<QTimer>

#include"game.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myrect.h"
#include "bullet.h"
#include "score.h"


game::game(QWidget *parent){
   //create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //make the newly created scene the scene to viseualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //create the player to add to the scene
    Myrect* player = new Myrect();
    player->setRect(0,0,100,100);
    player->setPos(400, 500);

    //make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add item to the scene
    scene->addItem(player);

    Score *score = new Score();
    scene->addItem(score);

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
    show();
}




