#include <QPushButton>
#include "healthScene.h"

void HealthScene::initScene(){
    QPixmap money = QPixmap(":/HealthBack.png");
    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(money);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    addPlayerValuesHUD();

    addMainButtons(static_cast<SceneManager*>(sceneManager)->getIndexOfScene(this));

}

void HealthScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void HealthScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}
