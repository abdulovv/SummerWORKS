#include "SceneManager.h"

void SceneManager::goToScene(int number) {
	scenes[number]->initScene();
	scenes[number]->show();
	if (currentScene != nullptr)
		currentScene->clearScene();
	currentScene = scenes[number];
}

SceneManager::~SceneManager() {
	for (int i = 0; i < scenes.size(); i++)
	{
		scenes[i]->~Scene();
	}
}