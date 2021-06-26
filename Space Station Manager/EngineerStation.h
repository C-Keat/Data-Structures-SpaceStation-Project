#pragma once
#include "Room.h"
class EngineerStation :	public Room<EngineerStation>
{
public:
	int mechanicSpaces;

public:
	~EngineerStation() {

	}
	EngineerStation(int id, int level, float oxygenLevel, int mechanicSpaces):Room(id, level, oxygenLevel) {

		this->mechanicSpaces = mechanicSpaces;

	}

	void Display() {

		Room::Display();

		cout << "Number of Pilot Spaces : " << mechanicSpaces << endl << endl << endl;



	}



};

