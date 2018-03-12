#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

/*!
 * \brief Class to create Score Object
 */
class score: public QGraphicsTextItem{
public:
    /*!
     * \brief Score Constructor
     */
    score(QGraphicsItem * parent=0);
    /*!
     * \brief Increments the Score by 1
     */
    void increase();
    /*!
     * \brief Returns the Score
     */
    int getScore();
private:
    /*!
     * \brief Stores the score
     */
    int Score;
};

#endif // SCORE_H
