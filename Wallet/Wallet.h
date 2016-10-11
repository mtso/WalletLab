
#ifndef WALLET_H
#define WALLET_H

#include <iostream>

#include "USDCurrency.h"
#include "GBPCurrency.h"

using namespace std;

const int MAX_WALLET_SIZE = AUD + 1;

class Wallet
{
private:
	Currency *currency[MAX_WALLET_SIZE];
	
public:
	/**
	 * The wallet's constructor allocates memory for the array of Currency pointers.
	 */
	Wallet();
	
	/**
	 * Wallet's destructor deletes each object that the array of pointers point to.
	 */
	~Wallet();
	
	/** 
	 * Checks if the wallet currently contains money of a currency type.
	 * @returns boolean
	 */
	bool contains(CurrencyType toRemove) const;

	/** 
	 * Adds a currency value into the wallet or creates a new currency object if one does not exist.
	 * @param deposit The Currency object to deposit.
	 */
	bool deposit(const Currency& deposit);

	/**
	 * Removes a currency of a certain type
	 * @param toRemove The CurrencyType to remove
	 */
	bool remove(CurrencyType toRemove);

	/**
	 * Withdraws a currency
	 */
	Currency& withdraw(Currency& withdrawal);

	/*
	bool isEmpty() const;

	/**/

	void printBalanceTo(std::ostream& out);
	
	//friend ostream& operator<< (ostream& outStream, const Wallet& wallet);

	/**/
};

#endif