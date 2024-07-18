#include "playerScene.h"

void PlayerScene::initScene(){

    backgroundImage = new QLabel(parentWidget);
    icons = new QLabel[3];

    QPixmap tempTexture(":/GameSceneBack.png");
    backgroundImage->setPixmap(tempTexture);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, screenSize.width(), screenSize.height());
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
    icons = nullptr;


    objs.push_back(new QPushButton("return to menu", parentWidget));
    connect(objs[4], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));

    //last:

    addMainButtons(objs);
    buttonCustomization();
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

void PlayerScene::buttonCustomization(){
    const int COUNT_OF_MAINBUTTONS = 5;
    int size = objs.size();

    connect(objs[size-4], SIGNAL(clicked(bool)), this, SLOT(goToMoneyScene()));
    //conect(objs[size-3], SIGNAL(clicked(bool)), this, SLOT(goToHealthScene()));
    //...
    //...

    for(int i = 1; i <= COUNT_OF_MAINBUTTONS; i++)
        objs[size-i]->setEnabled((i == 5 ? false : true));

}


