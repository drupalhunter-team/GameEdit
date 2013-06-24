#ifndef GAMEIMAGE_H
#define GAMEIMAGE_H

#include <QGraphicsPixmapItem>

class GameImage : public QGraphicsPixmapItem
{
public:
    GameImage(QString &file);
};

#endif // GAMEIMAGE_H
