#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "globaldata.h"
#include "qstringlistmodel.h"

#include <QFileDialog>
#include "gameimage.h"
#include "gamebutton.h"

#include <QAction>
#include <QGraphicsView>
#include "gamepaintwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QTabWidget *tabWidget = new QTabWidget(this);
//    this->setCentralWidget(tabWidget);

//    QWidget *itemWidget = initItemTreeWidget();
//    tabWidget->addTab(itemWidget, QString("物品"));

//    QWidget * unitsWidget = new QWidget(tabWidget);
//    tabWidget->addTab(unitsWidget, QString("单位"));

    QAction *actionAddImage = new QAction(QString("添加图片"), this);
    ui->mainToolBar->addAction(actionAddImage);
    QAction *actionAddButton = new QAction(QString("添加按钮"), this);
    ui->mainToolBar->addAction(actionAddButton);

    connect( actionAddImage, SIGNAL(triggered()), this, SLOT(actionAddSprite()));
    connect( actionAddButton, SIGNAL(triggered()), this, SLOT(actionAddButton()));

    scene = new GamePaintWindow(QSize(960, 640));
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::actionAddSprite()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                   tr("Add Image"),
                                                    QDir::currentPath(),
                                                   tr("PNG Files(*.png)"));
    if(!path.isEmpty()) {
        addSprite(path);
        return true;
     }
    return false;
}
bool MainWindow::actionAddButton()
{
    addButton();
    return false;
}

bool MainWindow::addSprite(QString &file)
{
    GameImage *image = new GameImage(file);
    if(image){
        scene->addItem(image);
        return true;
    }

    return false;
}
bool MainWindow::addButton()
{
    GameButton *btn = new GameButton();
    if(btn){
        scene->addItem(btn);
        return true;
    }

    return false;
}

bool MainWindow::saveIniFile()
{
//    QSettings *ConfigIni = new QSettings( INI_FILE_NAME,QSettings::IniFormat,0);
//   // ConfigIni->writeEntry(QString::fromUtf8("/config./opt/参数1"), QString::fromUtf8("中文"));
//    ConfigIni->setValue("node1", "this is value");
//    delete ConfigIni;
//    qDebug() <<"save";
    return true;
}
bool MainWindow::loadIniFile()
{
//    QSettings *ConfigIni = new QSettings("D:\\a.ini",QSettings::IniFormat,0);
//    ui->lineEdit_2->setText(ConfigIni->value("/config/node1","20").toString());
//    delete ConfigIni;
//    QSettings *ConfigIni = new QSettings("D:\\a.ini",QSettings::IniFormat,0); ui->lineEdit_2->setText(ConfigIni->value("/config/node1","20").toString()); delete ConfigIni;
    return true;
}

bool MainWindow::initFileList()
{
    QDockWidget *leftDockWidget = new QDockWidget(this);
    leftDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    this->addDockWidget( Qt::LeftDockWidgetArea, leftDockWidget);

    fileTreeWidget = new QTreeWidget();
    leftDockWidget->setWidget(fileTreeWidget);

    return true;
}

QWidget *MainWindow::initItemTreeWidget()
{
    QList<GameItem *> *itemList = GlobalData::getInstance()->itemList;

    QTableWidget *tableWidget = new QTableWidget(itemList->count(), 11); // 构造了一个QTableWidget的对象，并且设置为10行，5列
    tableWidget->setWindowTitle("QTableWidget & Item");
    QStringList header;
    header <<"ID" << "名字" << "描述" << "装备等级"<< "颜色"<< "购买价格"<< "出售价格"<< "等级限制"<< "生命上限"<< "攻击"<< "防御";
    tableWidget->setHorizontalHeaderLabels(header);

    for( int i = 0; i < itemList->count(); i++)
    {
        GameItem *item = itemList->at(i);
        tableWidget->setItem( i, 0,new QTableWidgetItem( QString::number(item->idx)));
        tableWidget->setItem( i, 1,new QTableWidgetItem( item->name));
        tableWidget->setItem( i, 2,new QTableWidgetItem( item->describe));
        tableWidget->setItem( i, 3,new QTableWidgetItem(QString::number(item->level)));
        tableWidget->setItem( i, 4,new QTableWidgetItem(QString::number(item->rank)));
        tableWidget->setItem( i, 5,new QTableWidgetItem(QString::number(item->buyPrice)));
        tableWidget->setItem( i, 6,new QTableWidgetItem(QString::number(item->salePrice)));
        tableWidget->setItem( i, 7,new QTableWidgetItem(QString::number(item->limitLevel)));
        tableWidget->setItem( i, 8,new QTableWidgetItem(QString::number(item->addHP)));
        tableWidget->setItem( i, 9,new QTableWidgetItem(QString::number(item->addAF)));
        tableWidget->setItem( i, 10,new QTableWidgetItem(QString::number(item->addDEF)));
    }

    return tableWidget;
}

void saveItemData(QTableWidget *widget)
{
    QList<GameItem *> *itemList = GlobalData::getInstance()->itemList;
    for( int i = 0; i < widget->rowCount(); i++)
    {
        GameItem *item = itemList->at(i);
        item->idx = widget->item( i, 0)->text().toInt();
        item->name = widget->item( i, 1)->text();
        item->describe = widget->item( i, 2)->text();
        item->level = widget->item( i, 3)->text().toInt();
        item->rank = widget->item( i, 4)->text().toInt();
        item->buyPrice = widget->item( i, 5)->text().toInt();
        item->salePrice = widget->item( i, 6)->text().toInt();
        item->limitLevel = widget->item( i, 7)->text().toInt();
        item->addHP = widget->item( i, 8)->text().toInt();
        item->addAF = widget->item( i, 9)->text().toInt();
        item->addDEF = widget->item( i, 10)->text().toInt();
    }
}


//QWidget *MainWindow::initItemWidget()
//{
//    QTreeWidget *infoListWidget = new QTreeWidget();
//    GlobalData *globalData = GlobalData::getInstance();
//    QStringList infoTitles;
//    infoTitles <<"ID" << "名字" << "描述" << "装备等级"<< "颜色"<< "购买价格"<< "出售价格"<< "等级限制"<< "生命上限"<< "攻击"<< "防御";
//    infoListWidget->setHeaderLabels(infoTitles);

//    for( QList <GameItem *>::Iterator itr = globalData->itemList->begin(); itr != globalData->itemList->end(); itr++)
//    {
//        GameItem *item = *itr;
//        QStringList itemStringList;
//        itemStringList << QString::number(item->idx)
//                       << item->name
//                       << item->describe
//                       << QString::number(item->level)
//                       << QString::number(item->rank)
//                       << QString::number(item->buyPrice)
//                       << QString::number(item->salePrice)
//                       << QString::number(item->limitLevel)
//                       << QString::number(item->addHP)
//                       << QString::number(item->addAF)
//                       << QString::number(item->addDEF);

//        infoListWidget->addTopLevelItem(new QTreeWidgetItem((QTreeWidget*)0, itemStringList));
//        //nameListWidget->addItem(item->name);
//    }
//    return infoListWidget;
//}

//init item
/*for( QList <GameItem *>::Iterator itr = globalData->itemList->begin(); itr != globalData->itemList->end(); itr++)
{
    GameItem *item = *itr;
    fileListWidget->addItem(item->name);
}*/


