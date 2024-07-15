#include "startscreen.h"
#include "qapplication.h"

StartScreen::StartScreen(QWidget *parent)
    : QMainWindow(parent){
    this->showFullScreen();

    QScreen* screen = QGuiApplication::primaryScreen();

    int height = screen->geometry().height();
    int width = screen->geometry().width();

    screenResolution = QPair<int, int>(width, height);

    QLabel *backgroundImage = new QLabel(this);

    QPixmap bomj = QPixmap("D:\\GITHUB\\SummerWORKS\\Images\\bomj.png");

    backgroundImage->setPixmap(bomj);
    backgroundImage->setScaledContents(true);
    this->setCentralWidget(backgroundImage);

    startButton = new QPushButton("START GAME",this->centralWidget());
    lvlButton = new QPushButton("DIFFICULTY LEVEL", this->centralWidget());;
    exitButton = new QPushButton("EXIT", this->centralWidget());;

    startButton->setGeometry(width/2.0-100, height/2.0-160, 200, 60);
    lvlButton->setGeometry(width/2.0-100, height/2.0-80, 200, 60);
    exitButton->setGeometry(width/2.0-100, height/2.0, 200, 60);

    startButton->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200);"
                               "border: none; color: black;}");

    lvlButton->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200);"
                             "border: none; color: black;}");

    exitButton->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 200);"
                              "border: none; color: black;}");

    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

StartScreen::~StartScreen() {
    delete startButton;
    delete lvlButton;
    delete exitButton;
}
