#pragma once
#include"Room.h"
#include"Astronaut.h"
#include"Pilot.h"

using namespace std;

template<class T>


class Tree
{

public:
	T* foundRoom;
	T* root;

public:
	Tree();
	T* SelectRoom(int key);
	void DisplayInOrder(T* localRoot);
	void TreeInsert(int roomLevel, int roomNum, int roomOxygen, int spaces);
	void DisplaySelecetedRoom();
	void AssignCrew(Astronaut* astro);
	void DisplayRoomsCrew();


};

template<class T>
Tree<T>::Tree() {
	root = 0;
	foundRoom = 0;
}

template<class T>
T* Tree<T>::SelectRoom(int key) {

	foundRoom = root;
	while (foundRoom->key != key) {
		//cout << "While entered";
		if (key < foundRoom->key)
			
			foundRoom = foundRoom->leftChild;
		else
			foundRoom = foundRoom->rightChild;
		if (foundRoom == 0)
			cout << "Room not found" << endl;
			return 0;
	}
	cout << " Found room key " << foundRoom->key << endl;
	return foundRoom;
}
template<class T>
void Tree<T>::DisplaySelecetedRoom() {

	
	foundRoom->Display();

}


template<class T>
void Tree<T>::AssignCrew(Astronaut* astro) {

	foundRoom->spaMan->Insert(astro);
}

template<class T>
void Tree<T>::DisplayRoomsCrew() {
	foundRoom->spaMan->Display();
}

template<class T>
void Tree<T>::DisplayInOrder(T* localRoot) {
	if (localRoot != 0) {
		DisplayInOrder(localRoot->leftChild);
		localRoot->Display();
		DisplayInOrder(localRoot->rightChild);
	}
}

template<class T>
void Tree<T>::TreeInsert(int roomLevel, int roomNum,int roomOxygen, int spaces) {
	
	T* newNode = new T(roomLevel, roomNum, roomOxygen, spaces);

	if (root == 0) {
		root = newNode;
	}
	else {

		T* current;
		current = root;
		T* parent;
		while (true)
		{
			parent = current;
			if (newNode->LessThan(newNode, current)) {
				//if (data < current->data) {
				current = current->leftChild;
				if (current == 0) {
					parent->leftChild = newNode;
					return;
				}
			}
			else {
				current = current->rightChild;
				if (current == 0) {
					parent->rightChild = newNode;
					return;
				}
			}
		}
	}

}
