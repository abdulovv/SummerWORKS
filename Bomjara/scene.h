#pragma once
#include <QWidget>
#include <QObject>
#include "QMainWindow"
#include "QPushButton"

class Scene : public QObject{
    Q_OBJECT
public:

    QWidget* centalWidget;
    QVector<QWidget*> objs;

    Scene() { centalWidget = nullptr; }

    virtual void hide() = 0;
    virtual void show(QMainWindow* parentWindow) = 0;

    ~Scene() {}
};
