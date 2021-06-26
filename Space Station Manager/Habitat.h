#pragma once
#include "Room.h"
class Habitat :	public Room<Habitat>
{

public:
	int habitatSpaces;

public:
	~Habitat() {

	}
	Habitat(int id, int level, float oxygenLevel, int habitatSpaces) :Room(id, level, oxygenLevel) {

		this->habitatSpaces = habitatSpaces;

	}

	void Display() {

		Room::Display();

		cout << "Number of Pilot Spaces : " << habitatSpaces << endl << endl << endl;



	}



};

