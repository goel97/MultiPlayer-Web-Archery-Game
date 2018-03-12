#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsPixmapItem>
#include "bow.h"
#include "arrow.h"
#include "gamestate.h"
#include "target.h"
#include <QWebSocket>

/*!
 * \brief Class to create Player Object
 */
class myplayer1: public QGraphicsPixmapItem
{
public:
    /*!
     * \brief Reference to the bow of the player
     */
    bow * bow1;
    /*!
     * \brief Reference to the state of the game
     */
    gamestate * state;
    /*!
     * \brief Reference to the target in the game
     */
    target *t;
    /*!
     * \brief Reference to the arrow of player 2.
     */
    arrow * player2Arrow;
    /*!
     * \brief Player Constructor to create player 1
     * \param state_param State of the Game
     * \param t_param Target in the Game
     */
    myplayer1(gamestate * state_param, target *t_param);
    /*!
     * \brief Player Constructor to create player 2
     */
    myplayer1(int i , gamestate * state_param);
    /*!
     * \brief To process when a key is pressed by the user
     */
    void keyPressEvent(QKeyEvent * event);
    /*!
     * \brief Reference to the Client Socket in the game
     */
    QWebSocket * client_local;
    /*!
     * \brief Function to set the reference to the Client Socket in the game
     */
    void setClientLocal(QWebSocket * client_param);

};

#endif // MYPLAYER1_H
