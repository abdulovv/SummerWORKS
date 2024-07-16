#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QPixmap>
#include <QLabel>
#include <QPair>
#include <QPushButton>
#include "menuScene.h"

class Window : public QMainWindow{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();
private:
    MenuScene menu;


private slots:

};
#endif // MAINWINDOW_H
