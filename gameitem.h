#ifndef GAMEITEM_H
#define GAMEITEM_H

#include "Prefix.h"

class GameItem :public QObject
{
public:
    GameItem();

public:
    int idx;
    QString name;
    QString describe;
    int level;
    int rank;
    int buyPrice;
    int salePrice;
    int limitLevel;

    int addHP;
    int addAF;
    int addDEF;
};

#endif // GAMEITEM_H
