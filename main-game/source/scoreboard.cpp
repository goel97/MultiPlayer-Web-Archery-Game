#include <QGraphicsScene>
#include "scoreboard.h"

scoreboard::scoreboard()
{
    QPixmap play(":/images/score1.png");
    QPixmap scaled= play.scaled(QSize(60,35));
    setPixmap(scaled);
}
