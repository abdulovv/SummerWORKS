#include <QPushButton>
#include "moneyScene.h"

void MoneyScene::initScene(){
    QPixmap money = QPixmap(":/Money.jpg");

    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(money);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, screenSize.width(), screenSize.height());
    objs.push_back(backgroundImage);

    //...
    //...
    //last:
    addMainButtons(objs);
    buttonCustomization();
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

void MoneyScene::buttonCustomization(){
    const int COUNT_OF_MAINBUTTONS = 5;
    int size = objs.size();

    connect(objs[size-5], SIGNAL(clicked(bool)), this, SLOT(goToPlayerScene()));
    //conect(objs[size-3], SIGNAL(clicked(bool)), this, SLOT(goToHealthScene()));
    //...
    //...

    for(int i = 1; i <= COUNT_OF_MAINBUTTONS; i++)
        objs[size-i]->setEnabled((i == 4 ? false : true));

}


