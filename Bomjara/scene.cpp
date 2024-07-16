#include "scene.h"

Scene::Scene() {}
void Scene::hide(){
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->hide();

    }
}
void Scene::show(QMainWindow *parentWindow){
    parentWindow->setCentralWidget(this->centalWidget);
    for(int i = 0; i < objs.size(); i++) {
        objs[i]->show();
    }
}
