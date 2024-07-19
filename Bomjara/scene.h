#pragma once

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include "qlabel.h"
#include "Player.h"

class Scene : public QObject{
    Q_OBJECT
protected:
    
public:
    QSize sceneSize;
    QWidget* parentWidget;
    QVector<QWidget*> objs;
    Player* player;
    QObject* sceneManager;

    Scene() { parentWidget = nullptr; player = nullptr; }

    virtual void initScene() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;


    void clearScene();
    int getIndexOfObjectByName(QString name);
    void addMainButtons(int currentSceneIndex);

    void addPlayerValuesHUD();



    ~Scene() {
    }
};
