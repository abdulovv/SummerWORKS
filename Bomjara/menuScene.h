#pragma once
#include "scene.h"

class menuScene : public Scene{
    Q_OBJECT
public:
    menuScene(){}
    void initScene();
    ~menuScene() {}
public slots:
    void hide_first();
};
