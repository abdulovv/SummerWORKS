#include "mainWindow.h"
#include "businessScene.h"
#include "casinoScene.h"
#include "happinnesscene.h"
#include "healthScene.h"
#include "mainMenuScene.h"
#include "moneyScene.h"
#include "playerScene.h"
#include "propertyScene.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent){

    QPixmap iconTexture(":/Icon.png");
    QIcon icon(iconTexture);
    this->setWindowIcon(icon);
    this->setWindowFlags(Qt::WindowMinimizeButtonHint);

    screenSize = QSize(QGuiApplication::primaryScreen()->size().width(),
                       QGuiApplication::primaryScreen()->size().height());
    player = new Player();

    this->installEventFilter(&inputController);

    sceneManager.scenes.push_back(new MainMenuScene(this, &sceneManager, &inputController, player, screenSize));
    sceneManager.scenes.push_back(new PlayerScene(this, &sceneManager, &inputController, player, screenSize));
    sceneManager.scenes.push_back(new MoneyScene(this, &sceneManager, &inputController, player, screenSize));
    sceneManager.scenes.push_back(new HealthScene(this, &sceneManager, &inputController, player, screenSize));
    sceneManager.scenes.push_back(new HappinnesScene(this, &sceneManager, &inputController, player, screenSize));
    sceneManager.scenes.push_back(new BusinessScene(this, &sceneManager, &inputController, player, screenSize));
    sceneManager.scenes.push_back(new CasinoScene(this, &sceneManager, &inputController, player, screenSize));
    sceneManager.scenes.push_back(new PropertyScene(this, &sceneManager, &inputController, player, screenSize));

    sceneManager.goToScene(0);
    
}

Window::~Window() {
    delete sceneManager.currentScene;
}
