#include "mainWindow.h"


Window::Window(QWidget *parent)
    : QMainWindow(parent){
    screenSize = QSize(QGuiApplication::primaryScreen()->size().width(),
                       QGuiApplication::primaryScreen()->size().height());

    menu.initScene(this, screenSize);
    menu.show();
    currentScene = &menu;

    initWindowButtons();

    connect(menu.objs[0], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
    connect((QPushButton*)menu.objs[2], &QPushButton::clicked, qApp, &QApplication::quit);
    connect(windowButtons[0], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));
    connect(windowButtons[1], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
}


void Window::initWindowButtons(){
    const int COUNT_OF_WINDOWBUTTONS = 6;

    float widthButton = (screenSize.width() * 5 / 7) / COUNT_OF_WINDOWBUTTONS;
    float step = (screenSize.width() * 2 / 7) / (COUNT_OF_WINDOWBUTTONS + 1);

    windowButtons.push_back(new QPushButton("MENU", this));
    windowButtons.push_back(new QPushButton("GAME", this));
    windowButtons.push_back(new QPushButton("SHOP", this));
    windowButtons.push_back(new QPushButton("WORK", this));
    windowButtons.push_back(new QPushButton("LIFE", this));
    windowButtons.push_back(new QPushButton("SLEEP", this));

    float currentPosX = step;
    for(int i = 0; i < COUNT_OF_WINDOWBUTTONS; i++){
        windowButtons[i]->setGeometry(currentPosX, screenSize.height() - 150, widthButton, 50);
        currentPosX += (widthButton+step);
        windowButtons[i]->hide();
    }
}

void Window::showWindowButtons(){
    for(QPushButton* currButton : windowButtons){
        currButton->show();
        currButton->setEnabled(true);
    }
}

void Window::hideWindowButtons(){
    for(QPushButton* currButton : windowButtons){
        currButton->hide();
    }
}

void Window::goToGameScene(){
    if (currentScene != (Scene*)&game) {
        currentScene->hide();
        if (game.objs.size() == 0)
            game.initScene(this, screenSize - QSize(0, 100));
        game.show();
        currentScene = &game;
        showWindowButtons();
        windowButtons[1]->setEnabled(false);
    }
}

void Window::goToMenuScene(){
    currentScene->hide();
    menu.show();
    currentScene = &menu;
    hideWindowButtons();
}

Window::~Window() {
    menu.~MenuScene();
    game.~GameScene();
    windowButtons.clear();
}
