#pragma once
#include "QPushButton"
#include "qlabel.h"
#include "SceneManager.h"
#include "QMainWindow"

class GameScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons;
    QLabel* backgroundImage;
    SceneManager* scenes;

    void addButtons(QVector<QWidget*> objs);
public:
    GameScene() : Scene() {
        icons = nullptr; backgroundImage = nullptr;
    }
    GameScene(QWidget* parent, SceneManager* sceneManager, QSize screenSize = QSize(0, 0)) {
        icons = nullptr; backgroundImage = nullptr;
        Scene::parentWidget = parent;
        scenes = sceneManager;
        Scene::screenSize = screenSize;
    }
    void initScene() override;
    void hide() override;
    void show() override;

    ~GameScene() {
        if (icons != nullptr)
            delete[] icons;
    }
public slots:
    void goToMenuScene() {
        scenes->goToScene(0);
    }
};
