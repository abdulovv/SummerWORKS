#include "menuScene.h"
#include "mainWindow.h"
#include "QPushButton"

void menuScene::initScene(){

    QLabel *backgroundImage = new QLabel(centalWidget);
    QPixmap bomj = QPixmap(":/bomj.png");
    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    centalWidget = backgroundImage;

    objs.push_back(new QPushButton("START GAME", centalWidget));
    objs.push_back(new QPushButton("DIFFICULTY LEVEL", centalWidget));
    objs.push_back(new  QPushButton("EXIT", centalWidget));
    int height = QGuiApplication::primaryScreen()->size().height();
    int width = QGuiApplication::primaryScreen()->size().width();

    for(int i = 0; i < 3; i++)
    {
        objs[i]->setGeometry(width/2.0 - 100, height/2.0 - 150 + 80*i, 200, 40);
        objs[i]->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200); border: none; color: black;}");
    }
    connect(objs[0], SIGNAL(clicked(bool)), this, SLOT(hide_first()));


}

void menuScene::hide_first(){
    objs[0]->hide();

}

