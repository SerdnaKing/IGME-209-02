// File_IO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //use ofstream to write a few things to a file

    ofstream outFile;
    outFile.open("data.txt");

    if (outFile.is_open()) {
        outFile << "Example output\n";
        outFile << "Another line\n";
        outFile.close();
    }
    
    //use ifstream object to read the file back in

}


