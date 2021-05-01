#pragma once
//with templates, everything goes in the header
template <class T>
class TemplatedQueue
{
public:
	//data variables
	T[] queue;
	T info;
	T size; //keeps track of the size of the queue, useful for
	//when you're making a larger queue
	//methods
	TemplatedQueue();
	void Push();
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
	queue[1];
}
template <class T>
void TemplatedQueue<T>::Push() {
	if(/*queue*/)
}
template <class T>
void TemplatedQueue<T>::Pop() {

}
template <class T>
void TemplatedQueue<T>::Print() {

}
template <class T>
int TemplatedQueue<T>::GetSize() {

}
template <class T>
bool TemplatedQueue<T>::IsEmpty() {

}
template <class T>
TemplatedQueue<T>::~TemplatedQueue() {
	delete[] data;
}

