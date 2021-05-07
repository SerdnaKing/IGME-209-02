#include "Wallet.h"

void Wallet::AddCoin(Coin* newCoin)
{
	// TODO DSA1
	// add the coin to the wallet
	//wallet is a vector, push each coin to the back of the wallet
	wallet.push_back(newCoin);
}

double Wallet::GetValue()
{
	// TODO DSA1
	// sum the total of all the coins
	double total = 0.0;
	for (int i = 0; i < wallet.size(); i++) {
		total += wallet[i]->getValue();
	}
	return total;
}

Wallet::~Wallet()
{
	// TODO DSA1
	//I am unsure how to clear the wallet
	//something to the effect of
	//delete wallet;
	//but it only threw errors
	//implementing wallet.clear() as a solution for now
	wallet.clear();

	//loop through and delete each part of wallet.
	for (int i = 0; i < wallet.size(); i++) {
		delete wallet.at(i);
	}
	
}
