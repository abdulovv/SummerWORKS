#include "SceneManager.h"

void SceneManager::goToScene(int number) {
	scenes[number]->initScene();
	scenes[number]->show();
	if (currentScene != nullptr)
		currentScene->clearScene();
	currentScene = scenes[number];
}

SceneManager::~SceneManager() {
	scenes.clear();
}