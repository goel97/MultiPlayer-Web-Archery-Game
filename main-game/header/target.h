#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsPixmapItem>
#include "gamestate.h"

#include <QObject>
/*!
 * \brief Class to create Target object
 */
class target: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /*!
     * \brief Reference to the state of the game
     */
    gamestate * state;
    /*!
     * \brief Target Constructor fot Server
     * \param state_param State of the game
     */
    target(gamestate * state_param);
    /*!
     * \brief Target Constructor fot Client
     * \param state_param State of the Game
     */
    target(int i,gamestate * state_param);
    /*!
     * \brief Stores the direction of movement of the target
     */
    int a;
    /*!
     * \brief Resets the position of the target
     */
    void reset();
public slots:
    /*!
     * \brief moves the target
     */
    void move();

};
#endif // TARGET_H
