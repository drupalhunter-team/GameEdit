#include "gamepaintwindow.h"
#include <QGraphicsItemGroup>

GamePaintWindow::GamePaintWindow(QSize winSize, QObject *parent) :
    QGraphicsScene(parent)
{
    this->addLine( 0, -winSize.height()/2, 0, winSize.height()/2);
    this->addLine( -winSize.width()/2, 0, winSize.width()/2, 0);
}


