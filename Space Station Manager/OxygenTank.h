#pragma once
#include<iostream>

using namespace std;

class OxygenTank
{
private:
	int id;
public:
	int oxygenLevel;
	OxygenTank* next;
	
	OxygenTank(int id,int oxygenLevel) {
		this->id = id;
		this->oxygenLevel = oxygenLevel;
	}

	int GetOxygenLevel() {

	}

	void Display() {
		cout << "Oxygen level : " << oxygenLevel << endl;
	}

	bool operator<(const OxygenTank& rhd) {
		return (this->oxygenLevel < rhd.oxygenLevel);
	}

	int GetId() {
		return id;
	}

};

