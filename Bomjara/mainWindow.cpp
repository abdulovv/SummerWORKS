#include "mainWindow.h"


Window::Window(QWidget *parent)
    : QMainWindow(parent){
    screenSize = QSize(QGuiApplication::primaryScreen()->size().width(),
                       QGuiApplication::primaryScreen()->size().height());
    

    scenes.scenes.push_back(new MenuScene(this, &scenes, player, screenSize));
    scenes.scenes.push_back(new GameScene(this, &scenes, player, screenSize));
    scenes.scenes.push_back(new MoneyScene(this, &scenes, player, screenSize));
    scenes.goToScene(0);
}



Window::~Window() {
    delete scenes.currentScene;

}
