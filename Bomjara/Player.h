#pragma once

#include <QPixmap>
#include "qstring.h"

class Player{
private:
	const QString moneyStatuses[7] = {"Homeless", "Poor", "Average", "Good", "Rich", "Business man", "Millioner"},
		educationStatuses[10] = { "No education", "Primary school", "Secondary school",
		"High school", "Undergraduate", "Postgraduate", "Doctorate" },
		reputationStatuses[10] = { "No name", "Average", "Respected", "Lord of homeless men",
		"Famous", "Celebrity", "Philanthropist" };
public:
	QString name;
	int age, moneyLevel, reputationLevel, educationLevel;

    float reputationScore, rubbles, dollars,
        health, hunger, hapiness;
	QPixmap profilePhoto;


	QString getMoneyStatus() const { return moneyStatuses[moneyLevel]; }
	QString getEducationStatus() const { return educationStatuses[educationLevel]; }
	QString getReputationStatus() const { return reputationStatuses[reputationLevel]; }


	Player() {
		name = "Unnamed"; age = 18; reputationLevel = 0; educationLevel = 0; moneyLevel = 0;
		reputationScore = 0; rubbles = 0; dollars = 0;
		health = 50; hunger = 50; hapiness = 50; 
	}
	
	void saveToFile(QString fileName = "playerData.ini");
	void loadFromFile(QString fileName = "playerData.ini");

};

