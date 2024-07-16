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
    QVector<QPushButton*> windowButtons;

    MenuScene menu;




    void initWindowButtons();
private slots:
    void showWindowButtons();
    void hideWindowButtons();
    void goToScene(int index);

};
#endif // MAINWINDOW_H
