#include "propertyScene.h"

void PropertyScene::initScene(){

    backgroundImage = new QLabel(parentWidget);
    QPixmap tempTexture(":/MoneyBack.png");
    backgroundImage->setPixmap(tempTexture);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    update();


    QPushButton* exitButton = new QPushButton("return to menu", parentWidget);
    objs.push_back(exitButton);

    connect(objs[objs.indexOf(exitButton)], SIGNAL(pressed()), sceneManager, SLOT(goToMenuScene()));


    addMainButtons(static_cast<SceneManager*>(sceneManager)->getIndexOfScene(this));
    //buttonCustomization();
}


void PropertyScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void PropertyScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}




void PropertyScene::update() {
    
}
