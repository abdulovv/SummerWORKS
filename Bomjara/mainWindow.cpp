#include "mainWindow.h"
#include "healthScene.h"
#include "mainMenuScene.h"
#include "moneyScene.h"
#include "playerScene.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent){

    QPixmap iconTexture(":/Icon.png");
    QIcon icon(iconTexture);
    this->setWindowIcon(icon);

    screenSize = QSize(QGuiApplication::primaryScreen()->size().width(),
                       QGuiApplication::primaryScreen()->size().height());
    player = new Player();
    sceneManager.scenes.push_back(new MainMenuScene(this, &sceneManager, player, screenSize));
    sceneManager.scenes.push_back(new PlayerScene(this, &sceneManager, player, screenSize));
    sceneManager.scenes.push_back(new MoneyScene(this, &sceneManager, player, screenSize));
    sceneManager.scenes.push_back(new HealthScene(this, &sceneManager, player, screenSize));

    sceneManager.goToScene(0);
}

Window::~Window() {
    delete sceneManager.currentScene;
}
