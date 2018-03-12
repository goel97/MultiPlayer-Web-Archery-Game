#include "gamestate.h"
#include <QGraphicsScene>

gamestate::gamestate(QGraphicsScene * scene)
{
    stateScene = scene;
    isArrow1 = false;
    isArrow2 = false;
    hit = 0;
    points1 = 0;
    points2 = 0;
}

QJsonObject gamestate::getJsonObject()
{
    QJsonObject tmp
    {

            {"player1_posX",Player1Position.x()},
            {"player1_posY",Player1Position.y()},
            {"player2_posX",Player2Position.x()},
            {"player2_posY",Player2Position.y()},
            {"target_posX",TargetPosition.x()},
            {"target_posY",TargetPosition.y()},
            {"isArrow1",isArrow1},
            {"isArrow2",isArrow2},
            {"arrow1_posX",Arrow1Position.x()},
            {"arrow1_posY",Arrow1Position.y()},
            {"arrow2_posX",Arrow2Position.x()},
            {"arrow2_posY",Arrow2Position.y()},
            {"arrow1_angle",Arrow1Angle},
            {"arrow2_angle",Arrow2Angle},
            {"bow1_angle",Bow1Angle},
            {"bow2_angle",Bow2Angle},
            {"hit",hit},
            {"points1",points1},
            {"points2",points2}

    };

    return tmp;
}



