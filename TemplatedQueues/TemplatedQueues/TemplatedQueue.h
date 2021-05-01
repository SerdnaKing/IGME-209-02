#pragma once
#include <iostream>
using namespace std;
//with templates, everything goes in the header
template <class T>
class TemplatedQueue
{
public:
	//data variables
	T* queue;
	//T info;
	//keeps track of the size of the queue, useful for
	//when you're making a larger queue
	//methods
	int size; 
	int queueSize;
	TemplatedQueue();
	TemplatedQueue(TemplatedQueue<T>& other);
	TemplatedQueue<T>& operator= (const TemplatedQueue<T>& other);
	void Push(T info);
	void Pop();
	void Print();
	int GetSize();
	bool IsEmpty();
	//~MyMethod();
	~TemplatedQueue();

	//template <typename T> T GetMax(T a, T b);
};
//MyClass<T> is telling the program what type the class is
template<class T>
TemplatedQueue<T>::TemplatedQueue() {
	queue = new T[5];
	size = 0;
	queueSize = 5;
}

//template copy;
template<class T>
TemplatedQueue<T>::TemplatedQueue(TemplatedQueue<T>&other) {
	size = other.size;
	queueSize = other.queueSize;
	queue = new T[queueSize];
	for (int i = 0; i < queueSize; i++) {
		queue[i] = other.queue[i];
	}
}
template <class T>
TemplatedQueue<T>& TemplatedQueue<T>::operator= (const TemplatedQueue<T>&other) {
	if (this != &other) {
		size = other.size;
		queueSize = other.queueSize;
		queue = new T[queueSize];
		for (int i = 0; i < queueSize; i++) {
			queue[i] = other.queue[i];
		}
	}
	return *this;
}
////copy constructor ???
//template<class T>
//vp

template <class T>
void TemplatedQueue<T>::Push(T info) {
	if (size == queueSize) {
		//make a temporary queue with double the size, 
		T* tempQueue = new T[queueSize * 2];
		//copy over queue data,
		for (int i = 0; i < queueSize; i++) {
			tempQueue[i] = queue[i];
		}
		//std::copy()
		//delete original
		delete[] queue;
		//then set temp = queue, 
		queue = tempQueue;
		queueSize *= 2;
	}
	queue[size] = info;
	size += 1;
}

template <class T>
void TemplatedQueue<T>::Pop() {
	//T.default()
	for (int i = 1; i < size; i++) {
		queue[i - 1] = queue[i];
	}
	size -= 1;
}
template <class T>
void TemplatedQueue<T>::Print() {
	for (int i = 0; i < size; i++) {
		cout << queue[i] << endl;
	}
	if (size == 0) {
		cout << "Nothing but us chickens" << endl;
	}
}
template <class T>
int TemplatedQueue<T>::GetSize() {
	return size;
}
template <class T>
bool TemplatedQueue<T>::IsEmpty() {
	return size == 0;
}
template <class T>
TemplatedQueue<T>::~TemplatedQueue() {
	delete[] queue;
}

