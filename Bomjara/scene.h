#pragma once
#include <QWidget>
#include <QObject>
#include "QMainWindow"
#include "QPushButton"


class Scene : public QObject
{
    Q_OBJECT
public:

    QWidget* centalWidget;
    QVector<QWidget*> objs;
    Scene() {}
    void hide();
    void show(QMainWindow* parentWindow);

    ~Scene() {}

};
