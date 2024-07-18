#pragma once
#include "QPushButton"
#include "qlabel.h"
#include "SceneManager.h"

class MoneyScene : public Scene{
    Q_OBJECT
private:
    QLabel* icons;
    QLabel* backgroundImage;
    SceneManager* scenes;

    void addButtons(QVector<QWidget*> objs);
public:
    MoneyScene() : Scene() {
        icons = nullptr; backgroundImage = nullptr;
    }

    MoneyScene(QWidget* parent, SceneManager* sceneManager, Player* player, QSize screenSize = QSize(0, 0)) {
        icons = nullptr; backgroundImage = nullptr;
        Scene::parentWidget = parent;
        scenes = sceneManager;
        Scene::screenSize = screenSize;
        this->player = player;
    }

    void initScene() override;
    void hide() override;
    void show() override;

    ~MoneyScene() {
        if (icons != nullptr)
            delete[] icons;
    }

public slots:
    void goToMenuScene() {
        scenes->goToScene(0);
    }

    void goToGameScene_1() {
        scenes->goToScene(1);
    }

    void goToGameScene_2() {
        scenes->goToScene(2);
    }

};
