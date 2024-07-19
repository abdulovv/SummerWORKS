#include <QPushButton>
#include "casinoScene.h"

void CasinoScene::initScene(){
    QPixmap money = QPixmap(":/CasinoBack.png");
    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(money);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    addPlayerValuesHUD();

    addMainButtons(static_cast<SceneManager*>(sceneManager)->getIndexOfScene(this));

}

void CasinoScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void CasinoScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}

