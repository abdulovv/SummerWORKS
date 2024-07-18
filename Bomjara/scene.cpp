#include "scene.h"

void Scene::clearScene(){
    for (int i = 0; i < objs.size(); i++){
        objs[i]->~QWidget();
    }

    objs.clear();
}

void Scene::addMainButtons(QVector<QWidget *> &objs){
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
}
