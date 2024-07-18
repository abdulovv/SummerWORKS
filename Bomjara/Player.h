#pragma once
#include <QMainWindow>
//#include "qapplication.h"


class Player
{
private:
	

public:
	QString name;
	int age, level;
	float score, rubbles, dollars,
		health, hunger, hapiness;
	QPixmap profilePhoto;


	Player() {
		name = "Unnamed"; age = 18; level = 0;
		score = 0; rubbles = 0; dollars = 0;
		health = 100; hunger = 100; hapiness = 100;
	}
	
	void saveToFile(QString fileName = "playerData.ini");
	void loadFromFile(QString fileName = "playerData.ini");

};

