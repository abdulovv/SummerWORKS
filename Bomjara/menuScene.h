#pragma once
#include "scene.h"

class MenuScene : public Scene{
    Q_OBJECT
public:
    MenuScene(){}
    void initScene();
    ~MenuScene() {}
public slots:
    void hide_first();
};
