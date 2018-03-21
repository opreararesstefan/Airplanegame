#ifndef GAME_H
#define GAME_H

#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QApplication>
#include<QWidget>

#include "bullet.h"
#include"myrect.h"
#include"score.h"


class game : public QGraphicsView
{
public:
    game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Myrect * player;
    Score * score;

};

#endif // GAME_H
