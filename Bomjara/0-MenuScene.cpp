#include "scene.h"
#include "mainWindow.h"
#include "QPushButton"

void initMenuScene(Scene* scene){

    QLabel *backgroundImage = new QLabel(scene->centalWidget);
    QPixmap bomj = QPixmap(":/bomj.png");
    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    scene->centalWidget = backgroundImage;

    scene->objs.push_back(new QPushButton("START GAME", scene->centalWidget));
    scene->objs.push_back(new QPushButton("DIFFICULTY LEVEL", scene->centalWidget));
    scene->objs.push_back(new  QPushButton("EXIT", scene->centalWidget));
    int height = QGuiApplication::primaryScreen()->size().height();
    int width = QGuiApplication::primaryScreen()->size().width();

    for(int i = 0; i < 3; i++)
    {
        scene->objs[i]->setGeometry(width/2.0 - 100, height/2.0 - 150 + 80*i, 200, 40);
        scene->objs[i]->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200); border: none; color: black;}");
    }

    //scene->centalWidget->connect(scene->objs[0], SIGNAL(clicked(bool)), scene->centalWidget, SLOT(scene->hide()));



}

