#pragma once
#include<iostream>

using namespace std;

template<class T>
class OxygenSorter
{
private:
	T** data;
	int count;
	int size;

public:
	~OxygenSorter() {};
	OxygenSorter(int size) {
		data = new T*[size];
	}
	bool IsEmpty() {
		return (count == size);
	}
	T* PeakMin() {
		return data[count - 1];
	}
	T* Remove() {
		return data[--count];
	}
	int Size() {
		return size;
	}

	void Insert(T* item) {

	if (count == 0) {
			data[count++] = item;
		}
		else {
			int j;
			for (j = (count - 1); j >= 0; j--)
			{
				if (*item < *data[j]) {
					data[j + 1] = data[j];
				}
				else {
					break;
				}
			}
			data[j + 1] = item;
			count++;
		}

	}


};

