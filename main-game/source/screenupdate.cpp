#include "screenupdate.h"
#include <QTimer>
#include "score.h"
#include <QMutex>

extern QMutex mutex;
extern score * point1;
extern score * point2;
/*screenUpdate::screenUpdate(QGraphicsScene *scene_param, gamestate *state_param , myplayer1 * p2_param , int i)
{
    scene_local = scene_param;
    state = state_param;
    id = i;
   // p1 = p1_param;
    p2 = p2_param;
   // t = t_param;
}*/
screenUpdate::screenUpdate(QGraphicsScene *scene_param, gamestate *state_param , myplayer1 * p2_param , int i, target *t_param)
{
    scene_local = scene_param;
    state = state_param;
    id = i;
   // p1 = p1_param;
    p2 = p2_param;
    t = t_param;
}

void screenUpdate::startUpdate()
{
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(50);
}

void screenUpdate::Update()
{
    p2->setPos(state->Player2Position.x(),state->Player2Position.y());
    p2->bow1->setPos(740,state->Player2Position.y() + 20 );
    p2->bow1->setTransformOriginPoint(0,25);
    p2->bow1->setRotation(state->Bow2Angle);

    if(id == 1)
    {
        t->setPos(state->TargetPosition.x(),state->TargetPosition.y());
    }

    mutex.lock();
    if(state->hit == 1)
    {
        qDebug()<< "c";
        t->reset();
    }
    mutex.unlock();

    if(state->isArrow2)
    {
        p2->player2Arrow->setPos(state->Arrow2Position.x(),state->Arrow2Position.y());
        p2->player2Arrow->setRotation(state->Arrow2Angle);
        if(!p2->player2Arrow->isVisible())
            p2->player2Arrow->show();
    }
    else
    {
        if(p2->player2Arrow->isVisible())
            p2->player2Arrow->hide();
    }
    if(state->points2 == point2->getScore() + 1)
    {
        point2->increase();
    }
}

