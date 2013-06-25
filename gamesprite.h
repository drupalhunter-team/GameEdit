#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <QGraphicsItemGroup>

class DLAction: QObject
{
public:
    DLAction(){
        framesIDSet = new QList<int>();
        delayTimeSet = new QList<int>();
    }
    ~DLAction(){
        delete framesIDSet;
        framesIDSet = NULL;
        delete delayTimeSet;
        delayTimeSet = NULL;
    }

    QList<int> *framesIDSet;
    QList<int> *delayTimeSet;
};

class GameSprite : public QGraphicsItemGroup, public QObject
{
public:
    GameSprite(QString &file);
    ~GameSprite();

    enum eModuleTypeIdx
    {
        MTI_IMG=0,	//图
        MTI_LINE,		//线
        MTI_RECT,		//矩形
        MTI_RECT_FILL,//填充矩形
        MTI_TRI,		//三角形
        MTI_TRI_FILL,	//填充三角形
        MTI_ARC,		//弧形
        MTI_ARC_FILL,	//填充弧形
        MTI_R_RECT,	//圆角矩形
        MTI_R_RECT_FILL,//填充圆角矩形
        MTI_STR	//文字
    };

private:
    QList<QGraphicsItemGroup*> *frameList;
    QList<DLAction*> *actionList;
    QGraphicsItemGroup *currentFrame;
    int currentActionID;
    int currentActionIndex;
    int currentDelayTime;

    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool loadBin(QString &file);
    void startAction(int actionID);
    void showFrame(int frameID);

    int m_nTimerId;

    void timerEvent( QTimerEvent *event );
private slots:
};

#endif // GAMESPRITE_H
