#ifndef SCREENUPDATE_H
#define SCREENUPDATE_H

#include <QGraphicsScene>
#include "gamestate.h"
#include "myplayer1.h"
#include "target.h"
#include <QObject>

/*!
 * \brief Class to create Screen Updator Object
 */
class screenUpdate : public QObject{
    Q_OBJECT
public:
    /*!
     * \brief Reference to the scene of the game
     */
    QGraphicsScene * scene_local;
    /*!
     * \brief Tells if Server or Client
     */
    int id;
    /*!
     * \brief Reference to player 1
     */
    myplayer1 * p1;
    /*!
     * \brief Reference to player 2
     */
    myplayer1 * p2;
    /*!
     * \brief Reference to Target
     */
    target * t;
    /*!
     * \brief Reference to the state of the game
     */
    gamestate * state;
    //screenUpdate(QGraphicsScene * scene_param,gamestate * state_param , myplayer1 * p2_param,int i);
    /*!
     * \brief screenupdate Constructor
     * \param scene_param Scene of the Game
     * \param state_param State of the Game
     * \param p2_param Player 2 of the Game
     * \param i Id(Server or Client)
     * \param t_param Target of the Game
     */
    screenUpdate(QGraphicsScene * scene_param,gamestate * state_param , myplayer1 * p2_param,int i,target * t_param);
    /*!
     * \brief Calls the update() function using QTimer
     */
    void startUpdate();
private Q_SLOTS:
    /*!
     * \brief Updates the position of the player 2 and target
     */
    void Update();


};
#endif // SCREENUPDATE_H
