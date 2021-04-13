// RecursionPE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;


//iterative
int myFunc(int numb) {
    /*if (numb % 2 == 0) {
        return (numb / 2) * 7;
    }
    else
        return ((numb / 2) * 7) + 3;*/

    return (numb / 2) * 7 + (numb % 2)*3;

}

//recursive (WORKING CORRECTLY
int fac(int numb) {
    if (numb <= 1) {
        return 3;
    }
    if (numb % 2 == 1) {
        return 3 + fac(numb - 1);
    }
    if (numb % 2 == 0) {
        return 4 + fac(numb - 1);
    }
    }
    


//make your own method use modulus to calculate
//WORKING CORRECTLY
int iterative(int numb) {
    int start = 0;
    for (int i = 1; i <= numb; i++) {
        if (i % 2 == 1) {
            start += 3;
        }
        if (i % 2 == 0) {
            start += 4;
        }
    }
    return start;
}
void calculateTimer(int size) {
    clock_t t1;
    clock_t t2;
    clock_t t3;
    t1 = clock();


    cout << "performance at " << size <<" seats" << endl;
    cout << fac(size) << endl;
    t1 = clock() - t1;
    double time1 = ((double)t1) / CLOCKS_PER_SEC * 100000;

    t2 = clock();
    cout << iterative(size) << endl;
    t2 = clock() - t2;
    double time2 = ((double)t2) / CLOCKS_PER_SEC * 100000;

    t3 = clock();
    cout << myFunc(size) << endl;
    t3 = clock() - t3;
    double time3 = ((double)t3) / CLOCKS_PER_SEC * 100000;
    cout << "Recursive: " << time1 << " ticks  " << "Iterative: " << time2 << " ticks  " << "Formula:" << time3 << " ticks." << endl;
}
int main()
{
    calculateTimer(1000000);
    calculateTimer(100000);
    calculateTimer(10000);
    calculateTimer(1000);
}