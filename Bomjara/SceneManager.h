#pragma once

#include "scene.h"

class SceneManager : public QObject{
	Q_OBJECT	//for SLOTS usage
public:
	QVector<Scene*> scenes;
	Scene* currentScene;

	SceneManager() { currentScene = nullptr; }


	
	void nextScene();
	void previousScene();
    int getIndexOfScene(Scene* scene);
    ~SceneManager();
public slots:
    void goToScene(int number);

    void goToMenuScene() {
        goToScene(0);
    }

    void goToPlayerScene() {
        goToScene(1);
    }

    void goToMoneyScene() {
        goToScene(2);
    }

    void goToHealthScene() {
        goToScene(3);
    }

    void goToHapinnesScene() {
        goToScene(4);
    }

    void goToBusinessScene() {
        goToScene(5);
    }

    void goToCasinoScene() {
        goToScene(6);
    }

    void goToPropertyScene() {
        goToScene(7);
    }
};

