#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include "Coin.h"
using namespace std;

class Wallet
{
public:
	/// <summary>
	/// Adds a new coin to the wallet
	/// </summary>
	/// <param name="newCoin"></param>
	void AddCoin(Coin* newCoin);
	/// <summary>
	/// Gets the value of the wallet
	/// </summary>
	/// <returns></returns>
	double GetValue();
	/// <summary>
	/// clean up the wallet
	/// </summary>
	~Wallet();
private:
	vector<Coin*> wallet;
};

