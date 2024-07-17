#include "gameScene.h"

void GameScene::initScene(QWidget* parent, QSize screenSize){
    parentWidget = parent;
    this->screenSize = screenSize;

    backgroundImage = new QLabel(parentWidget);
    icons = new QLabel[3];

    QPixmap tempTexture(":/gameSceneBack.png");
    backgroundImage->setPixmap(tempTexture);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, screenSize.width(), screenSize.height() - 180);
    objs.push_back(backgroundImage);

    for (int i = 0; i < 3; i++) {
        icons[i].setParent(parentWidget);
        icons[i].setScaledContents(true);
        icons[i].setGeometry(screenSize.width() - 350, 80 + 100 * i, 40, 40);
        objs.push_back(icons + i);
    }
    tempTexture.load(":/Heart.png");
    icons[0].setPixmap(tempTexture);
    tempTexture.load(":/Food.png");
    icons[1].setPixmap(tempTexture);
    tempTexture.load(":/Sleep.png");
    icons[2].setPixmap(tempTexture);

}


void GameScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void GameScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}


