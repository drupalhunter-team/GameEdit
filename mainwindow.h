#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Prefix.h"
#include "config.h"

#include "gamepaintwindow.h"


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
    bool addButton();

private:
    Ui::MainWindow *ui;
    QTreeWidget *fileTreeWidget;

    QString workspace;

    bool initFileList();

    QWidget *initItemTreeWidget();

    bool loadIniFile();

    GamePaintWindow *scene;

private slots:
    bool saveIniFile();
    bool actionAddSprite();
    bool actionAddButton();
};

#endif // MAINWINDOW_H
