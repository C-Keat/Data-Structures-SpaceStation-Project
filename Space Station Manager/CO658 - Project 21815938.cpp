#include<iostream>
#include"SpaceManager.h"
#include"Astronaut.h"
#include"Botanist.h"
#include"Mechanic.h"
#include"Pilot.h"
#include"Room.h"
#include"CockPit.h"
#include"EngineerStation.h"
#include"Habitat.h"
#include"Tree.h"
#include"OxygenLinkedStack.h"
#include"OxygenSorter.h"
#include <time.h>

int main() {
	srand(time(NULL));
	int inputKey = 2;
	
	cout << "Cockpit Station storage tree created !!" << endl << endl;
	Tree<CockPit>* cockPitTree = new Tree<CockPit>();
	//CockPits being added to a tree.
					//(id,Level,Oxygen Spaces)
	cockPitTree->TreeInsert(1, 4, 34, 3);//key num - 136
	cockPitTree->TreeInsert(4, 2, 34, 3);//key num - 272
	cockPitTree->TreeInsert(1, 2, 65, 4);//key num - 130
	cockPitTree->TreeInsert(5, 5, 99, 5);//key num - 2475
	
	//assigning crew to room 130
	cout << "Crew assigned to - " ;
	cockPitTree->SelectRoom(130);
	cockPitTree->DisplaySelecetedRoom();
	cockPitTree->AssignCrew(new Pilot(1,2));
	cockPitTree->AssignCrew(new Pilot(2, 5));
	cockPitTree->AssignCrew(new Pilot(6, 2));
	cockPitTree->AssignCrew(new Pilot(2, 6));
	cout << "Crew : " << endl;
	cockPitTree->DisplayRoomsCrew();

	cout << endl << endl << endl << endl;

	//new room selected from tree, adding crew members to the room
	cout << "Crew assigned to : " << endl;;
	cockPitTree->SelectRoom(272);
	cockPitTree->DisplaySelecetedRoom();
	cockPitTree->AssignCrew(new Pilot(2, 4));
	cockPitTree->AssignCrew(new Pilot(3, 7));
	cockPitTree->DisplayRoomsCrew();

	cockPitTree->foundRoom->spaMan->Delete(inputKey);

	cout << "Crew member ID:  " << inputKey << " has left selected room" << endl << endl << "New crew in room : " << endl;

	cockPitTree->DisplayRoomsCrew();
	
	cin.get();
	system("CLS");
	
	//using the template tree class, we are able to create another tree with the EngineerStations in it
	cout << "Engineer Station storage tree created" << endl;
	Tree<EngineerStation>* engineerStationTree = new Tree<EngineerStation>();

	//adding Engineering Rooms to the engineering station tree
	engineerStationTree->TreeInsert(6, 3, 89, 5);//1602
	engineerStationTree->TreeInsert(1, 3, 67, 5);//201
	engineerStationTree->TreeInsert(2, 6, 43, 5);//516
	engineerStationTree->TreeInsert(12, 4, 67, 5);//3216
	engineerStationTree->TreeInsert(7, 2, 23, 5);//322
	engineerStationTree->TreeInsert(8, 3, 44, 5);//1057

	engineerStationTree->DisplayInOrder(engineerStationTree->root);

	//selecting room and adding a linked list to it, via the template SpaceManager
	engineerStationTree->SelectRoom(3216);
	cout << "ROOM SELECTED : " << endl;
	engineerStationTree->DisplaySelecetedRoom();
	cout << "Assigning crew to room ......" << endl;

	engineerStationTree->AssignCrew(new Mechanic(2, 10, 3));
	engineerStationTree->AssignCrew(new Mechanic(1, 2, 2));
	engineerStationTree->AssignCrew(new Mechanic(3, 4, 1));
	engineerStationTree->AssignCrew(new Mechanic(4, 7, 4));
	engineerStationTree->AssignCrew(new Mechanic(5, 2, 6));
	engineerStationTree->AssignCrew(new Mechanic(6, 1, 5));
	engineerStationTree->AssignCrew(new Mechanic(7, 6, 3));
	engineerStationTree->AssignCrew(new Mechanic(8, 6, 6));
	engineerStationTree->AssignCrew(new Mechanic(9, 3, 7));
	engineerStationTree->AssignCrew(new Mechanic(10, 2, 9));

	cout << "Selected room crew : " << endl;
	engineerStationTree->DisplayRoomsCrew();

	cin.get();
	system("CLS");

	//creating new habbitat Station Tree, adding rooms into the tree then assigning crew to one of the seleted rooms
	cout << "Habbitat Station storage tree created" << endl;
	Tree<Habitat>* habbitatStationTree = new Tree<Habitat>();

	habbitatStationTree->TreeInsert(6, 3, 89, 5);//1602
	habbitatStationTree->TreeInsert(1, 3, 67, 5);//201
	habbitatStationTree->TreeInsert(2, 6, 43, 5);//516
	habbitatStationTree->TreeInsert(12, 4, 67, 5);//3216
	habbitatStationTree->TreeInsert(7, 2, 23, 5);//322
	habbitatStationTree->TreeInsert(8, 3, 44, 5);//1057

	habbitatStationTree->SelectRoom(3216);
	cout << "room Selected : " << endl;
	habbitatStationTree->DisplaySelecetedRoom();
	
	cout << "Crew being assigned......" << endl;
	habbitatStationTree->AssignCrew(new Botanist(2, 4, 7));
	habbitatStationTree->AssignCrew(new Botanist(3, 7, 9));

	cout << "Crew assigned to selected room : " << endl;
	habbitatStationTree->DisplayRoomsCrew();

	cin.get();
	system("CLS");

	//prepping the oxygen room, 

	OxygenLinkedStack<OxygenTank>* oStack = new OxygenLinkedStack<OxygenTank>();

	cout << "TESTING THE OXYGEN TANKS INTO TOO QUEUE" << endl;

	OxygenSorter<OxygenTank>* tankQ = new OxygenSorter<OxygenTank>(20);

	//randomly generating 20 tanks,  
	for (int i = 0; i < 20; i++)
	{
		tankQ->Insert(new OxygenTank(i,rand() % 101));
	}
	//organising them in priority queue, taking them out of queue and pushing them into a stack, to represent how they would be stored in real life
	while (!tankQ->IsEmpty()) {
		OxygenTank* tempOx = tankQ->Remove();
		oStack->Push(tempOx);
	}
	
	//poping the stack to see what is happing
	while (!oStack->IsEmpty())
	{
		cout << "Oxygen tank ID :" << oStack->Peek()->GetId();
		cout <<" Oxygen level : "<< oStack->Pop()->oxygenLevel << endl;
	}

}