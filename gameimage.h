#ifndef GAMEIMAGE_H
#define GAMEIMAGE_H

#include <QGraphicsPixmapItem>

typedef enum
{
    TRANS_NONE = 0,
    TRANS_ROT90 = 5,
    TRANS_ROT180 = 3,
    TRANS_ROT270 = 6,
    TRANS_MIRROR = 2,
    TRANS_MIRROR_ROT90 = 7,
    TRANS_MIRROR_ROT180 = 1,
    TRANS_MIRROR_ROT270 = 4,
}RotationType;

class GameImage : public QGraphicsPixmapItem
{
public:
    GameImage(QString &file);
    void rotateSprite(int rotateType);
};

#endif // GAMEIMAGE_H
