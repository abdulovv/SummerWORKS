#include "gameScene.h"
#include <QPushButton>
#include <QLayout>


void GameScene::addButtons(QVector<QWidget*> objs){
    QVector<QPushButton*> buttons;

    buttons.push_back( new QPushButton("GAME-1", parentWidget));
    buttons.push_back( new QPushButton("GAME-2", parentWidget));
    buttons.push_back( new QPushButton("GAME-3", parentWidget));
    buttons.push_back( new QPushButton("GAME-4", parentWidget));

    int countOfButtons = buttons.size();

    float widthButton = (screenSize.width()*5/7) / (countOfButtons);
    float step = (screenSize.width()*2/7) / (countOfButtons + 1);

    float currentPosX = step;
    for(int i = 0; i < countOfButtons; i++){
        QPushButton* currentButton = buttons[i];
        currentButton->setGeometry(currentPosX, screenSize.height()-120, widthButton, 50);
        currentPosX += (widthButton+step);
        objs.push_back(currentButton);
        currentButton->show();
    }
}

void GameScene::initScene(){

    backgroundImage = new QLabel(parentWidget);
    icons = new QLabel[3];

    QPixmap tempTexture(":/gameSceneBack.png");
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

    objs.push_back(new QPushButton("exit", parentWidget));
    connect(objs[4], SIGNAL(clicked(bool)), this, SLOT(goToMenuScene()));

    addButtons(objs);
}


void GameScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void GameScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}


