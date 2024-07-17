#pragma once
#include "scene.h"
#include "qvector.h"

class SceneManager
{
public:
	QVector<Scene*> scenes;
	Scene* currentScene;

	SceneManager() { currentScene = nullptr; }

	void goToScene(int number);
	void nextScene();
	void previousScene();
	~SceneManager();
};

