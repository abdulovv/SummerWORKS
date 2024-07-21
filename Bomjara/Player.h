#pragma once

#include <QPixmap>
#include "qstring.h"

struct StatusDescription {
	QString status;
	int requiredScore;
	StatusDescription() { status = ""; requiredScore = 0; }
	StatusDescription(QString status, int requiredScore) : status(status), requiredScore(requiredScore) {}
};

class Player{
private:
	const StatusDescription moneyStatuses[7] = {
		{"Homeless", 0}, {"Poor", 100}, {"Average", 500}, {"Good", 1000 }, {"Rich", 5000}, {"Businessman", 10000},
		{"Millioner", 100000}
	}, educationStatuses[10] = {
			{"No education", 0}, {"Primary school", 100}, {"Secondary school", 200},
			{"High school", 300}, {"Undergraduate", 400}, {"Postgraduate", 500}, {"Doctorate", 600}
	}, reputationStatuses[10] = {
		{"No name", 0}, {"Average", 100}, {"Respected", 1000}, {"Lord of homeless men", 10000},
			{"Famous", 100000}, {"Celebrity", 1000000}, {"Philanthropist", 100000000}
	};
	
public:
	QString name;
	int age, moneyLevel, reputationLevel, educationLevel;

    float reputationScore, rubbles, dollars,
        health, hunger, hapiness;
	QPixmap profilePhoto;


	QString getMoneyStatus() const { return moneyStatuses[moneyLevel].status; }
	QString getEducationStatus() const { return educationStatuses[educationLevel].status; }
	QString getReputationStatus() const { return reputationStatuses[reputationLevel].status; }


	Player() {
		name = "Unnamed"; age = 18; reputationLevel = 0; educationLevel = 0; moneyLevel = 0;
		reputationScore = 0; rubbles = 0; dollars = 0;
		health = 50; hunger = 50; hapiness = 50; 
	}
	
	void addHealth(float amount) { health += amount; if (health > 100) health = 100;  if (health < 0) health = 0; }
	void addHunger(float amount) { hunger += amount; if (hunger > 100) hunger = 100;  if (hunger < 0) hunger = 0; }
	void addHapiness(float amount) { hapiness += amount; if (hapiness > 100) hapiness = 100; if (hapiness < 0) hapiness = 0; }

	void manageValues() {
		if (hunger < 30)
		{
			health -= (30 - hunger) / 10.0f;
			hapiness -= (30 - hunger) / 10.0f;
		}
		if (hapiness < 30) {
			health -= (30 - hapiness) / 10.0f;
			reputationScore -= (30 - hapiness) / 10.0f;
		}
		while (reputationScore > reputationStatuses[reputationLevel].requiredScore)
			reputationLevel++;
		while (dollars > moneyStatuses[moneyLevel].requiredScore)
			moneyLevel++;

	}

	void saveToFile(QString fileName = "playerData.ini");
	void loadFromFile(QString fileName = "playerData.ini");

};

