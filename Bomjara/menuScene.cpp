#include "menuScene.h"
#include "mainWindow.h"
#include "QPushButton"

void MenuScene::initScene(){

    QLabel *backgroundImage = new QLabel(centalWidget);
    QPixmap bomj = QPixmap(":/bomj.png");
    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    //centalWidget = backgroundImage;
    backgroundImage->setGeometry(0, 0,
                               QGuiApplication::primaryScreen()->size().width(),
                               QGuiApplication::primaryScreen()->size().height() - 50);

    objs.push_back(new QPushButton("START GAME", centalWidget));
    objs.push_back(new QPushButton("CONTINUE", centalWidget));
    objs.push_back(new  QPushButton("EXIT", centalWidget));
    objs.push_back(backgroundImage);
    int height = QGuiApplication::primaryScreen()->size().height();
    int width = QGuiApplication::primaryScreen()->size().width();

    const int COUNT_OF_BUTTONS = 3;

    for(int i = 0; i < COUNT_OF_BUTTONS; i++){
        objs[i]->setGeometry(width/2.0 - 100, height/2.0 - 150 + 80*i, 200, 40);
        objs[i]->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200); border: none; color: black;}");
    }


}



void MenuScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void MenuScene::show(QMainWindow *parentWindow){
    //parentWindow->setCentralWidget(centalWidget);
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}



