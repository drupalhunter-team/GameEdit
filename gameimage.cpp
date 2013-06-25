#include "gameimage.h"
#include "QDebug"
GameImage::GameImage(QString &file)
{
    setPixmap(QPixmap(file));
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
}
//#include "QGraphicsItemAnimation."

void GameImage::rotateSprite(int rotateType)
{
    switch (rotateType)
    {
        case TRANS_NONE:
            break;
        case TRANS_ROT90:
            this->setRotation(90);
            break;
        case TRANS_ROT180:
            this->setRotation(180);
            break;
        case TRANS_ROT270:
            this->setRotation(270);
            break;
        case TRANS_MIRROR:
            //this->setRotation(0);
            //sprite.flipX = YES;
            break;
        case TRANS_MIRROR_ROT90:
            //sprite.rotation = 90;
            //sprite.flipX = YES;
            break;
        case TRANS_MIRROR_ROT180:
            //sprite.rotation = 180;
            //sprite.flipX = YES;
            break;
        case TRANS_MIRROR_ROT270:
            //sprite.rotation = 270;
            //sprite.flipX = YES;
            break;
        default:
            break;
    }
}
