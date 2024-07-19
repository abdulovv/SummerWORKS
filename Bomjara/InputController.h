#pragma once
#include "qwidget.h"
#include "qevent.h"
class InputController : public QWidget
{
	Q_OBJECT

public:
    bool eventFilter(QObject* obj, QEvent* event);

signals:
    void keyPressed(int key);
};

