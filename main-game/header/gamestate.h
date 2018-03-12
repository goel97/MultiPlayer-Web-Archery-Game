#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QGraphicsScene>
#include <QPointF>
#include <QJsonObject>
//#include "myplayer1.h"
//#include "target.h"
//class target;
//class myplayer1;
/*!
 * \brief Class to store the State of the Game
 */
class gamestate
{
public:
        /*!
        * \brief GameState Constructor
        */
        gamestate(QGraphicsScene * scene);
        /*!
         * \brief id = 0 in Server and id = 1 in Client
         */
        int id;
        /*!
         * \brief Reference to the scene in the game
         */
        QGraphicsScene * stateScene;
        /*!
         * \brief Stores the position of Player 1
         */
        QPointF Player1Position;
        /*!
         * \brief Stores the position of Player 2
         */
        QPointF Player2Position;
        /*!
         * \brief Stores the position of the Target
         */
        QPointF TargetPosition;
        /*!
         * \brief Tells if the arrow of player 1 is in the scene
         */
        bool isArrow1; //tells if arrow of player1 is in the scene.
        /*!
         * \brief Tells if the arrow of player 2 is in the scene
         */
        bool isArrow2; //tells if arrow of player2 is in the scene.
        /*!
         * \brief Stores the position of Arrow 1
         */
        QPointF Arrow1Position;
        /*!
         * \brief Stores the angle of Arrow 1
         */
        qreal Arrow1Angle;
        /*!
         * \brief Stores the angle of Arrow 2
         */
        qreal Arrow2Angle;
        /*!
         * \brief Stores the position of Arrow 2
         */
        QPointF Arrow2Position;
        /*!
         * \brief Stores the angle of Bow 1
         */
        qreal Bow1Angle;
        /*!
         * \brief Stores the angle of Bow 2
         */
        qreal Bow2Angle;
        /*!
         * \brief Tells if the arrow of client had hit the target.
         */
        int hit;
        /*!
         * \brief Stores the score of Player 1
         */
        int points1;
        /*!
         * \brief Stores the score of Player 2
         */
        int points2;
        /*!
         * \brief To get the Json Object of the GameState
         */
        QJsonObject getJsonObject();


    //void StateSet(myplayer1* p1 , myplayer1 * p2,target * t);
};
#endif // GAMESTATE_H
