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
	
}
