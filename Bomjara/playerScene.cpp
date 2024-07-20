#include "playerScene.h"
#include "qevent.h"

void PlayerScene::initScene(){

    backgroundImage = new QLabel(parentWidget);
    
    

    QPixmap tempTexture(":/PlayerBack.png");
    
    backgroundImage->setPixmap(tempTexture);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    addPlayerValuesHUD();


    connect(inputController, &InputController::keyPressed, this, &PlayerScene::keyPressedSlot);

    QPushButton* exitButton = new QPushButton("return to menu", parentWidget);
    objs.push_back(exitButton);

    connect(objs[objs.indexOf(exitButton)], SIGNAL(pressed()), sceneManager, SLOT(goToMenuScene()));

    addMainButtons(static_cast<SceneManager*>(sceneManager)->getIndexOfScene(this));
    
}


void PlayerScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void PlayerScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}




void PlayerScene::update() {
    int HUDindex = getIndexOfObjectByName(tr("First HUD Icon"));
    if (HUDindex != -1) {
        objs[HUDindex + 1]->setFixedWidth(objs[HUDindex + 2]->geometry().width() * player->health / 100.0f);
        objs[HUDindex + 4]->setFixedWidth(objs[HUDindex + 2]->geometry().width() * player->hunger / 100.0f);
        objs[HUDindex + 7]->setFixedWidth(objs[HUDindex + 2]->geometry().width() * player->hapiness / 100.0f);
    }
}
void PlayerScene::keyPressedSlot(int key)
{
    if (key == Qt::Key_W) {
        player->health++;
    }
    if (key == Qt::Key_S) {
        player->health--;
    }
    update();
}