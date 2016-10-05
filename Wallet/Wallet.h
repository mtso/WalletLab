
#ifndef WALLET_H
#define WALLET_H

#include <iostream>

//#include "Currency.h"

#include "USDCurrency.h"
#include "GBPCurrency.h"
//#include "JPYCurrency.h"
//#include "CHFCurrency.h"
//#include "AUDCurrency.h"


const int MAX_WALLET_SIZE = 5;

class Wallet
{
private:
	Currency *currencies[MAX_WALLET_SIZE]; // = { nullptr, nullptr, nullptr, nullptr, nullptr };
	int currencyCount = 0;

public:
	Wallet();
	~Wallet();

	int getCount() { return currencyCount; }
	int contains(CurrencyType);
	void add(Currency);
	void deposit(CurrencyType, int, int);
	bool remove(CurrencyType);
	bool withdraw(CurrencyType, int, int);
	bool isEmpty();
	void printBalance(ostream&);
};

#endif