#include "playerScene.h"
#include "qevent.h"

void PlayerScene::initScene() {

    backgroundImage = new QLabel(parentWidget);
    bomj = new QLabel(parentWidget);
    QLabel* playerDataFrame = new QLabel(parentWidget),
        * playerData = new QLabel(tr("    Name: ") + player->name + tr(", Age: ") + QString::number(player->age) +
        tr("\nMoney status: ") + player->getMoneyStatus() +
        tr("\nReputation: ") + player->getReputationStatus() +
        tr("\nEducation: ") + player->getEducationStatus(), parentWidget),
        * playerMoney = new QLabel(tr("Dollars: ") + QString::number(player->dollars) + tr("$")
            + tr("\nRubbles: ") + QString::number(player->rubbles) + tr("₽"), parentWidget);
        

    QPixmap tempTexture(":/PlayerBack.png");
    
    backgroundImage->setPixmap(tempTexture);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
    objs.push_back(backgroundImage);

    tempTexture.load(":/Bomj.png");
    bomj->setPixmap(tempTexture);
    bomj->setScaledContents(1);
    bomj->setGeometry(sceneSize.width() * 0.3f, sceneSize.height() * 0.5f,
        sceneSize.width() * 0.35f, sceneSize.height() * 0.45f);
    objs.push_back(bomj);

    playerData->setFont(QFont("Arial", sceneSize.width() / 100.0));
    playerData->setGeometry(sceneSize.width() * 0.03f, sceneSize.height() * 0.05f,
        sceneSize.width() * 0.25f, playerData->font().pointSize() * 6);

    objs.push_back(playerData);

    playerMoney->setFont(QFont("Arial", sceneSize.width() / 100.0));
    playerMoney->setGeometry(playerData->pos().x(), playerData->pos().y() + playerData->height() + sceneSize.height() / 50.0,
        sceneSize.width() * 0.25f, playerData->font().pointSize() * 3);
    objs.push_back(playerMoney);

	tempTexture.fill(Qt::gray);
    playerDataFrame->setPixmap(tempTexture);
	playerDataFrame->setGeometry(playerMoney->pos().x() - sceneSize.height() / 50.0, 
        playerData->pos().y() - sceneSize.height() / 50.0,
		playerData->width() + sceneSize.width() / 50.0, 
        playerData->height() + playerMoney->height() + sceneSize.height() / 50 * 3);
    objs.push_back(playerDataFrame);


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
    if (key == Qt::Key_Up) {
        player->health++;
    }
    if (key == Qt::Key_Down) {
        player->health--;
    }
    update();
}