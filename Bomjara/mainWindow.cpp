#include "mainWindow.h"
#include "qapplication.h"
#include "0-MenuScene.cpp"

window::window(QWidget *parent)
    : QMainWindow(parent){

    scenes = QVector<Scene>(3);
    scenes[0].centalWidget = this->centralWidget();
    initMenuScene(&scenes[0]);

    scenes[0].show(this);

    this->showMaximized();
}

window::~window() {

}
