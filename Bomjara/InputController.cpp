#include "InputController.h"

bool InputController::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        emit keyPressed(key->key());
        return true;
    }
    else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}
