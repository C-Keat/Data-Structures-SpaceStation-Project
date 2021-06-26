#pragma once
#include "Astronaut.h"
class Mechanic : public Astronaut
{

public:
	int numberOfTools;

public:
	~Mechanic() {

	}

	Mechanic(int id, int rank, int toolNumber):Astronaut(id,rank) {

		this->numberOfTools = toolNumber;

	}

	void Display() {
	
		Astronaut::Display();
		cout << " Botanist rank : " << rank << "  Tools avalible : " << numberOfTools << endl;


	}


};

