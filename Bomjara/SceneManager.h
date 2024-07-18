#pragma once

#include <QVector>

#include "scene.h"

class SceneManager{
public:
	QVector<Scene*> scenes;
	Scene* currentScene;

	SceneManager() { currentScene = nullptr; }

	void goToScene(int number);
	void nextScene();
	void previousScene();
	~SceneManager();
};

