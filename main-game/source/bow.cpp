#include "bow.h"

bow::bow()
{
    QPixmap b(":/images/bowleft.png");
    QPixmap scaled= b.scaled(QSize(50,60));
    setPixmap(scaled);
    angle = 0;
}

