#include <QPushButton>
#include "healthScene.h"

void HealthScene::initScene(){
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

void HealthScene::buttonCustomization(){
    int size = objs.size();

    connect(objs[size-7], SIGNAL(clicked(bool)), this, SLOT(goToPlayerScene()));
    connect(objs[size-6], SIGNAL(clicked(bool)), this, SLOT(goToMoneyScene()));
    connect(objs[size-5], SIGNAL(clicked(bool)), this, SLOT(goToHealthScene()));
    connect(objs[size-4], SIGNAL(clicked(bool)), this, SLOT(goToHappinnesScene()));

    //conect(objs[size-3], SIGNAL(clicked(bool)), this, SLOT(goToHealthScene()));
    //...
    //...

    objs[size-5]->setEnabled(false);
}


