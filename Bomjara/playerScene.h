#pragma once

#include <QPushButton>
#include <QLabel>

#include "SceneManager.h"

class PlayerScene : public Scene{
    Q_OBJECT
private:

    QLabel* backgroundImage = nullptr, *bomj = nullptr;
    
    
public:
    PlayerScene() : Scene() {
    }
    PlayerScene(QWidget* parent, SceneManager* sceneManager, InputController* inputController,
        Player* player, QSize screenSize = QSize(0, 0)) : Scene(parent, sceneManager, inputController, player, screenSize)
    {

    }
    void initScene() override;
    void hide() override;
    void show() override;
    
    ~PlayerScene() {
        clearScene();

    }

private slots:
    void update();
    void keyPressedSlot(int key);
    
};














