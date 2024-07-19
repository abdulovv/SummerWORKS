#include "playerScene.h"

void PlayerScene::initScene(){

    backgroundImage = new QLabel(parentWidget);
    icons = new QLabel[3]; horizontalBars = new QLabel[3];
    horizontalBarsFrames = new QLabel[3];

    QPixmap tempTexture(":/PlayerBack.png");
    //tempTexture.fill(QColor(155, 0, 0));
    
    backgroundImage->setPixmap(tempTexture);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, screenSize.width(), screenSize.height());
    objs.push_back(backgroundImage);

    tempTexture.load(":/Heart.png");
    icons[0].setPixmap(tempTexture);
    tempTexture.load(":/Food.png");
    icons[1].setPixmap(tempTexture);
    tempTexture.load(":/Sleep.png");
    icons[2].setPixmap(tempTexture);
    tempTexture.load(":/HealthBar.png");
    horizontalBars[0].setPixmap(tempTexture);
    tempTexture.load(":/HungryBar.png");
    horizontalBars[1].setPixmap(tempTexture);
    tempTexture.load(":/SleepBar.png");
    horizontalBars[2].setPixmap(tempTexture);
    tempTexture.load(":/HealthBarFrame.png");
    horizontalBarsFrames[0].setPixmap(tempTexture);
    tempTexture.load(":/HungryBarFrame.png");
    horizontalBarsFrames[1].setPixmap(tempTexture);
    tempTexture.load(":/SleepBarFrame.png");
    horizontalBarsFrames[2].setPixmap(tempTexture);

    for (int i = 0; i < 3; i++) {
        icons[i].setParent(parentWidget);
        horizontalBars[i].setParent(parentWidget);
        horizontalBarsFrames[i].setParent(parentWidget);

        icons[i].setScaledContents(true);
        horizontalBars[i].setScaledContents(true);
        horizontalBarsFrames[i].setScaledContents(true);

        icons[i].setGeometry(screenSize.width() - 350, 80 + 100 * i, 40, 40);
        horizontalBars[i].setGeometry(icons[i].geometry().x() + 50, icons[i].geometry().y(), 200, 40);
        horizontalBarsFrames[i].setGeometry(horizontalBars[i].geometry().x() - 5, 
            horizontalBars[i].geometry().y() - 5, 210, 50);

        objs.push_back(icons + i);
        objs.push_back(horizontalBars + i);
        objs.push_back(horizontalBarsFrames + i);
    }

    update();


    QPushButton* exitButton = new QPushButton("return to menu", parentWidget);
    objs.push_back(exitButton);

    connect(objs[objs.indexOf(exitButton)], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));

    //last:

    addMainButtons();
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
    int size = objs.size();

    connect(objs[size-7], SIGNAL(clicked(bool)), this, SLOT(goToPlayerScene()));
    connect(objs[size-6], SIGNAL(clicked(bool)), this, SLOT(goToMoneyScene()));
    connect(objs[size-5], SIGNAL(clicked(bool)), this, SLOT(goToHealthScene()));
    connect(objs[size-4], SIGNAL(clicked(bool)), this, SLOT(goToHappinnesScene()));
    connect(objs[size-3], SIGNAL(clicked(bool)), this, SLOT(goToBusinessScene()));
    connect(objs[size-2], SIGNAL(clicked(bool)), this, SLOT(goToCasinoScene()));
    connect(objs[size-1], SIGNAL(clicked(bool)), this, SLOT(goToPropertyScene()));

    objs[size-7]->setEnabled(false);
}


void PlayerScene::update() {
    horizontalBars[0].setFixedWidth(player->health * 2);
    horizontalBars[1].setFixedWidth(player->hunger * 2);
    horizontalBars[2].setFixedWidth(player->sleep * 2);
}
