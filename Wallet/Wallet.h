
#ifndef WALLET_H
#define WALLET_H

#include <iostream>

#include "USDCurrency.h"
#include "GBPCurrency.h"

using namespace std;

const int MAX_WALLET_SIZE = 5;

class Wallet
{
private:
	Currency *currencies[MAX_WALLET_SIZE];
	int currencyCount = 0;
	
public:
	Wallet();
	~Wallet();

	int getCount() const { return currencyCount; }
	
	// Checks if the wallet currently contains money of a currency type.
	// Returns the index of the currency or the sentinel -1 if the wallet does not contain a currency of the passed-in type
	bool contains(CurrencyType) const;

	void deposit(Currency& deposit);

	/*
	bool remove(CurrencyType);
	Currency withdraw(CurrencyType, int, int);
	bool isEmpty() const;
	void printBalanceTo(ostream&) const;

	/**/
};

#endif