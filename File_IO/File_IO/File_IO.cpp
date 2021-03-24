// File_IO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //use ofstream to write a few things to a file

    ofstream outFile;

    //create and name the text document
    outFile.open("data.txt");

    //check to make sure it is open before you write to the document
    // if open, add your text then close before exiting the if statement
    if (outFile.is_open()) {
        outFile << "Example output\n";
        outFile << "Another line\n";
        outFile.close();
    }
    
    //use ifstream object to read the file back in
    ifstream inFile;
    string line;

    //open the named file if it exists (we know it does so there
    //shouldn't be any errors
    inFile.open("data.txt", ios::binary);

    //seek & get the length
    inFile.seekg(0, ios::end);
    int length = (int)inFile.tellg();

    //seek back to the beginning
    inFile.seekg(0, ios::beg);
    if (inFile.is_open()) {

        //make an array to hold the file
        char* fileContents = new char[length + 1];

        //read file and set null pointer
        inFile.read(fileContents, length);
        fileContents[length] = 0;

        //print the files data into the console window
        cout << fileContents << endl;
        //close the file    
        inFile.close();
    }

}


