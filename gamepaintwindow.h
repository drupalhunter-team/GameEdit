#ifndef GAMEPAINTWINDOW_H
#define GAMEPAINTWINDOW_H

#include <QGraphicsScene>

class GamePaintWindow : public QGraphicsScene
{
    Q_OBJECT
public:
    GamePaintWindow( QSize winSize, QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // GAMEPAINTWINDOW_H
