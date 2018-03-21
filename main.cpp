
#include <QApplication>
#include "game.h"


 game * gam;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     gam = new game;
    gam->show();

    return a.exec();
}
