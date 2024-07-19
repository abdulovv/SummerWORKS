#pragma once

#include <QLabel>
#include "SceneManager.h"

class MainMenuScene : public Scene{
    Q_OBJECT
private:
    QLabel* backgroundImage = nullptr;
    SceneManager* sceneManager = nullptr;
public:
    MainMenuScene() : Scene() { }
    MainMenuScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        Scene::parentWidget = parent;
        this->sceneManager = sceneManager;
        Scene::sceneSize = screenSize;
        this->player = player;
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
        sceneManager->goToScene(1);
    }
};
