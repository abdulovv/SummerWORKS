#include <QPushButton>
#include "happinnesScene.h"

void HappinnesScene::initScene(){
    QPixmap money = QPixmap(":/StudyBack.png");
    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(money);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);


    addMainButtons(static_cast<SceneManager*>(sceneManager)->getIndexOfScene(this));

}

void HappinnesScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void HappinnesScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}

