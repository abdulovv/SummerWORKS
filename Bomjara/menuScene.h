#pragma once
#include "scene.h"
#include "QLabel"
#include "qpixmap.h"

class MenuScene : public Scene{
    Q_OBJECT
private:
    QLabel* backgroundImage;
public:
    MenuScene() : Scene() {}
    void initScene(QWidget* parent, QSize screenSize = QSize(0, 0));

    void hide() override;
    void show() override;

    ~MenuScene() {}
public slots:

};
