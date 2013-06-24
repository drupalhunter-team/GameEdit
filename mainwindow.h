#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Prefix.h"
#include "config.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool addSprite(QString &file);
private:
    Ui::MainWindow *ui;
    QTreeWidget *fileTreeWidget;

    QString workspace;

    bool initFileList();

    QWidget *initItemTreeWidget();

    bool loadIniFile();

    QGraphicsScene *scene;
    QGraphicsView *view;

private slots:
    bool saveIniFile();
    bool actionAddSprite();
};

#endif // MAINWINDOW_H
