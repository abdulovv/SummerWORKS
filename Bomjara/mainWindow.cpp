#include "mainWindow.h"
#include "qapplication.h"
#include "menuScene.h"

window::window(QWidget *parent)
    : QMainWindow(parent){

    menu.centalWidget = this->centralWidget();
    menu.initScene();

    menu.show(this);

    this->showMaximized();
}

window::~window() {

}
