#include <QPushButton>
#include "businessScene.h"

void BusinessScene::initScene(){
    QPixmap money = QPixmap(":/HealthBack.jpg");
    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(money);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, screenSize.width(), screenSize.height());
    objs.push_back(backgroundImage);

    //...
    //...
    //last:
    addMainButtons();
    buttonCustomization();
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

void BusinessScene::buttonCustomization(){
    int size = objs.size();

    connect(objs[size-7], SIGNAL(clicked(bool)), this, SLOT(goToPlayerScene()));
    connect(objs[size-6], SIGNAL(clicked(bool)), this, SLOT(goToMoneyScene()));
    connect(objs[size-5], SIGNAL(clicked(bool)), this, SLOT(goToHealthScene()));
    connect(objs[size-4], SIGNAL(clicked(bool)), this, SLOT(goToHappinnesScene()));
    connect(objs[size-3], SIGNAL(clicked(bool)), this, SLOT(goToBusinessScene()));
    connect(objs[size-2], SIGNAL(clicked(bool)), this, SLOT(goToCasinoScene()));
    connect(objs[size-1], SIGNAL(clicked(bool)), this, SLOT(goToPropertyScene()));

    objs[size-3]->setEnabled(false);
}


