
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

#include "Accountable.h"
#include "CurrencyType.h"

using namespace std;

class Currency: Accountable {
protected:
	struct MonetaryValue {
		int main;
		int subunit;
	};

	MonetaryValue value;

	const int base;
	const string name;
	const string subunitName;

	void normalize(const int &, int &, int &);

public:
	const CurrencyType type;

	MonetaryValue getValue();

	// Constructor and Deconstructor
	Currency(CurrencyType, int, string, string);
	virtual ~Currency();

	// Copy assignment constructor
	Currency& operator= (const Currency&);

	// Operator Overloads
	Currency& operator+= (const Currency &);
	Currency& operator-= (const Currency &);
};

Currency operator+ (Currency, const Currency&);


#endif