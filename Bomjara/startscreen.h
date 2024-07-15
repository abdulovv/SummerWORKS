#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QMainWindow>
#include <QScreen>
#include <QPixmap>
#include <QLabel>
#include <QPair>
#include <QPushButton>

class StartScreen : public QMainWindow
{
    Q_OBJECT

public:
    StartScreen(QWidget *parent = nullptr);
    ~StartScreen();
private:
    virtual void resizeEvent(QResizeEvent *event) override;
    void moveInterface();
    QPair<int, int> screenResolution;
    QPushButton* startButton;
    QPushButton* lvlButton;
    QPushButton* exitButton;
private slots:
    void game();
};
#endif // STARTSCREEN_H
