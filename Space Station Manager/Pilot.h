#pragma once
#include "Astronaut.h"
class Pilot : public Astronaut
{

public:

	~Pilot() {
	}
	Pilot(int id, int rank):Astronaut(id,rank) {

	}

	void Display() {

		cout << "Pilot ";
		Astronaut::Display();
		cout << " Pilot Rank : " << rank << endl;

	}



};

