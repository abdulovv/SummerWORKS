#pragma once

#include <QLabel>
#include "SceneManager.h"

class HealthScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons = nullptr;
    QLabel* backgroundImage = nullptr;
    SceneManager* sceneManager = nullptr;

public:
    HealthScene() : Scene() {
    }

    HealthScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
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
        clearScene();
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

    void goToHappinnesScene(){
        sceneManager->goToScene(4);
    }
};





