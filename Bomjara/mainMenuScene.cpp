#include <QPushButton>
#include <QApplication>

#include "mainMenuScene.h"

void MainMenuScene::initScene(){
    QPixmap bomj = QPixmap(":/MenuBack.png");

    backgroundImage = new QLabel(parentWidget);
    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    backgroundImage->setGeometry(0, 0, sceneSize.width(), sceneSize.height());
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
    QPushButton* b1 = new QPushButton(parentWidget);
    QPushButton* b2 = new QPushButton(parentWidget);
    QPushButton* b3 = new QPushButton(parentWidget);


    QIcon iconSTART(":/StartGameButtonBefore.png");
    b1->setIcon(iconSTART);
    b1->setIconSize(QSize(200,40));

    QIcon iconCONTINUE(":/ContinueGameButtonBefore.png");
    b2->setIcon(iconCONTINUE);
    b2->setIconSize(QSize(200,40));

    QIcon iconEXIT(":/ExitButtonBefore.png");
    b3->setIcon(iconEXIT);
    b3->setIconSize(QSize(200,40));

    objs.push_back(b1);
    objs.push_back(b2);
    objs.push_back(b3);

    objs.push_back(backgroundImage);

    const int COUNT_OF_BUTTONS = 3;

    for(int i = 0; i < COUNT_OF_BUTTONS; i++){
        objs[i]->setGeometry(sceneSize.width() / 2.0 - 100, sceneSize.height() / 2.0 - 150 + 80 * i, 200, 40);
    }


    connect(objs[0], SIGNAL(pressed()), this, SLOT(goToGameScene()));
    connect(objs[1], SIGNAL(pressed()), this, SLOT(goToGameScene()));
    connect((QPushButton*)objs[2], &QPushButton::clicked, qApp, &QApplication::quit);
}

