#pragma once

#include <QWidget>
#include <QObject>

#include "Player.h"

class Scene : public QObject{
    Q_OBJECT
protected:
    
public:
    QSize screenSize;
    QWidget* parentWidget;
    QVector<QWidget*> objs;
    Player* player;

    Scene() { parentWidget = nullptr; player = nullptr; }

    virtual void initScene() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;

    void clearScene(){
        for (int i = 0; i < objs.size(); i++)
            objs[i]->~QWidget();

        objs.clear();
    }

    ~Scene() {
        clearScene();
    }
};
