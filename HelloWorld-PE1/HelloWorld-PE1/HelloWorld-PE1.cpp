// HelloWorld-PE1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// declare variables that will be used
int seconds;
double area;
int divisionTest;
int main()
{
    seconds = (31 * 24 * 60 * 60);
    area = 3.14 * (6.2 * 6.2); //Math.PI and Math.Pow (all Math. are unavailable)
    divisionTest = 17 / 3; 
    std::cout << "Hello World!\n";
    std::cout << "Seconds in December:" << seconds << "\n" << std::endl;
    std::cout << "Area of a Circle with radius 6.2 returns: " << area << "\n" << std::endl;
    std::cout << "Dividing 17 by 3 returns:  " << divisionTest << " meaning the division truncates!\n" << std::endl;
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
