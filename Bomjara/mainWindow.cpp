#include "mainWindow.h"
#include "qapplication.h"
#include "menuScene.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent){

    menu.centalWidget = this->centralWidget();
    menu.initScene();

    menu.show(this);

    this->showMaximized();
}

Window::~Window() {

}
