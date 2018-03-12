#ifndef BOW_H
#define BOW_H
#include <QGraphicsPixmapItem>

/*!
 * \brief The Class to create Bow object
 */
class bow : public QGraphicsPixmapItem{
public:
    /*!
     * \brief Bow Constructor
     */
    bow();
    //bow(int i);
    /*!
     * \brief Angle of the Bow
     */
    qreal angle;
};
#endif // BOW_H
