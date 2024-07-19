#include "mainWindow.h"
#include "healthScene.h"
#include "mainMenuScene.h"
#include "moneyScene.h"
#include "playerScene.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent){

    screenSize = QSize(QGuiApplication::primaryScreen()->size().width(),
                       QGuiApplication::primaryScreen()->size().height());

    sceneManager.scenes.push_back(new MainMenuScene(this, &sceneManager, player, screenSize));
    sceneManager.scenes.push_back(new PlayerScene(this, &sceneManager, player, screenSize));
    sceneManager.scenes.push_back(new MoneyScene(this, &sceneManager, player, screenSize));
    sceneManager.scenes.push_back(new HealthScene(this, &sceneManager, player, screenSize));

    sceneManager.goToScene(0);
}

Window::~Window() {
    delete sceneManager.currentScene;
}
