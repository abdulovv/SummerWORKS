#pragma once
#include "QLabel"
#include "qpixmap.h"
#include "SceneManager.h"

class MenuScene : public Scene{
    Q_OBJECT
private:
    QLabel* backgroundImage;
    SceneManager* scenes;
public:
    MenuScene() : Scene() { backgroundImage = nullptr; }
    MenuScene(QWidget* parent, SceneManager* sceneManager, QSize screenSize = QSize(0, 0)) {
        backgroundImage = nullptr;
        Scene::parentWidget = parent;
        scenes = sceneManager;
        Scene::screenSize = screenSize;
    }


    void initScene() override;
    void hide() override;
    void show() override;

    ~MenuScene() {}
public slots:
    void goToGameScene() {
        scenes->goToScene(1);
    }
};
