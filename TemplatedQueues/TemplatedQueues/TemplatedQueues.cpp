// TemplatedQueues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TemplatedQueue.h"

using namespace std;

int main()
{
    TemplatedQueue<int> newList;
    newList.Print();
    newList.Push(4);
    newList.Push(3);
    newList.Print();
    newList.Pop();
    newList.Print();
    newList.GetSize();
    cout << "Popping a number" << endl;
    newList.Pop();
    cout << "Is the queue empty?(1 = yes, 0 = no)" << newList.IsEmpty() << endl;

    TemplatedQueue<int> intList(newList);
    intList.Print();
    //copy assignment operator
    TemplatedQueue<int> anotherList = intList;
    anotherList.Print();
    //intList = newList;

    TemplatedQueue<string> newString;
    cout << "Adding a chicken" << endl;
    newString.Push("Chicken MAshed Potato");
    newString.Print();

    TemplatedQueue<string> stringList(newString);
    stringList.Print();
    //copy assignment operator
    TemplatedQueue<string> anotherStringList = stringList;
    anotherList.Print();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
