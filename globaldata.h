#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include "Prefix.h"

class GlobalData : public QObject
{
    Q_OBJECT
private:
    explicit GlobalData(QObject *parent = 0);
    
signals:
    
public slots:
    bool saveItemData(const char* fileName);

public:
    QList<GameItem*> *itemList;
   // QList *unitList;

public:
    QList<GameItem*>* loadItemData(const char* fileName);

    static GlobalData* getInstance();
};

#endif // GLOBALDATA_H
