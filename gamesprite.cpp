#include "gamesprite.h"
#include <QMessageBox>
#include <QList>
#include "gameimage.h"
#include "qdir.h"

extern "C"{
#include "DLFile.h"
};
#include "config.h"
#include <QDebug>
#include <QTimeLine>

GameSprite::GameSprite(QString &file):
    currentActionID(0),
    currentActionIndex(0),
    currentDelayTime(0),
    currentFrame(NULL)
{
    loadBin(file);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);

    startAction(0);

    m_nTimerId = startTimer(1000/60);
    qDebug()<<"构造";
}
GameSprite::~GameSprite()
{
    if(m_nTimerId)
        killTimer(m_nTimerId);
}

void GameSprite::timerEvent( QTimerEvent *event )
{
    float time = 1000/60;
    currentDelayTime += time;

    DLAction *action = actionList->at(currentActionID);
    float macDelayTime = action->delayTimeSet->at(currentActionIndex);

    if(currentDelayTime >= macDelayTime)
    {
        currentDelayTime = 0;
        if(++currentActionIndex >= action->framesIDSet->count())
            currentActionIndex = 0;
        showFrame(action->framesIDSet->at(currentActionIndex));
    }

}
bool GameSprite::loadBin(QString &file)
{
    FILE *fp = openFile(file.toUtf8());

    if(!fp){
        qDebug()<<"打开失败";
        QMessageBox::critical(NULL, "错误", "未能读取精灵", QMessageBox::Yes, QMessageBox::Yes);
        return false;
    }
    QStringList *imageList = new QStringList();
    QStringList *moduleList = new QStringList();
    frameList = new QList<QGraphicsItemGroup*>();
    actionList = new QList<DLAction*>();

    int image_length = readShort(fp);	//读取图片数量

    for( int i = 0; i < image_length; ++i )			// 读图片名称
    {
        imageList->append(QString(readUTF(fp)));
    }

    int module_length = readShort(fp);	// 读模块
    if ( module_length > 0)
    {
        for( int i = 0; i < module_length; i++)
        {
            int type = readByte(fp);
            switch(type)
            {
                case MTI_IMG:
                {
                    /*float x = */readShort(fp);
                    /*float y = */readShort(fp);
                    /*float w = */readShort(fp);
                    /*float h = */readShort(fp);
                    int idx = readShort(fp);
                    QString string = imageList->at(idx);
                    moduleList->append(string);
                }
                    break;//图
                case MTI_LINE:
                    /*pModule->color = */readInt(fp);
                    /*pModule->width = */readShort(fp);
                    /*pModule->height = */readShort(fp);
                    break;//线
                case MTI_RECT:
                    /*pModule->color = */readInt(fp);
                    /*pModule->width = */readShort(fp);
                    /*pModule->height = */readShort(fp);
                    break;//矩形
                case MTI_RECT_FILL:
                    /*pModule->color = */readInt(fp);
                    /*pModule->width = */readShort(fp);
                    /*pModule->height = */readShort(fp);
                    break;//填充矩形
                case MTI_TRI:
                case MTI_TRI_FILL:	//填充三角形
                case MTI_ARC:		//弧形
                case MTI_ARC_FILL:	//填充弧形
                case MTI_R_RECT:	//圆角矩形
                case MTI_R_RECT_FILL://填充圆角矩形
                    /*pModule->color = */readInt(fp);
                    /*pModule->width = */readShort(fp);
                    /*pModule->height = */readShort(fp);
                    /*ptr_module->attr3x = */readShort(fp);
                    /*ptr_module->attr3y = */readShort(fp);
                    break;//三角形
                case MTI_STR:
                    break;//文字
                default:
                    break;//文字
            }
        }
    }

    // 读出frame
    int frame_length = readShort(fp);
    if( frame_length > 0 )
    {
        for( int i = 0; i < frame_length; ++i)
        {
            QGraphicsItemGroup *frame = new QGraphicsItemGroup();
            int moduleCount = readShort(fp);
            if( moduleCount > 0 )
            {
                for( int j = 0; j < moduleCount; ++j)
                {
                    int mid = readShort(fp);
                    int module_x = readShort(fp);
                    int module_y = readShort(fp);
                    int rotate = readByte(fp);
                    QString image = moduleList->at(mid);
                    image = GET_IMAGE_PATH(image);
                    qDebug()<<image;
                    GameImage *module = new GameImage(image);
                    module->setPos( module_x, module_y);
                    module->rotateSprite(rotate);

                    frame->addToGroup(module);
                }
            }

            int collisum = readByte(fp);
            if( collisum > 0 )
            {
                for( int j = 0; j < collisum; ++j )
                {
                    readShort(fp);
                    readShort(fp);
                    readShort(fp);
                    readShort(fp);
                    readShort(fp);
                }
            }
            frameList->append(frame);
        }
    }

    // 读出action
    int action_length = readShort(fp);
    if( action_length > 0 )
    {
        for( int i = 0; i < action_length; ++i)
        {
            DLAction *action = new DLAction();
            /*int type = */readByte(fp);
            int size = readShort(fp);

            for( int j = 0; j < size; ++j )
            {
                int frame_id = readShort(fp);
                int delayTime = readShort(fp);

                action->framesIDSet->append(frame_id);
                action->delayTimeSet->append(delayTime);
            }
            actionList->append(action);
        }
    }

    closeFile(fp);
    fp = 0;

    return true;
}

void GameSprite::startAction(int actionID)
{
   DLAction *action = actionList->at(actionID);
   int frameID = action->framesIDSet->at(currentActionIndex);
   currentActionID = actionID;
   currentActionIndex = 0;
   showFrame(frameID);

}

void GameSprite::showFrame(int frameID)
{
    QGraphicsItemGroup *group = frameList->at(frameID);

}

//void GameSprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QGraphicsItemGroup::paint(painter, option, widget);
//}
