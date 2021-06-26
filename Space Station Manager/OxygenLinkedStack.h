#pragma once
#include"SpaceManager.h"//linked list
#include"OxygenTank.h"

template<class T>
class OxygenLinkedStack
{
private:
	SpaceManager<OxygenTank>* oxygenStack;
	int top;

public:

	OxygenLinkedStack();
	void Push(T* value);
	T* Pop();
	T* Peek();
	bool IsEmpty();

};
template<class T>
OxygenLinkedStack<T>::OxygenLinkedStack() {

	oxygenStack = new SpaceManager<OxygenTank>();
	top = -1;

}
template<class T>
void OxygenLinkedStack<T>::Push(T* value) {

	oxygenStack->Insert(value);


}
template<class T>
T* OxygenLinkedStack<T>::Pop() {

	return oxygenStack->Delete();

}
template<class T>
T* OxygenLinkedStack<T>::Peek() {

	return oxygenStack->GetFirst();

}
template<class T>
bool OxygenLinkedStack<T>::IsEmpty() {
	return oxygenStack->IsEmpty();

}