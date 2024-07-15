#include "startscreen.h"
#include "qapplication.h"

StartScreen::StartScreen(QWidget *parent)
    : QMainWindow(parent){

    QLabel *backgroundImage = new QLabel(this);
    qDebug()<<QApplication::applicationDirPath();
    QPixmap bomj = QPixmap(":/bomj.png");
    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    this->setCentralWidget(backgroundImage);

    startButton = new QPushButton("START GAME",this->centralWidget());
    lvlButton = new QPushButton("DIFFICULTY LEVEL", this->centralWidget());;
    exitButton = new QPushButton("EXIT", this->centralWidget());

    this->showMaximized();

    startButton->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200);"
                               "border: none; color: black;}");

    lvlButton->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200);"
                             "border: none; color: black;}");

    exitButton->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200);"
                              "border: none; color: black;}");

    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(game()));
    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);

}

void StartScreen::resizeEvent(QResizeEvent *event){
    moveInterface();
}
void StartScreen::moveInterface(){

    int height = StartScreen::size().height();
    int width = StartScreen::size().width();
    screenResolution = QPair<int, int>(width, height);
    startButton->setGeometry(width/2.0-100, height/2.0-160, 200, 60);
    lvlButton->setGeometry(width/2.0-100, height/2.0-80, 200, 60);
    exitButton->setGeometry(width/2.0-100, height/2.0, 200, 60);

}

void StartScreen::game(){

}

StartScreen::~StartScreen() {
    delete startButton;
    delete lvlButton;
    delete exitButton;
}
