
#ifndef WALLET_H
#define WALLET_H

#include "Currency.h"

const int MAX_WALLET_SIZE = 5;

class Wallet
{
private:
	Currency currencies[MAX_WALLET_SIZE];
	int currencyCount;

public:
	Wallet();

	int getCount() { return currencyCount; }
	bool isContaining(CurrencyType);
	bool add(CurrencyType, int, int);
	bool remove(CurrencyType, int, int);
	bool isEmpty();
};

#endif