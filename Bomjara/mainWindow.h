#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QPixmap>
#include <QLabel>
#include <QPair>
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
    MenuScene menu;
    GameScene game;




    void initWindowButtons();
    void showWindowButtons();
    void hideWindowButtons();
private slots:

    void goToGameScene();
    void goToMenuScene();
};
#endif // MAINWINDOW_H
