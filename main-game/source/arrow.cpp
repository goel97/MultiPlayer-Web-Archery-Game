#include "arrow.h"
#include "score.h"
#include <QTimer>
#include <QtCore/qglobal.h>
#include <QTime>
#include <QGraphicsScene>
#include <QList>
#include <qmath.h>
#include "target.h"
#include "myplayer1.h"
#include <typeinfo>
#include <QDebug>
#include <QMutex>

extern score * point1;
extern score * point2;
extern QMutex mutex;
extern int flag;

arrow::arrow(gamestate *state_param, target *t_param)
{
    state = state_param;
    t = t_param;
    QPixmap arro(":/images/arr.png");
    QPixmap scaled= arro.scaled(QSize(55,18));
    setPixmap(scaled);
    time=0;

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

arrow::arrow(int i)
{
    QPixmap arro(":/images/arr.png");
    QPixmap scaled= arro.scaled(QSize(55,18));
    setPixmap(scaled);
}

void arrow::move(){
    time += 0.3;

    //qDebug() << t->x() <<t->y();
    mutex.lock();

    if(pos().x()>=(t->x()-20) && pos().x()<=(t->x()+20) && pos().y()<(t->y()+20) && pos().y()>(t->y()-20))
    {
        if(state->id ==1 )
        {
            state->hit = 1;
        }

        point1->increase();
        state->points1 ++;
        scene()->removeItem(this);
        if(state->id == 0)
        {
             t->reset();
             state->TargetPosition.setX(t->x());
             state->TargetPosition.setY(t->y());
         }
         delete this;
         state->isArrow1=false;
         flag=0;

         mutex.unlock();

         return;

    }
    mutex.unlock();

    presentAngle = qRadiansToDegrees(qAtan((75*qSin(qDegreesToRadians(-1*angle)) - 10*time)/(75*qCos(qDegreesToRadians(angle)))));
    setRotation(-1*presentAngle);
    state->Arrow1Angle = -1*presentAngle;

    double dy = 80 * qSin(qDegreesToRadians(-1*angle))*time-(5*(time*time));
    double dx = 80 * qCos(qDegreesToRadians(angle)) * time;

    setPos(initialX+dx,initialY-dy);
    state->Arrow1Position.setX(pos().x());
    state->Arrow1Position.setY(pos().y());

    if (pos().x() > 475)
    {
        scene()->removeItem(this);
        state->isArrow1 = false;
        delete this;
        flag=0;
    }
}
