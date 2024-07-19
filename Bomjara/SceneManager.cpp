#include "SceneManager.h"

void SceneManager::goToScene(int number) {
	scenes[number]->initScene();
	scenes[number]->show();

    if(currentScene != nullptr)
		currentScene->clearScene();

    currentScene = scenes[number];
}

int SceneManager::getIndexOfScene(Scene* scene)
{
	for (int i = 0; i < scenes.size(); i++)
		if (scenes[i] == scene)
			return i;
	return -1;
}

SceneManager::~SceneManager() {
    scenes.clear();
}
