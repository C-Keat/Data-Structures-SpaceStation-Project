#pragma once
#include<iostream>
#include"SpaceManager.h"
#include"Astronaut.h"
#include"Tree.h"

using namespace std;

template<class T>
class Room
{
private:
	int id;
	
protected:
	


public:
	
	int level , key;
	int oxygenLevel;

	T* leftChild;
	T* rightChild;
	SpaceManager<Astronaut>* spaMan;


public:
	~Room() {

	}
	Room(int level, int id, float oxygenLevel) {

		this->id = id;
		this->level = level;
		this->oxygenLevel = oxygenLevel;

		spaMan = new SpaceManager<Astronaut>();

		leftChild = 0;
		rightChild = 0;
		key = this->level * this->id * this->oxygenLevel;

	}

	virtual void Display() {

		cout << "Room Level : " << level << " Room ID : " << id << " Oxygen Levels : " << oxygenLevel << "% " << endl;
		cout << "Room Key : " << key << endl;
	}

	bool LessThan(T* p1, T* p2) {

		int scoreA = Factorial(p1->level) * p1->id;
		int scoreB = Factorial(p2->level) * p2->id;

		if (scoreA < scoreB) {
			return true;
		}
		else {
			return false;
		}

	}

	int Factorial(int n) {
		if (n == 1)
			return 1;
		return Factorial(n - 1) * n;
	}



};

