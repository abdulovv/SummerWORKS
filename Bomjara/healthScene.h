#pragma once

#include <QLabel>
#include "SceneManager.h"

class HealthScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons = nullptr;
    QLabel* backgroundImage = nullptr;

public:
    HealthScene() : Scene() {
    }

    HealthScene(QWidget* parent, SceneManager* sceneManager, InputController* inputController,
        Player* player, QSize screenSize = QSize(0, 0)) : Scene(parent, sceneManager, inputController, player, screenSize)
    {

    }

    void initScene() override;
    void hide() override;
    void show() override;

    ~HealthScene() {
        clearScene();
    }

public slots:
    
};





