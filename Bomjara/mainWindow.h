#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QPixmap>
#include <QLabel>
#include <QPair>
#include <QPushButton>
#include "scene.h"

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);
    ~window();
private:

    QVector<Scene> scenes;

private slots:

};
#endif // MAINWINDOW_H
