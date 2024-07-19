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
    PropertyScene(QWidget* parent, SceneManager* sceneManager, InputController* inputController,
        Player* player, QSize screenSize = QSize(0, 0)) : Scene(parent, sceneManager, inputController, player, screenSize)
    {

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















