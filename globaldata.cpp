#include "globaldata.h"
#include "gameitem.h"

GlobalData* globalData = NULL;

GlobalData* GlobalData::getInstance(){
    return globalData ? globalData : new GlobalData();
}

GlobalData::GlobalData(QObject *parent) :
    QObject(parent)
{
    itemList = loadItemData("item.bin");
}

QList<GameItem*>* GlobalData::loadItemData(const char* fileName)
{
    QList<GameItem*> *list = new QList<GameItem*>();
    FILE *fp = openFile(fileName);
    if(!fp){
        QDebug(QtWarningMsg) << "读取物品出错";
        return list;
    }

    skipBytes(fp, readInt(fp));

    int count = readInt(fp);
    for( int i = 0; i < count; i++){
        GameItem *gameItem = new GameItem();
        list->append(gameItem);

        gameItem->idx = readInt(fp);
        gameItem->name = readUTF(fp);
        gameItem->describe = readUTF(fp);
        gameItem->level = readInt(fp);
        gameItem->rank = readInt(fp);
        gameItem->buyPrice = readInt(fp);
        gameItem->salePrice = readInt(fp);
        gameItem->limitLevel = readInt(fp);

        gameItem->addHP = readInt(fp);
        gameItem->addAF = readInt(fp);
        gameItem->addDEF = readInt(fp);
    }

    closeFile(fp);

    QDebug(QtDebugMsg) << fileName << "加载"<<list->count()<<"个物品";
    return list;
}

bool GlobalData::saveItemData(const char* fileName)
{
//    QList<GameItem*> *list = new QList<GameItem*>();
//    FILE *fp = openFile(fileName);
//    if(!fp){
//        QDebug(QtWarningMsg) << "存储物品出错";
//        return list;
//    }

//    skipBytes(fp, readInt(fp));

//    int count = readInt(fp);
//    for( int i = 0; i < count; i++){
//        GameItem *gameItem = new GameItem();
//        list->append(gameItem);

//        saveInt(gameItem->idx, fp);
//        break;
////        gameItem->name = readUTF(fp);
////        gameItem->describe = readUTF(fp);
////        gameItem->level = readInt(fp);
////        gameItem->rank = readInt(fp);
////        gameItem->buyPrice = readInt(fp);
////        gameItem->salePrice = readInt(fp);
////        gameItem->limitLevel = readInt(fp);

////        gameItem->addHP = readInt(fp);
////        gameItem->addAF = readInt(fp);
////        gameItem->addDEF = readInt(fp);
//    }

//    closeFile(fp);
    return true;
}
