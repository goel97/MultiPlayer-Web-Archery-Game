#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "gamestate.h"
#include "target.h"

/*!
 * \brief The Class to Create an Arrow Object
 */

class arrow: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /*!
     * \brief Reference to the state of the game
     */
    gamestate * state;
    /*!
     * \brief Reference to the target in the game
     */
    target *t;
    /*!
        * \brief Arrow Constructor to create arrow for player1
        * \param state_param State of the Game.
        * \param t_param Target in the game.
        */
    arrow(gamestate * state_param, target *t_param);
    /*!
     * \brief Arrow Constructor to create arrow for player2
     */
    arrow(int i);
    /*!
     * \brief  Angle at which the arrow was launched.
     */
    qreal angle;
    /*!
     * \brief Stores the current angle of the arrow
     */
    qreal presentAngle;
    /*!
     * \brief X coordinate from where the arrow the was launched.
     */
    qreal initialX;
    /*!
     * \brief Y coordinate from where the arrow the was launched.
     */
    qreal initialY;
    /*!
     * \brief Time which maintains the projectile path of the arrow
     */
    qreal time;
public slots:
    /*!
     * \brief Moves the arrow after it is launched.
     */
    void move();
};

#endif // ARROW_H
