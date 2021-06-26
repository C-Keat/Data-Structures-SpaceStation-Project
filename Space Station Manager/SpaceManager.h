#pragma once
#include<iostream>

using namespace std;

template<class T>


class SpaceManager
{
private:
	T* first;

public:
	SpaceManager(void);
	~SpaceManager(void);
	T* GetFirst();
	bool IsEmpty()const;
	void Insert(T* newAstro);
	void Display()const;
	T* Find(int id)const;
	T* Delete();
	T* Delete(int id);

	friend class Astronaut;

};
template<class T>
SpaceManager<T>::SpaceManager() {
	first = 0;
}
template<class T>
SpaceManager<T>::~SpaceManager(void) {
	cout << "Delete Space manager" << endl;
	while (!IsEmpty()) {
		cout << "Delete Space Manager" << endl;
		delete Delete();
	}
}
template<class T>
bool SpaceManager<T>::IsEmpty()const {
	return (first == 0);
}
template<class T>
void SpaceManager<T>::Insert(T* newWorker) {
	newWorker->next = first;
	first = newWorker;
}

template<class T>
void SpaceManager<T>::Display()const {
	T* current = first;
	while (current != 0) {
		current->Display();
		current = current->next;
	}
}

template<class T>
T* SpaceManager<T>::Find(const int id)const {
	T* current = first;
	while (current->id != id) {
		if (current->next == 0)
			return 0;
		else
			current = current->next;
	}
	return current;
}

template<class T>
T* SpaceManager<T>::Delete() {
	T* temp = first;
	first = first->next;
	return temp;
}

template<class T>
T* SpaceManager<T>::Delete(int id) {
	T* current = first;
	T* previous = first;
	while (current->id != id) {
		if (current->next == 0)
			return 0;
		else {
			previous = current;
			current = current->next;
		}
	}
	if (current == first)
		first = first->next;
	else
		previous->next = current->next;
	return current;
}

template<class T>
T* SpaceManager<T>::GetFirst() {

	return first;

}