#include <QPushButton>
#include "moneyScene.h"

void MoneyScene::addButtons(QVector<QWidget*> objs){
    QVector<QPushButton*> buttons;

    buttons.push_back( new QPushButton("MY PLAYER", parentWidget));
    buttons.push_back( new QPushButton("MONEY", parentWidget));
    buttons.push_back( new QPushButton("HEALTH", parentWidget));
    buttons.push_back( new QPushButton("HAPPINNES", parentWidget));
    buttons.push_back( new QPushButton("BUSINESS", parentWidget));

    int countOfButtons = buttons.size();

    float widthButton = (screenSize.width()*5/7) / (countOfButtons);
    float step = (screenSize.width()*2/7) / (countOfButtons + 1);

    float currentPosX = step;
    for(int i = 0; i < countOfButtons; i++){
        QPushButton* currentButton = buttons[i];
        currentButton->setGeometry(currentPosX, screenSize.height()-125, widthButton, 50);
        currentPosX += (widthButton+step);
        objs.push_back(currentButton);
        currentButton->show();
    }

    connect(buttons[0], SIGNAL(clicked(bool)), this, SLOT(goToGameScene_1()));

    buttons[0]->setEnabled(true);
    buttons[1]->setEnabled(false);
}

void MoneyScene::initScene(){
    backgroundImage = new QLabel(parentWidget);

    // QPixmap tempTexture(":/gameSceneBack.png");
    // backgroundImage->setPixmap(tempTexture);
    // backgroundImage->setScaledContents(true);
    // backgroundImage->setGeometry(0, 0, screenSize.width(), screenSize.height());
    // objs.push_back(backgroundImage);

    // for (int i = 0; i < 3; i++) {
    //     icons[i].setParent(parentWidget);
    //     icons[i].setScaledContents(true);
    //     icons[i].setGeometry(screenSize.width() - 350, 80 + 100 * i, 40, 40);
    //     objs.push_back(icons + i);
    // }

    // objs.push_back(new QPushButton("exit", parentWidget));
    // connect(objs[4], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));

    addButtons(objs);
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


