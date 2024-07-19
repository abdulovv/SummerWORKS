#pragma once

#include <QLabel>
#include "SceneManager.h"

class HealthScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons;
    QLabel* backgroundImage;
    SceneManager* sceneManager;

public:
    HealthScene() : Scene() {
        icons = nullptr; backgroundImage = nullptr;
    }

    HealthScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        icons = nullptr; backgroundImage = nullptr;
        Scene::parentWidget = parent;
        this->sceneManager = sceneManager;
        Scene::screenSize = screenSize;
        this->player = player;
    }

    void initScene() override;
    void hide() override;
    void show() override;
    void buttonCustomization() override;

    ~HealthScene() {
        if (icons != nullptr)
            delete[] icons;
    }

public slots:
    void goToMenuScene() {
        sceneManager->goToScene(0);
    }

    void goToPlayerScene(){
        sceneManager->goToScene(1);
    }

    void goToMoneyScene(){
        sceneManager->goToScene(2);
    }

    void goToHealthScene(){
        sceneManager->goToScene(3);
    }
};





