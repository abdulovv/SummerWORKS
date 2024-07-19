#pragma once

#include <QLabel>
#include "SceneManager.h"
#include "scene.h"

class CasinoScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons = nullptr;
    QLabel* backgroundImage = nullptr;
    //SceneManager* sceneManager = nullptr;

public:
    CasinoScene() : Scene() {
    }

    CasinoScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        Scene::parentWidget = parent;
        this->sceneManager = sceneManager;
        Scene::sceneSize = screenSize;
        this->player = player;
    }

    void initScene() override;
    void hide() override;
    void show() override;

    ~CasinoScene() {
        clearScene();
    }

public slots:
    
};
