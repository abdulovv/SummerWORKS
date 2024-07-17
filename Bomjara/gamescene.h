#pragma once
#include "scene.h"
#include "QPushButton"
#include "qlabel.h"

class GameScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons;
    QLabel* backgroundImage;
public:
    GameScene() : Scene() {}
    void initScene(QWidget* parent, QSize screenSize = QSize(0, 0));

    void hide() override;
    void show() override;

    ~GameScene() {
        delete[] icons;
    }
public slots:

};
