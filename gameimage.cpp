#include "gameimage.h"

GameImage::GameImage(QString &file)
{
    setPixmap(QPixmap(file));
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
}
