// TemplatedQueues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TemplatedQueue.h"

using namespace std;

int main()
{
    TemplatedQueue<int> newList;
    cout << "Making sure printing nothing won't break the world..." << endl;
    newList.Print();
    cout << "If you are reading this that means nothing exploded.. hooray" << endl;
    cout << "Pushing the number 4." << endl;
    newList.Push(4);
    cout << "Pushing the number 3" << endl;
    newList.Push(3);
    cout << "Printing the current data locally" << endl;
    newList.Print();
    cout << "Popping a number... Long live the king" << endl;
    newList.Pop();
    cout << "Printing the current data locally..." << endl;
    newList.Print();
    cout << "Retrieving the number of entries..." << endl;
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
    newString.Push("Chicken Mashed Potato");
    cout << "Printing a chicken" << endl;
    newString.Print();
    cout << "Adding 6 flavors of awesome" << endl;
    newString.Push("I'm awesome");
    newString.Push("You're Awesome");
    newString.Push("That guy over there is awesome");
    newString.Push("Keanu Reeves is awesome");
    newString.Push("My family is awesome");
    newString.Push("I'm gonna do awesome");
    cout << "Printing the list... nothing should break here either" << endl;
    newString.Print();
    cout << "Reading this means nothing broke again, huzzah!" << endl;
    cout << "Popping first entrty... I am no longer awesome" << endl;
    newString.Pop();
    cout << "Printing to check if there's still chicken mixed with my awesome flavors.." << endl;
    newString.Print();
    cout << "I am no longer plagued by chicken! That's awesome!" << endl;
    cout << "Is the queue empty? (1 = yes, 0 = no)" << newList.IsEmpty() << endl;
    TemplatedQueue<string> stringList(newString);
    stringList.Print();
    //copy assignment operator
    TemplatedQueue<string> anotherStringList = stringList;
    anotherStringList.Print();


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
