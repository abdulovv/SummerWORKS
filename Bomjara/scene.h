#pragma once

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include "qlabel.h"
#include "Player.h"
#include "InputController.h"

class Scene : public QObject{
    Q_OBJECT
protected:
    
public:
    QSize sceneSize;
    QWidget* parentWidget;
    QVector<QWidget*> objs;
    Player* player;
    QObject* sceneManager;
    InputController* inputController;

    Scene() { parentWidget = nullptr; player = nullptr; sceneManager = nullptr; inputController = nullptr; }

    Scene(QWidget* parent, QObject* sceneManager, InputController* inputController, Player* player, QSize screenSize = QSize(0, 0)) {
        parentWidget = parent;
        this->sceneManager = sceneManager;
        sceneSize = screenSize;
        this->player = player;
        this->inputController = inputController;
    }
    virtual void initScene() = 0;
    virtual void hide() = 0;
    virtual void show() = 0;


    void clearScene();
    int getIndexOfObjectByName(QString name);
    void addMainButtons(int currentSceneIndex);

    void addPlayerValuesHUD(QSize positionFromRTCorner = {350, 80}, 
        QSize iconsSize = { 40, 40 }, QSize spacings = {50, 80}, float barsLenght = 200);

    

    ~Scene() {
    }
};
