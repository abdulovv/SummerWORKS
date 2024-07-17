#include "mainWindow.h"


Window::Window(QWidget *parent)
    : QMainWindow(parent){
    screenSize = QSize(QGuiApplication::primaryScreen()->size().width(),
                       QGuiApplication::primaryScreen()->size().height());
    
    MenuScene* menu = new MenuScene(this, &scenes, screenSize);
    GameScene* game = new GameScene(this, &scenes, screenSize);

    scenes.scenes.push_back(menu);
    scenes.scenes.push_back(game);
    scenes.goToScene(0);


    //connect(menu.objs[0], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
    //connect((QPushButton*)menu.objs[2], &QPushButton::clicked, qApp, &QApplication::quit);
    //connect(windowButtons[0], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));
    //connect(windowButtons[1], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
    //connect(game.objs[4], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));
}



Window::~Window() {
    //scenes.scenes.clear();
    delete scenes.currentScene;

}
