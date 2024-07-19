#pragma once

#include <QPushButton>
#include <QLabel>

#include "SceneManager.h"

class PropertyScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons = nullptr, *horizontalBars, *horizontalBarsFrames;
    QLabel* backgroundImage = nullptr;
    SceneManager* sceneManager = nullptr;

public:
    PropertyScene() : Scene() {
    }
    PropertyScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        Scene::parentWidget = parent;
        this->sceneManager = sceneManager;
        Scene::screenSize = screenSize;
        this->player = player;
    }
    void initScene() override;
    void hide() override;
    void show() override;
    void buttonCustomization() override;

    ~PropertyScene() {
        clearScene();
    }

public slots:
    void update();

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

    void goToBusinessScene(){
        sceneManager->goToScene(5);
    }

    void goToCasinoScene(){
        sceneManager->goToScene(6);
    }

    void goToPropertyScene(){
        sceneManager->goToScene(7);
    }
};















