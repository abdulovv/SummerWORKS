#include "mainWindow.h"
#include "qapplication.h"
#include "menuScene.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent){
    menu.centalWidget = this;

    menu.initScene();
    menu.show(this);
    currentScene = &menu;

    initWindowButtons();

    connect(menu.objs[0], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
    //connect(menu.objs[1], SIGNAL(clicked(bool)), this, SLOT(showWindowButtons()));
    connect((QPushButton*)menu.objs[2], &QPushButton::clicked, qApp, &QApplication::quit);
    connect(windowButtons[0], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));
    connect(windowButtons[1], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
}


void Window::initWindowButtons(){
    int height = QGuiApplication::primaryScreen()->size().height();
    int width = QGuiApplication::primaryScreen()->size().width();

    const int COUNT_OF_WINDOWBUTTONS = 6;

    float widthButton = (width*5/7) / COUNT_OF_WINDOWBUTTONS;
    float step = (width*2/7) / (COUNT_OF_WINDOWBUTTONS+1);

    float currentPosX = step;
    for(int i = 0; i < COUNT_OF_WINDOWBUTTONS; i++){
        QPushButton* windowButton = new QPushButton(this);

        windowButtons.push_back(windowButton);

        windowButton->setGeometry(currentPosX, height-150, widthButton, 50);
        currentPosX += (widthButton+step);

        windowButton->hide();
    }
}

void Window::showWindowButtons(){
    for(QPushButton* currButton : windowButtons){
        currButton->show();
    }
}

void Window::hideWindowButtons(){
    for(QPushButton* currButton : windowButtons){
        currButton->hide();
    }
}

void Window::goToGameScene(){
    currentScene->hide();
    if(game.objs.size() == 0)
        game.initScene();
    game.show(this);
    currentScene = &game;
    showWindowButtons();
}

void Window::goToMenuScene(){
    currentScene->hide();
    menu.show(this);
    currentScene = &menu;
    hideWindowButtons();
}

Window::~Window() {

}
