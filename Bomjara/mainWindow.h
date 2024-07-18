#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>

#include "SceneManager.h"
#include "scene.h"

class Window : public QMainWindow{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr);
    ~Window();
private:
    Scene* currentScene;
    Player* player;

    QSize screenSize;
    SceneManager sceneManager;

private slots:

};
#endif // MAINWINDOW_H
