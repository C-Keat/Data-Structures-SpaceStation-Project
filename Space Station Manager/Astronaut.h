#pragma once
#include<iostream>
#include"SpaceManager.h"

using namespace std;

class Astronaut
{

private:
	int id;
protected:
	int rank;

public:
	Astronaut* next;


public:
	~Astronaut() {
	}
	Astronaut(int id, int rank) {

		this->id = id;
		this-> rank = rank;

	}
	virtual void Display() {

		cout << "ID : " << id;

	}


	friend class SpaceManager<Astronaut>;
};

