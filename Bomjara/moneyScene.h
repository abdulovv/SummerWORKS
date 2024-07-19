#pragma once

#include <QLabel>
#include "SceneManager.h"

class MoneyScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons = nullptr;
    QLabel* backgroundImage = nullptr;
    //SceneManager* sceneManager = nullptr;

public:
    MoneyScene() : Scene() {
    }

    MoneyScene(QWidget* parent, SceneManager* sceneManager, InputController* inputController,
        Player* player, QSize screenSize = QSize(0, 0)) : Scene(parent, sceneManager, inputController, player, screenSize)
    {

    }

    void initScene() override;
    void hide() override;
    void show() override;

    ~MoneyScene() {
        clearScene();
    }

public slots:
    
};
