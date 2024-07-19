#include <QPushButton>
#include <QApplication>

#include "mainMenuScene.h"

void MainMenuScene::initScene(){
    QPixmap bomj = QPixmap(":/StartBack.jpg");

    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, screenSize.width(), screenSize.height());

    addMainButtons();
}

void MainMenuScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void MainMenuScene::show(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}

void MainMenuScene::addMainButtons(){
    objs.push_back(new QPushButton("START GAME", parentWidget));
    objs.push_back(new QPushButton("CONTINUE GAME", parentWidget));
    objs.push_back(new  QPushButton("EXIT", parentWidget));

    objs.push_back(backgroundImage);

    const int COUNT_OF_BUTTONS = 3;

    for(int i = 0; i < COUNT_OF_BUTTONS; i++){
        objs[i]->setGeometry(screenSize.width() / 2.0 - 100, screenSize.height() / 2.0 - 150 + 80 * i, 200, 40);
        objs[i]->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200); border: none; color: black;}");
    }

    connect(objs[0], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
    connect(objs[1], SIGNAL(clicked(bool)), this, SLOT(goToGameScene()));
    connect((QPushButton*)objs[2], &QPushButton::clicked, qApp, &QApplication::quit);
}

void MainMenuScene::buttonCustomization(){
    //empty
}

