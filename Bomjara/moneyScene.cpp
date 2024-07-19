#include <QPushButton>
#include "moneyScene.h"

void MoneyScene::initScene(){
    QPixmap money = QPixmap(":/MoneyBack.png");

    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(money);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    addMainButtons(static_cast<SceneManager*>(sceneManager)->getIndexOfScene(this));

}

void MoneyScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void MoneyScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}

