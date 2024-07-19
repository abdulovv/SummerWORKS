#pragma once

#include <QPushButton>
#include <QLabel>

#include "SceneManager.h"

class PropertyScene : public Scene{
    Q_OBJECT
private:
    QLabel* backgroundImage = nullptr;

public:
    PropertyScene() : Scene() {
    }
    PropertyScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        Scene::parentWidget = parent;
        this->sceneManager = sceneManager;
        Scene::sceneSize = screenSize;
        this->player = player;
    }
    void initScene() override;
    void hide() override;
    void show() override;


    ~PropertyScene() {
        clearScene();
    }

public slots:
    void update();

    
};















