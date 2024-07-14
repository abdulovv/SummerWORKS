#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QMainWindow>

class StartScreen : public QMainWindow
{
    Q_OBJECT

public:
    StartScreen(QWidget *parent = nullptr);
    ~StartScreen();
};
#endif // STARTSCREEN_H
