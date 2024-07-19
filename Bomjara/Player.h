#pragma once

#include <QPixmap>

class Player{
private:

public:
	QString name;
    int age, level;

    float score, rubbles, dollars, sleep,
        health, hunger, hapiness;

    QPixmap profilePhoto;

	Player() {
		name = "Unnamed"; age = 18; level = 0;
		score = 0; rubbles = 0; dollars = 0;
		health = 10; hunger = 75; hapiness = 100; sleep = 40;
	}
	
	void saveToFile(QString fileName = "playerData.ini");
	void loadFromFile(QString fileName = "playerData.ini");
};

