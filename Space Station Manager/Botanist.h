#pragma once
#include "Astronaut.h"
class Botanist : public Astronaut
{
public:
	int numberOfPlants;

	~Botanist() {

	}

	Botanist(int id, int rank, int plantNumber):Astronaut(id,rank) {

		numberOfPlants = plantNumber;

	}

	void Display() {

		Astronaut::Display();
		cout << " Botanist rank : " << rank << "  Plants avalible : " << numberOfPlants << endl;

	}




};

