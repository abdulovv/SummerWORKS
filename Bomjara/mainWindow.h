#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qapplication.h"
#include <QScreen>
#include <QPushButton>
#include "menuScene.h"
#include "gamescene.h"


class Window : public QMainWindow{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr);
    ~Window();
private:
    QVector<QPushButton*> windowButtons;
    Scene* currentScene;
    //MenuScene menu;
    //GameScene game;
    QSize screenSize;
    SceneManager scenes;

    void initWindowButtons();
    void showWindowButtons();
    void hideWindowButtons();
private slots:
    //void goToGameScene();
    //void goToMenuScene();
};
#endif // MAINWINDOW_H
