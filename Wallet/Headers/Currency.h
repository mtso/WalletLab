
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

#include "CurrencyType.h"

using namespace std;

struct MonetaryValue {
	int mainunit;
	int subunit;
};

class Currency {
protected:
	MonetaryValue value;
	void normalize();

public:
	// Constructor and Deconstructor
	Currency(CurrencyType, int);
	virtual ~Currency();

	const CurrencyType type;
	const int base;
	
	MonetaryValue getValue() { return value; }
	virtual string getMainunitName();
	virtual string getSubunitName();

	Currency operator- (Currency& right) {
		
	}
};

#endif