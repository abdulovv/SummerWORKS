#pragma once

#include <QLabel>
#include "SceneManager.h"

class MainMenuScene : public Scene{
    Q_OBJECT
private:
    QLabel* backgroundImage;
    SceneManager* scenes;
public:
    MainMenuScene() : Scene() { backgroundImage = nullptr; }
    MainMenuScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        backgroundImage = nullptr;
        Scene::parentWidget = parent;
        scenes = sceneManager;
        Scene::screenSize = screenSize;
        this->player = player;
    }


    void initScene() override;
    void hide() override;
    void show() override;
    void addButtons();

    ~MainMenuScene() {}
public slots:
    void goToGameScene() {
        scenes->goToScene(1);
    }
};
