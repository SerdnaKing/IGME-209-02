#include "Wallet.h"

void Wallet::AddCoin(Coin* newCoin)
{
	//wallet is a vector, push each coin to the back of the wallet
	wallet.push_back(newCoin);
}

double Wallet::GetValue()
{
	// sum the total of all the coins
	double total = 0.0;
	//iterate through each coin and get the value, add to a total
	for (int i = 0; i < wallet.size(); i++) {
		total += wallet[i]->getValue();
	}
	return total;
}

Wallet::~Wallet()
{
	//loop through and delete each part of wallet.
	for (int i = 0; i < wallet.size(); i++) {
		delete wallet.at(i);
	}
	
}
