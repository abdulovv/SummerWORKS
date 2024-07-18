#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qapplication.h"
#include <QScreen>
#include <QPushButton>
#include "menuScene.h"
#include "gamescene.h"
#include "moneyScene.h"


class Window : public QMainWindow{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr);
    ~Window();
private:
    QVector<QPushButton*> windowButtons;
    Scene* currentScene;
    Player* player;

    QSize screenSize;
    SceneManager scenes;

private slots:

};
#endif // MAINWINDOW_H
