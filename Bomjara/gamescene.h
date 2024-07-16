#pragma once
#include "scene.h"

class GameScene : public Scene{
    Q_OBJECT
public:
    GameScene(){}
    void initScene();

    void hide() override;
    void show(QMainWindow* parentWindow) override;

    ~GameScene() {}
public slots:

};
