#include "gamebutton.h"

GameButton::GameButton()
{
    QGraphicsPixmapItem *normalImage = new QGraphicsPixmapItem(QString("://icon/Next.png"));
    this->addToGroup(normalImage);

    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
}
