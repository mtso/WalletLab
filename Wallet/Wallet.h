
#ifndef WALLET_H
#define WALLET_H

#include <iostream>

#include "USDCurrency.h"
#include "GBPCurrency.h"
#include "JPYCurrency.h"
#include "CHFCurrency.h"
#include "AUDCurrency.h"

using namespace std;

const int MAX_WALLET_SIZE = AUD + 1;

/**
 * Wallet manages an array of 5 currency accounts
 * and provides methods to help the user manipulate the account balances.
 */
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
	void deposit(const Currency& deposit);

	/**
	 * Removes a currency of a certain type
	 * @param toRemove The CurrencyType to remove
	 */
	bool remove(CurrencyType toRemove);

	/**
	 * Removes all currencies from wallet
	 */
	void removeAll();

	/**
	 * Withdraws a currency
	 * @returns the withdrawal amount if successful or 
	 *	a zero-value withdrawal object if there was an insufficient balance
	 */
	Currency& withdraw(Currency& withdrawal);

	/**
	 * Checks if the wallet contains currency objects or not.
	 * @returns true if the whole array points to nullptr
	 */
	bool isEmpty() const;
	
	/**
	 * Ostream operation prints the wallet balances to an ostream.
	 */
	friend ostream& operator<< (ostream& outStream, const Wallet& wallet);
};

#endif