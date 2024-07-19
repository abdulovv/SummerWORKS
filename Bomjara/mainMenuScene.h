#pragma once

#include <QLabel>
#include "SceneManager.h"

class MainMenuScene : public Scene{
    Q_OBJECT
private:
    QLabel* backgroundImage = nullptr;
    SceneManager* scenes;
public:
    MainMenuScene() : Scene() { }
    MainMenuScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        Scene::parentWidget = parent;
        scenes = sceneManager;
        Scene::screenSize = screenSize;
        this->player = player;
    }


    void initScene() override;
    void hide() override;
    void show() override;
    void buttonCustomization() override;

    void addMainButtons();

    ~MainMenuScene() {
        clearScene();
    }
public slots:
    void goToGameScene() {
        scenes->goToScene(1);
    }
};
