#include <QPushButton>
#include "businessScene.h"

void BusinessScene::initScene(){
    QPixmap money = QPixmap(":/BusinessBack.png");
    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(money);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    addMainButtons(static_cast<SceneManager*>(sceneManager)->getIndexOfScene(this));

}

void BusinessScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void BusinessScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}

