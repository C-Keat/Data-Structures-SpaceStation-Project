#pragma once
#include "Room.h"
class CockPit : public Room<CockPit>
{

public:
	int pilotSpaces;

public:
	~CockPit() {

	}
	CockPit(int id, int level,float oxygenLevel,int pilotSpaces):Room(id,level,oxygenLevel) {

		this->pilotSpaces = pilotSpaces;

	}

	void Display() {

		Room::Display();

		cout << "Number of Pilot Spaces : " << pilotSpaces << endl << endl << endl;

	}

	

};

