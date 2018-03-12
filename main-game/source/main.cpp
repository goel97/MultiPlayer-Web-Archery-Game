#include <QApplication>
#include "target.h"
#include "myplayer1.h"
#include "score.h"
#include "scoreboard.h"
#include <QGraphicsScene>
#include "gamestate.h"
//#include <QPointF>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QJsonObject>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QJsonValue>
#include "screenupdate.h"
#include "server.h"
#include "client.h"
#include <QTimer>
//#include "mainthread.h"
#include <QThread>
#include <QMutex>

score * point1;
score * point2;
QMutex mutex;
target * t;
int flag;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    gamestate * state = new gamestate(scene);
    point1 = new score();
    point2 = new score();
    scoreboard * s1 =new scoreboard();
    scoreboard * s2 =new scoreboard();
    myplayer1 * p1;

    int x = 1;
    if(x == 0)
    {
        state->id = 0;
        t = new target(state);
        p1 = new myplayer1(state,t);

        myplayer1 * p2 = new myplayer1(1,state);
        // add the item to the scene
        scene->addItem(p1);
        scene->addItem(p1->bow1);
        scene->addItem(p2);
        scene->addItem(p2->bow1);
        scene->addItem(p2->player2Arrow);
        scene->addItem(t);
        p1->setFlag(QGraphicsItem::ItemIsFocusable);
        p1->setFocus();

        scene->addItem(s1);
        scene->addItem(s2);
        scene->addItem(point1);
        scene->addItem(point2);
        point2->setPos(400,0);

        // create a view to visualize the scene
        QGraphicsView * view = new QGraphicsView(scene);

        // show the view
        //view->show();
        view->setFixedSize(800,600);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene->setSceneRect(0,0,800,600);
        scene->setBackgroundBrush(QBrush(QImage(":/images/bg.resized.png")));
        p1->setPos(0,200);
        p1->bow1->setPos(45,200);
        p2->setPos(710,200);

        p2->bow1->setPos(655,260);

        p2->bow1->setRotation(180);
        s1->setPos(150,0);
        s2->setPos(550,0);
        t->setPos(view->width()/2,view->height()-60);

        state->Player1Position.setX(p1->x());
        state->Player1Position.setY(p1->y());
        state->Player2Position.setX(p2->x());
        state->Player2Position.setY(p2->y());
        state->TargetPosition.setX(t->x());
        state->TargetPosition.setY(t->y());
        state->Bow1Angle = 0;
        state->Arrow1Angle =0;
        state->Bow2Angle = 180;
        state->Arrow2Angle = 180;
        server * GameServer = new server(scene,view,1234,state,t);
        GameServer->startServer();
        screenUpdate * u = new screenUpdate(scene,state,p2,0,t);
        u->startUpdate();
    }
    else
    {
        state->id = 1;
        t = new target(1,state);
        p1 = new myplayer1(state,t);

        myplayer1 * p2 = new myplayer1(1,state);
        // add the item to the scene
        scene->addItem(p1);
        scene->addItem(p1->bow1);
        scene->addItem(p2);
        scene->addItem(p2->bow1);
        scene->addItem(p2->player2Arrow);
        scene->addItem(t);
        p1->setFlag(QGraphicsItem::ItemIsFocusable);
        p1->setFocus();
        scoreboard * s =new scoreboard();
        scene->addItem(s1);
        scene->addItem(s2);       
        scene->addItem(point1);
        scene->addItem(point2);

        // create a view to visualize the scene
        QGraphicsView * view = new QGraphicsView(scene);

        // show the view
        view->show();
        view->setFixedSize(800,600);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scene->setSceneRect(0,0,800,600);
        scene->setBackgroundBrush(QBrush(QImage(":/images/bg.resized.png")));
        p1->setPos(0,200);
        p1->bow1->setPos(45,200);
        p2->setPos(710,200);
        p2->bow1->setPos(655,260);
        p2->bow1->setRotation(180);
        s1->setPos(150,0);
        s2->setPos(550,0);
        point2->setPos(400,0);
        t->setPos(view->width()/2,view->height()-60);
        state->Player1Position.setX(p1->x());
        state->Player1Position.setY(p1->y());
        state->Player2Position.setX(p2->x());
        state->Player2Position.setY(p2->y());
        state->TargetPosition.setX(t->x());
        state->TargetPosition.setY(t->y());
        state->Bow1Angle = 0;
        state->Arrow1Angle =0;
        state->Bow2Angle = 180;
        state->Arrow2Angle = 180;
        client * GameClient  = new client(state);
        GameClient->estServerConnection(QUrl("ws://192.168.43.210:1234"));
        screenUpdate * u = new screenUpdate(scene,state,p2,1,t);
        u->startUpdate();
    }
    return a.exec();
}
