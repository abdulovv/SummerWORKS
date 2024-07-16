#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include "QMainWindow"
#include"QPushButton"
class Scene
{
public:
    QWidget* centalWidget;
    QVector<QWidget*> objs;

    Scene();
    Scene(QWidget* centralWidget){
        this->centalWidget = centralWidget;
    }
    void hide();
    void show(QMainWindow* parentWindow);
};



#endif // SCENE_H
