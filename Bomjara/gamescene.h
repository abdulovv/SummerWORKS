#pragma once
#include "QPushButton"
#include "qlabel.h"
#include "SceneManager.h"

class GameScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons;
    QLabel* backgroundImage;
    SceneManager* scenes;
public:
    GameScene() : Scene() {}
    GameScene(QWidget* parent, SceneManager* sceneManager, QSize screenSize = QSize(0, 0)) {
        Scene::parentWidget = parent;
        scenes = sceneManager;
        Scene::screenSize = screenSize;
    }
    void initScene() override;
    void hide() override;
    void show() override;

    ~GameScene() {
        delete[] icons;
    }
public slots:
    void goToMenuScene() {
        scenes->goToScene(0);
    }
};
