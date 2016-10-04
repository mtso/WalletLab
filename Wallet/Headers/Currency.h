
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
	const CurrencyType type;
	const int base;

	Currency(CurrencyType, int);
	virtual ~Currency();
	
	MonetaryValue getValue();
	string getName();
	string getSubunitName();
};

#endif