#include <QFile>
#include "Player.h"

void Player::saveToFile(QString fileName){
	QFile file(fileName);

    if(file.isOpen()){
		file.write(reinterpret_cast<char*>(this));
	}
}

void Player::loadFromFile(QString fileName){
	QFile file(fileName);

    if(file.isOpen()){
		file.read(reinterpret_cast<char*>(this), 1024);
	}
}
