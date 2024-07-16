#pragma once
#include "scene.h"

class MenuScene : public Scene{
    Q_OBJECT
public:
    MenuScene(){}
    void initScene();

    void hide() override;
    void show(QMainWindow* parentWindow) override;

    ~MenuScene() {}
public slots:
    void hide_first();
};
