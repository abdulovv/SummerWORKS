#pragma once

#include <QLabel>
#include "SceneManager.h"

class MainMenuScene : public Scene{
    Q_OBJECT
private:
    QLabel* backgroundImage = nullptr;
public:
    MainMenuScene() : Scene() { }
    MainMenuScene(QWidget* parent, SceneManager* sceneManager, InputController* inputController,
        Player* player, QSize screenSize = QSize(0, 0)) : Scene(parent, sceneManager, inputController, player, screenSize)
    {

    }


    void initScene() override;
    void hide() override;
    void show() override;

    void addMainButtons();

    ~MainMenuScene() {
        clearScene();
    }
public slots:
    void goToGameScene() {
        static_cast<SceneManager*>(sceneManager)->goToScene(1);
    }
};
