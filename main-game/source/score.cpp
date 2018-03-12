#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    Score = 0;

    // draw the text
    setPlainText(QString("\t\t\t") + QString::number(Score)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
}

void score::increase()
{
    Score++;
    setPlainText(QString("\t\t\t") + QString::number(Score)); // Score: 1 and onwards
}

int score::getScore()
{
    return Score;
}
