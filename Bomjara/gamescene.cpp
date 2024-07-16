#include "gameScene.h"
#include "mainWindow.h"
#include "QPushButton"
#include "qlineedit.h"


void GameScene::initScene(){
    QLabel *backgroundImage = new QLabel(centalWidget);
    QPixmap bomj = QPixmap(":/3219238023.png");
    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    centalWidget = backgroundImage;

    objs.push_back(new QPushButton("GAME", centalWidget));
    objs[0]->setGeometry(500, 500, 100, 100);

    int height = QGuiApplication::primaryScreen()->size().height();
    int width = QGuiApplication::primaryScreen()->size().width();


}


void GameScene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();
    }
}

void GameScene::show(QMainWindow *parentWindow){
    parentWindow->setCentralWidget(this->centalWidget);
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}



